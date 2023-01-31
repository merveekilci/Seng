
-- *** Basic SQLCommands (SQL DML Commands; SELECT, JOIN, INSERT, UPDATE, DELETE) *** --



-- *** The following queries use the NorthWind Sample Database. *** --



-- SELECT --
-- The Select Command is used to retrieve (search/list) data from the database.

SELECT * FROM "customers";

SELECT "CompanyName", "ContactName" FROM "customers";



- WHERE --
-- The WHERE command is used to list the records matching the desired condition. (filter to queries)

SELECT * FROM "customers" WHERE "Country" = 'Argentina';

SELECT * FROM "customers" WHERE "Country" != 'Brazil';

SELECT * FROM "customers" WHERE "Country"='Argentina' AND "City" = 'Buenos Aires';

SELECT * FROM "customers" WHERE "Country" = 'Türkiye' OR "Country" = 'Japan';

SELECT * FROM "order_details" WHERE "UnitPrice" = 14;

SELECT * FROM "order_details" WHERE "UnitPrice" < 14;

SELECT * FROM "order_details" WHERE "UnitPrice" <= 14;

SELECT * FROM "order_details" WHERE "UnitPrice" >= 14;

SELECT * FROM "order_details" WHERE "UnitPrice" > 14;



-- DISTINCT --
-- It ensures that the repeated records (rows) in the query result are shown as a single record.

SELECT DISTINCT "City" from "customers";



-- ORDER BY --
-- The "ORDER BY" command is used to sort the records listed as a result of the queries alphabetically or numerically 
-- according to certain fields as ascending or descending.

SELECT * FROM "customers" ORDER BY "ContactName" ASC;

SELECT * FROM "customers" ORDER BY "ContactName" DESC;

SELECT * FROM "customers" ORDER BY "Country" DESC, "ContactName" DESC;

SELECT * FROM "customers" ORDER BY "Country", "ContactName";



-- LIKE --It is used to search for certain patterns from the strings.

SELECT * FROM "customers" WHERE "Country" LIKE '%pa%';

SELECT * FROM "customers" WHERE "Country" LIKE '_razil';

SELECT * FROM "customers" WHERE "City" LIKE 'Sao _aulo';

SELECT * FROM "customers" WHERE "Country" LIKE '%pa_';


-- BETWEEN -- It can be used for numbers, characters, dates.

SELECT * FROM "products" WHERE "UnitPrice" BETWEEN 10 AND 20;

SELECT * FROM "products" WHERE "ProductName" BETWEEN 'C' AND 'M';



-- IN -- if we are filtering for more than one data, we can use IN.

SELECT * FROM "customers" 
WHERE "Country" IN ('Türkiye', 'Kuzey Kıbrıs Türk Cumhuriyeti');

--Alternatively;

SELECT * FROM "customers" 
WHERE "Country"='Türkiye' OR "Country"='Kuzey Kıbrıs Türk Cumhuriyeti';


-- Querying fields with NULL and NOT NULL content.

SELECT * FROM "customers" WHERE "Region" IS NOT NULL;

SELECT * FROM "customers" WHERE "Region" IS NULL;



-- AS --
-- The AS statement gives nicknames to fields/tables.

SELECT "CompanyName" AS "customers" FROM "customers"; 

SELECT "UnitPrice", "UnitPrice" * 1.18 AS "Pricewithtax" FROM "products";

SELECT "OrderID" AS "orderNo",
       "ShipPostalCode" || ',' || "ShipAddress" AS "newAddress"
FROM "orders"
WHERE "OrderDate" BETWEEN '07/04/1996' AND '07/09/1996';
-- || sign shows the joining processes for strings.


 - INNER JOIN --

--Select and list orderno, companyname, contactname and order date of the customers
SELECT 
  "public"."orders"."OrderID",
  "public"."customers"."CompanyName",
  "public"."customers"."ContactName",
  "public"."orders"."OrderDate"
FROM "orders" 
INNER JOIN "customers" ON "orders"."CustomerID" = "customers"."CustomerID" 


