

-- *** Basic SQL (SQL DDL Commands; INDEX, GENERILAZITION, SINGLE RELATION, SQL DML
-- Commands; VIEW, MULTI-ROW FUNCTIONS, GROUPING) *** -- 


-- INDEX -- for speeding up the searching operations, the index is used. But it must be used effectively. 
--Because unnecessary index usage causes unnecessary resource usage.

CREATE TABLE "Customers" (
	"customerNo" SERIAL NOT NULL,
	"name" CHARACTER VARYING(40),
	"surname" CHARACTER VARYING(40), 
	CONSTRAINT "custonmerNoPK" PRIMARY KEY ("customerNo")
);

CREATE INDEX "customerNameIndex" ON "Customers" ("name");

CREATE INDEX "customerSurnameIndex" ON "Customers" USING btree ("surname");

DROP INDEX "customerNameIndex";



-- Generalization Example --
-- Connection establishment between parent table and child table.It is best place to use "CASCADE"


CREATE SCHEMA "Personel";

CREATE TABLE "Personel"."Personel" ( 
	"personelNo" SERIAL,
	"name" CHARACTER VARYING(40) NOT NULL,
	"surname" CHARACTER VARYING(40) NOT NULL,
	"personelType" CHARACTER(1) NOT NULL,
	CONSTRAINT "personelPK" PRIMARY KEY ("personelNo")
);
	
