
-- *** Advanced SQL(Subqueries, IN, ALL, ANY, UNION, INTERSECT, EXCEPT, Transaction) --

-- ** Subquery Examples ** --

-- The examples given here are from the NorthWind database.
-- It relates to the subschema given with the lect14_2_additional_document.PNG



-- * Using Subquery with WHERE (Returning Single Value) * --

-- If operators such as =, !=, <, > are used in the WHERE statement, the result of subquery must be a single field and the data type must be suitable. 
Otherwise it gives an error.

-- Since a single value is returned from the grouping operation, the grouping function can be used within the subquery.

-- A single value can be guaranteed to be returned from the subquery by using the primary key within the condition in the subquery.

--
SELECT AVG("UnitPrice") FROM "products";

--List ProductID, UnitPrice information of the products whose unit price is lower than the average unit price of all products.
SELECT "ProductID", "UnitPrice" FROM "products"
WHERE "UnitPrice" < (SELECT AVG("UnitPrice") FROM "products");
-----------------------------------------------------------------------------------------------


--SELECT "ProductID" FROM "products" WHERE "ProductName" = 'Y Z Bilgisayar';


--List CustomerID,Company Name, Contact Name who bought 'Y Z Bilgisayar';
SELECT DISTINCT "public"."customers"."CustomerID",
    "public"."customers"."CompanyName",
    "public"."customers"."ContactName"
FROM "orders"
INNER JOIN "customers" ON "orders"."CustomerID" = "customers"."CustomerID"
INNER JOIN "order_details" ON "order_details"."OrderID" = "orders"."OrderID"
WHERE "order_details"."ProductID" =
    (SELECT "ProductID" FROM "products" WHERE "ProductName" = 'Y Z Bilgisayar')



--Alternative way is using 3 inner join instead of 2 inner join (more slowly)
SELECT DISTINCT "public"."customers"."CustomerID",
    "public"."customers"."CompanyName",
    "public"."customers"."ContactName"
FROM "orders"
INNER JOIN "customers" ON "orders"."CustomerID" = "customers"."CustomerID"
INNER JOIN "order_details" ON "order_details"."OrderID" = "orders"."OrderID"
INNER JOIN "products" ON "order_details"."ProductID" = "products"."ProductID"
 WHERE "ProductName" = 'Y Z Bilgisayar';

----------------------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------------------


-- * Using Subquery with WHERE (Returning Multiple Value)  * --

-- if multiple values are returned from the subquery; IN, ANY, and ALL statements must be used.

-- The IN statement is used to investigate whether the queried value is within the set of values returned from the subquery.

--List SuppliedID whose products' unit price is greater than 18
SELECT "SupplierID" FROM "products" WHERE "UnitPrice" > 18

-- List suppliers information whose products' unit price is greater than 18
SELECT * FROM "suppliers"
WHERE "SupplierID" IN
    (SELECT "SupplierID" FROM "products" WHERE "UnitPrice" > 18);

----------------------------------------------------------------------------------------------------------------------
--List customerID, Company name and Contact name of the customers who bought products whose product name start with 'A'.

SELECT "ProductID" FROM "products" WHERE "ProductName" LIKE 'A%';

SELECT DISTINCT "public"."customers"."CustomerID",
    "public"."customers"."CompanyName",
    "public"."customers"."ContactName"
FROM "orders"
INNER JOIN "customers" ON "orders"."CustomerID" = "customers"."CustomerID"
INNER JOIN "order_details" ON "order_details"."OrderID" = "orders"."OrderID"
WHERE "order_details"."ProductID" IN
    (SELECT "ProductID" FROM "products" WHERE "ProductName" LIKE 'A%');
----------------------------------------------------------------------------------------------------------

UPDATE "orders"
SET "ShipCountry" = 'Mexico'
WHERE "CustomerID" IN
(SELECT "CustomerID" FROM "customers" WHERE "Country" = 'Mexico')

----------------------------------------------------------------------------------------
DELETE FROM "products"
WHERE "SupplierID" IN
(SELECT "SupplierID" FROM "suppliers" WHERE "Country" = 'USA');
---------------------------------------------------------------------------------------------