--Select and list orderno, companyname, contactname and order date of the customers whose country starts with A
SELECT 
  "public"."orders"."OrderID",
  "public"."customers"."CompanyName",
  "public"."customers"."ContactName",
  "public"."orders"."OrderDate"
FROM "orders" 
INNER JOIN "customers"  ON "orders"."CustomerID" = "customers"."CustomerID"
WHERE "public"."customers"."Country" LIKE 'A%'



---Select and list orderno, companyname and order date of the companies who have an order.
SELECT 
  "orders"."OrderID" AS "orderNo",
  "customers"."CompanyName" AS "company",
  "orders"."OrderDate" AS "date"
FROM "orders"
INNER JOIN "customers" ON "orders"."CustomerID" = "customers"."CustomerID";



--An employee is related with an order. Thus, list the orderid, orderdate,companyname and related employee's first and last name. (wizard)
SELECT 
  "orders"."OrderID",
  "orders"."OrderDate",
  "customers"."CompanyName",
  "employees"."FirstName",
  "employees"."LastName"
FROM "orders"
INNER JOIN "customers" ON "orders"."CustomerID" = "customers"."CustomerID"
INNER JOIN "employees" ON "orders"."EmployeeID" = "employees"."EmployeeID";



-List the orderid and productname information of each orders. (there is not a common field btw orders and products table, thus we will use order order_details)
SELECT
  "orders"."OrderID",
  "products"."ProductName"
FROM "order_details"
INNER JOIN "orders" ON "order_details"."OrderID" = "orders"."OrderID"
INNER JOIN "products" ON "order_details"."ProductID" = "products"."ProductID";




-- LEFT OUTER JOIN --
--Show the all companies name from customer table. if these companies have order, show the order id and order date.
SELECT
   "orders"."OrderID", 
  "customers"."CompanyName", 
  "orders"."OrderDate" 
FROM "customers"
LEFT OUTER JOIN "orders" ON "orders"."CustomerID" = "customers"."CustomerID" ;




--  RIGHT OUTER JOIN --
--Show the name and surname of the all employees. if these employees were related with an order show the related orderid and orderdate.
SELECT
  "orders"."OrderID", 
  "employees"."FirstName", 
  "employees"."LastName", 
  "orders"."OrderDate" 
FROM "orders"
RIGHT OUTER JOIN "employees" ON "orders"."EmployeeID" = "employees"."EmployeeID" ;



-- SELECT ... INTO --
-- It is used to copy data from a table into a new table.
-- The new table must not exist.

SELECT "CompanyName", "ContactName" INTO "MusteriYedek" FROM "customers";




-- INSERT --
-- The INSERT command is used to add a new record to the table.
-- Data integrity constraints are taken into account in insert operations.
-- It is possible to add data to only some columns. No data added columns will appear NULL .

INSERT INTO "customers" 
("CustomerID", "CompanyName", "ContactName","Address", "City", "PostalCode", "Country")
VALUES ('ZZA', 'Zafer', 'Ayşe', 'Serdivan', 'Sakarya', '54400', 'Türkiye');



-- INSERT INTO ... SELECT --
-- Used to copy data from a table into an existing table.

INSERT INTO "MusteriYedek" SELECT "CompanyName", "ContactName" FROM "customers";



-- UPDATE --
-- The UPDATE command changes the record(s) in the table.
-- Data integrity constraints are taken into account in update operations.

UPDATE "customers" SET "ContactName" = 'Mario Pontes', "City" = 'Rio de Janeiro' 
WHERE "CompanyName" = 'Familia Arquibaldo';
--if the WHERE clause is not used, all rows are replaced .--



-- DELETE --
-- The DELETE statement deletes the record or records in the table.
-- Data integrity constraints are taken into account in deletion operations.

DELETE FROM "customers" 
WHERE "CompanyName" = 'LINO-Delicateses' AND "ContactName" = 'Felipe Izquierdo';



--It is possible to delete all records in the table without deleting the table.
--The following command is used to delete all records in the table.

DELETE FROM "customers";