CREATE TABLE "Personel"."Advisor" ( 
	"personelNo" INT,
	"company" CHARACTER VARYING(40) NOT NULL,
	CONSTRAINT "advisorPK" PRIMARY KEY ("personelNo"),
    CONSTRAINT "AdvisorPersonel" FOREIGN KEY ("personelNo") REFERENCES "Personel"."Personel" ("personelNo")
	ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE "Personel"."SalesRepresentavive" ( 
	"personelNo" INT,
	"region" CHARACTER VARYING(40) NOT NULL,
	CONSTRAINT "SalesRepresentavivePK" PRIMARY KEY ("personelNo"),
    CONSTRAINT "SalesRepresentavivePersonel" FOREIGN KEY ("personelNo") REFERENCES "Personel"."Personel" ("personelNo")
	ON DELETE CASCADE	ON UPDATE CASCADE

);
	



-- Getting data when inheritance is used
SELECT * FROM "Personel"."Personel"
INNER JOIN "Personel"."SalesRepresentavive"
ON "Personel"."Personel"."personelNo" = "Personel"."SalesRepresentavive"."personelNo"

SELECT * FROM "Personel"."Personel"
INNER JOIN "Personel"."Advisor"
ON "Personel"."Personel"."personelNo" = "Personel"."Danisman"."personelNo"


-- Field added to base table to speed up queries
SELECT "name", "surname" FROM "Personel"."Personel"
WHERE "personelTipi"='S';

SELECT "name", "surname" FROM "Personel"."Personel"
WHERE "personelTipi"='D';

SELECT "name", "surname" FROM "Personel"."Personel"
INNER JOIN "Personel"."Advisor"
ON "Personel"."personelNo" = "Advisor"."personelNo"



-- Recursive Join / Single Relation Example --


CREATE TABLE "Personel" (
	"personelNo" SERIAL,
	"name" CHARACTER VARYING(40) NOT NULL,
	"surname" CHARACTER VARYING(40) NOT NULL,
	"admin" INTEGER,
	CONSTRAINT "personelPK" PRIMARY KEY ("personelNo"),
	CONSTRAINT "personelFK" FOREIGN KEY ("admin") REFERENCES "Personel" ("personelNo")
);

INSERT INTO "Personel"
("name", "surname")
VALUES ('Ahmet', 'Şahin');

INSERT INTO "Personel"
("name", "surname")
VALUES ('Ayşe', 'Kartal');

INSERT INTO "Personel"
("name", "surname", "admin")
VALUES ('Mustafa', 'Çelik', '1');

INSERT INTO "Personel"
("name", "surname", "admin")
VALUES ('Fatma', 'Demir', '2');

SELECT "Staff"."name" AS "staffName",
    "Staff"."surname" AS "staffSurname",
	"Admin"."name" AS "adminName",
	"Admin"."surname" AS "adminSurname"
FROM "Personel" AS "Staff"
INNER JOIN "Personel" AS "Admin" ON "Admin"."personelNo" = "Staff"."admin";

SELECT "Staff"."name" AS "staffName",
    "Staff"."surname" AS "staffSurname",
	"Admin"."name" AS "adminName",
	"Admin"."surname" AS "adminSurname"
FROM "Personel" AS "Staff"
LEFT OUTER JOIN "Personel" AS "Admin" ON "Admin"."personelNo" = "Staff"."admin";
-- Staffs which have no admin are also listed.




-- ** View ** --

-- It is the structure that ensures that the information in the rows and fields 
-- selected from one or more tables are displayed like a new table.


-- All rows can be selected from the table(s), or only rows that meet certain criteria can be selected.

-- All fields in the table(s) can be included in the view, or only certain fields can be included in the view.

-- It is used to define a shortcut for the SELECT operation.

-- It is generally preferred in complex selection (SELECT) operations.

-- It is dynamic. Each time the table created with VIEW is accessed, the expressions that created it (view statements) are re-executed.

-- Makes complex queries simple.

-- It is also used for security reasons.
-- For example, if the company staff can see the general information of the customers (name, surname, address, etc.) 
-- but cannot access the credit card information, a view containing only the information we want them to see
-- can be created and we authorize the relevant personnel to this view.

-- The following queries use the NorthWind Sample Database. --

CREATE OR REPLACE VIEW "public"."OrderCustomer" AS
SELECT "orders"."OrderID",
    "orders"."OrderDate",
    "customers"."CompanyName",
    "customers"."ContactName",
    "employees"."FirstName",
    "employees"."LastName"
FROM "orders"
INNER JOIN "employees" ON "orders"."EmployeeID" = "employees"."EmployeeID"
INNER JOIN "customers" ON "orders"."CustomerID" = "customers"."CustomerID";


SELECT * FROM "OrderCustomer"


DROP VIEW "OrderCustomer";



-- ** SQL  Multi-Row Functions -- ** --

-- The following queries use the NorthWind Sample Database. --




-- COUNT -- Number of lines --
-- Returs the number of rows that resulting the query.
-- If applied for only one column, NULL records in that column are not counted.


-- Number of all records in the table
SELECT COUNT(*)
FROM "customers"

SELECT COUNT("Region")
FROM "customers"

SELECT COUNT(*)
FROM "customers"
WHERE "Country" = 'Mexico';


SELECT COUNT("CustomerID") AS "customernumber"
FROM "customers";

SELECT COUNT("CustomerID") AS "customernumberinTurkey"
FROM "customers"
WHERE "Country" = 'Türkiye';




-- LIMIT

SELECT * FROM "products" ORDER BY "ProductID" ASC LIMIT 4

SELECT * FROM "products" ORDER BY "ProductID" DESC LIMIT 5




-- MAX
-- It is used to reach the largest value in the selected column.

SELECT MAX("UnitPrice") FROM "products";

SELECT MAX("UnitPrice") AS "maxValue" FROM "products";




-- MIN
-- It is used to reach the smallest value in the selected column.

SELECT MIN("UnitPrice") FROM "products";

SELECT MIN("UnitPrice") AS "minValue" FROM "products";




-- SUM
-- It is used to reach the sum of the values in the selected column.

SELECT SUM("UnitPrice") FROM "products";

SELECT SUM("UnitPrice") AS "toplam" FROM "products";


-- AVG - Average --

SELECT AVG("UnitPrice") FROM "products";
SELECT SUM("UnitPrice") / COUNT("ProductID") FROM "products";






-- GROUP BY
-- Groups the query result by the specified field(s).
-- The field to be selected must be the grouped field or multi-row functions (COUNT).
-- It is necessary to use the HAVING statement in order to write the condition after the grouping operation.


-- The following query groups products by their suppliers and calculates the number of products 
-- each supplier provides and returns them with supplier information.

SELECT "SupplierID", COUNT(*)
FROM "products"
GROUP BY "SupplierID"


SELECT "SupplierID", SUM("UnitsInStock") AS "countofstock"
FROM "products"
GROUP BY "SupplierID"








-- HAVING
-- It is used for filtering on grouped data.
-- Conditions written with HAVING are made with multi-row functions or over the grouped area.

SELECT "SupplierID", COUNT("SupplierID") AS "NumberofProducts"
FROM "products"
GROUP BY "SupplierID"
HAVING COUNT("SupplierID") > 2;



-- WHERE is not used with multi-row functions.
-- The following two queries are incorrect.

SELECT "SupplierID", COUNT("SupplierID") AS "NumberofProducts"
FROM "products"
WHERE COUNT("SupplierID") > 2;

SELECT "SupplierID", COUNT("SupplierID") AS "NumberofProducts"
FROM "products"
GROUP BY "SupplierID"
WHERE COUNT("SupplierID") > 2;