-- * subquery with ANY * --


-- There are three types.
-- = ANY
-- > ANY
-- < ANY

-- = ANY expression is used to investigate whether the queried value is equal to 
-- any of the elements of the set of values returned from the subquery.

-- > ANY expression is used to investigate whether the queried value is bigger than 
-- any of the elements of the set of values returned from the subquery.

-- < ANY expression is used to investigate whether the queried value is smaller than 
-- any of the elements of the set of values returned from the subquery.

--List the product information whose unit price matches any of the unit prices of the products which are supplied by Tokyo Traders
SELECT * FROM  "products"
WHERE "UnitPrice" = ANY
(
    SELECT "UnitPrice"
    FROM "suppliers"
    INNER JOIN "products"
    ON "suppliers"."SupplierID" = "products"."SupplierID"
    WHERE "suppliers"."CompanyName" = 'Tokyo Traders'
);

-----------------------------------------------------------------------
--Alternative way
SELECT * FROM  "products"
WHERE "UnitPrice" IN
(
    SELECT "UnitPrice"
    FROM "suppliers"
    INNER JOIN "products"
    ON "suppliers"."SupplierID" = "products"."SupplierID"
    WHERE "suppliers"."CompanyName" = 'Tokyo Traders'
);

----------------------------------------------------------------------
--List the product information whose unit price is less than any of the unit prices of the products which are supplied by Tokyo Traders
SELECT * FROM  "products"
WHERE "UnitPrice" < ANY
(
    SELECT "UnitPrice"
    FROM "suppliers"
    INNER JOIN "products"
    ON "suppliers"."SupplierID" = "products"."SupplierID"
    WHERE "suppliers"."CompanyName" = 'Tokyo Traders'
);
--------------------------------------------------------------------
--List the product information whose unit price is greater than any of the unit prices of the products which are supplied by Tokyo Traders
SELECT * FROM  "products"
WHERE "UnitPrice" > ANY 
(
    SELECT "UnitPrice" 
    FROM "suppliers"
    INNER JOIN "products" 
    ON "suppliers"."SupplierID" = "products"."SupplierID"
    WHERE "suppliers"."CompanyName" = 'Tokyo Traders'
)

-------------------------------------------------------------------------------------------------------

-- * Subquery with ALL* --


-- There are 2 types.
-- > ALL
-- < ALL

-- > ALL expression is used to investigate whether the queried value is 
-- bigger than all the elements of the set of values returned from the subquery.

-- < ALL expression is used to investigate whether the queried value is 
-- smaller than all the elements of the set of values returned from the subquery..

--List the product information whose unit price is less than all of the unit prices of the products which are supplied by Tokyo Traders
SELECT * FROM  "products"
WHERE "UnitPrice" < ALL
(
    SELECT "UnitPrice"
    FROM "suppliers"
    INNER JOIN "products"
    ON "suppliers"."SupplierID" = "products"."SupplierID"
    WHERE "suppliers"."CompanyName" = 'Tokyo Traders'
);

-----------------------------------------------------
--List the product information whose unit price is greater than all of the unit prices of the products which are supplied by Tokyo Traders
SELECT * FROM  "products"
WHERE "UnitPrice" > ALL 
(
    SELECT "UnitPrice" 
    FROM "suppliers"
    INNER JOIN "products" 
    ON "suppliers"."SupplierID" = "products"."SupplierID"
    WHERE "suppliers"."CompanyName" = 'Tokyo Traders'
)

-------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------

-- * Subquery with HAVING  * --


SELECT AVG("UnitsInStock") FROM "products";

--List the total stock of each supplier whose total stock is less than the average stock of all products.
SELECT "SupplierID", SUM("UnitsInStock") AS "totalNumberinStock"
FROM  "products"
GROUP BY "SupplierID"
HAVING SUM("UnitsInStock") < (SELECT AVG("UnitsInStock") FROM "products");

---------------------------------------------------------------------------------------

SELECT MAX("Quantity") FROM "order_details";

--List the total quantity value of each product whose total quantity value is greater than the max quantity value of the order_details table. 
SELECT "ProductID", SUM("Quantity")
FROM "order_details"
GROUP BY "ProductID"
HAVING SUM("Quantity") > (SELECT MAX("Quantity") FROM "order_details");


-----------------------------------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------------------------------------

-- * Inline subquery * --

-- Inline subqueries must return a single field and a single row. Otherwise it gives an error.

SELECT
    "ProductName",
    "UnitsInStock",
    (SELECT MAX("UnitsInStock") FROM "products") AS "maxValue"
FROM "products";

-----------------------------------------------------------------------------------------------------------------------------------
SELECT
    "SupplierID",
    COUNT("UnitsInStock") AS "total",
    SQRT(SUM(("UnitsInStock" - (SELECT AVG("UnitsInStock") FROM "products")) ^ 2) / COUNT("UnitsInStock"))  AS "standartDeviation"
FROM "products"
GROUP BY "SupplierID"



-----------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------
-- ** UNION ve UNION ALL ** --

-- Return the set union of two tables.

-- The same records are displayed once with the UNION statement.
-- The same records are shown with the UNION ALL statement.

SELECT "CustomerID" FROM "customers"
UNION
SELECT "CustomerID" FROM "orders"
ORDER BY "CustomerID";

-----------------------------------------------------
SELECT "CustomerID" FROM "customers"
UNION ALL
SELECT "CustomerID" FROM "orders"
ORDER BY "CustomerID";

----------------------------------------------------
SELECT "CompanyName", "Country" FROM "customers"
UNION ALL
SELECT "CompanyName", "Country" FROM "suppliers"
ORDER BY 2;

--------------------------------------------------------------------------------------------
----------------------------------------------------------------------------------------

-- ** INTERSECT ** --

-- The set intersection of the two tables is obtained.

SELECT "CompanyName", "Country" FROM "customers"
INTERSECT
SELECT "CompanyName", "Country" FROM "suppliers"
ORDER BY 2;



-----------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------
-- ** EXCEPT ** --

-- It is used to get the difference of one table from another. 

SELECT "CompanyName", "Country" FROM "customers"
EXCEPT
SELECT "CompanyName", "Country" FROM "suppliers"
ORDER BY 2;


-----------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------
-- ** Transaction ** --

-- Transaction is one of the important features of database management systems.
-- Supports features specified by ACID.

-- The term ACID consists of the first letters of the words Atomicity, Consistency, Isolation, and Durability. 
-- Details are described below.

-- Atomicity: All sub-transactions within the scope of the transaction are handled as a whole. 
-- Either all subprocesses run successfully, or if any of them fail, 
-- all of them are ignored and the database is restored to its previous stable state. 

-- Consistency: If any constraint is violated, the database is restored to its previous stable state with a roll back operation.

-- Isolation: Transactions do not affect each other (in case of joint resource use). 
-- The used common resource is locked by the transaction until the transaction is complete.

-- Durability: In case of an error by the system, the incomplete process is definitely completed after the system starts to work.


BEGIN; --start to transaction

INSERT INTO "order_details" ("OrderID", "ProductID", "UnitPrice", "Quantity", "Discount")
VALUES (10248, 11, 20, 2, 0);

-- If there is an error in the above query, it will not proceed.
-- If there is an error in the query below, it will rollback from this point. 
-- In other words, the transactions made in the above query are rolled back.

Update "products" 
SET "UnitsInStock" = "UnitsInStock" - 2
WHERE "ProductID" = 11;

-- If both queries execute without error, execute both and update the state of the database.

COMMIT; --Complete the transaction
----------------------------------------------------------------------------------------------------

--Ahmet will sent 100 TL to Mehmet
BEGIN;
UPDATE account SET balance = balance- 100.00
    WHERE user_name = 'Ahmet';

--SAVEPOINT my_savepoint;

UPDATE account SET balance = balance + 100.00
    WHERE user_name = 'Mehmet';


-- Send money Ayşe instead of Mehmet

ROLLBACK TO my_savepoint;
UPDATE account SET balance = balance + 100.00
WHERE user_name = 'Ayşe';
COMMIT;