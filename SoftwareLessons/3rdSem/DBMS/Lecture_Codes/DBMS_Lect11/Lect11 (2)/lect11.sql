
-- *** SQL Programming: Functions/ stored procedure, Conditional Expressions, 
-- Loops, Trigger, *** --



-- Northwind Database is used for the following examples.



-- ** Functions/ stored procedure ** --



-- Functions / stored procedures are SQL statements stored in the DBMS. They include standart sql and sql programming statements.
-- They can be called by applications, triggers, or some other function / stored procedure.



-- * Advantages * --

-- Improves the performance of the application.
-- Functions / stored procedures, once created, are compiled and stored in the database catalog.
-- It is Much faster than compiling SQL statements from stractch.

-- It reduces the traffic between the application and the database server.
-- Send the name of the function / stored procedure and its parameters instead of long SQL statements. 

-- Reusable.
-- Speeds up the application development process.

-- It is very useful in terms of providing security.
-- The database administrator can easily determine which applications will access functions / stored procedures 
-- without dealing with the security levels of the tables.



-- * Disadvantages * --

-- Programming, modifying (version control) and finding bugs are difficult with a function / stored procedures.

-- Since the Database Management System will have to perform different tasks in addition to data storage and listing, 
-- it may cause negative results in terms of memory usage and processing time.

-- Functions / stored procedures can also be done by application software.

-- As the business logic of the application is transferred to the database server, 
-- the dependency between the application and the database increases and it becomes increasingly impossible to code independently 
-- from the database.



-- * Function Example 1 * --

CREATE OR REPLACE FUNCTION inch2cm(numberINCH REAL)
RETURNS REAL
AS
$$ -- Begining of function body
BEGIN
    RETURN 2.54 * numberINCH / 100;
END;
$$ -- Ending of function body
LANGUAGE plpgsql;



-- Function calling

SELECT * FROM inch2cm(10);



-- * Conditional statements * -- (SEE ADDITIONAL DOCUMENT)

-- * Loops * -- (SEE ADDITIONAL DOCUMENT)

-- https://www.postgresql.org/docs/current/plpgsql-control-structures.html



-- * Function Example 2 * --

CREATE OR REPLACE FUNCTION "functionDefine"(message text, subCharacterNumber SMALLINT, repitationNumber integer)
RETURNS TEXT -- SETOF TEXT, SETOF RECORD  (possible to return multiple values)
AS  
$$
DECLARE
    result TEXT; -- Variable definition block
BEGIN
    result := '';
    IF repitationNumber > 0 THEN
        FOR i IN 1 .. repitationNumber LOOP
            result:= result || i || '.' || SUBSTRING(message FROM 1 FOR subCharacterNumber) || E'\r\n';
            -- E'\r\n': enter
        END LOOP;
    END IF;
    RETURN result;
END;
$$
LANGUAGE 'plpgsql' SECURITY DEFINER;


-- SECURITY DEFINER: The function is run with the privileges of the user who created it.

-- SECURITY INVOKER: The function is run with the privileges of the calling user. (default one)


-- Function calling

SELECT "functionDefine"('Database', 4::SMALLINT, 2);





-- * Function Example 3 * --

-- An example of a function showing how to loop through the result set of a SELECT query is shown below.

CREATE OR REPLACE FUNCTION public.registration()
 RETURNS text
 LANGUAGE plpgsql
AS 
$$
DECLARE
    customer customers%ROWTYPE; ---- another version of this: customers."CustomerID"%TYPE 
    results TEXT;
BEGIN
    results := '';
    FOR customer IN SELECT * FROM customers LOOP
        results := results || customer."CustomerID" || E'\t' || customer."CompanyName" || E'\r\n';
    END LOOP;
    RETURN results;
END;
$$


-- Function calling

SELECT  registration();



-- * Function example 4 * --

-- Function example which returns table.

CREATE OR REPLACE FUNCTION searchPersonel(personelNo INT)
RETURNS TABLE(number SMALLINT, personelName VARCHAR(10), Surname VARCHAR(20)) 
LANGUAGE plpgsql
AS 
$$
BEGIN
    RETURN QUERY SELECT "EmployeeID", "FirstName", "LastName" FROM employees
                 WHERE "EmployeeID" = personelNo;
END;
$$


-- Function Calling

SELECT * FROM searchPersonel(1);


-- * Function example 5 * --

-- Below is an example of a function whose output parameter is defined in the argument list.

CREATE OR REPLACE FUNCTION inch2cm(numberInch REAL, OUT numberCM REAL)
AS 
$$
BEGIN
    numberCM := 2.54 * numberINCH;
END;
$$
LANGUAGE "plpgsql";


-- Function calling

SELECT * FROM inch2cm(2);



---------------------------------------------------------------------------------------------------------------------------------------------------------



-- ** Trigger ** --


-- https://www.postgresql.org/docs/current/sql-createtrigger.html

-- These are functions that can be run automatically with INSERT, UPDATE and DELETE operations
--



-- * Advantages * --

-- It is an alternative way to ensure data integrity.
-- (For example; Reducing the amount of stock when the product is sold)

-- It is an alternative way for scheduled tasks.
-- Tasks can be executed automatically before or after INSERT, UPDATE and DELETE operations without waiting.

-- It is very useful for logging changes in tables.


-- * Disadvantages * --

-- It reduces the clearity of the database design.
-- Together with functions / stored procedures, they form another structure behind the visible database structure.

-- They create additional workload; therefore processing delays may increase.
-- Because, they run on every change to the tables and as a result processing delays may increase.



-- * TRIGGER EXAMPLE 1  * --

-- Below is an example of a trigger used to monitor unit price changes of products in the NorthWind database.

CREATE TABLE "public"."monitorProductChanging" (
	"recordNo" serial,
	"productNo" SmallInt NOT NULL,
	"oldUnitPrice" Real NOT NULL,
	"newUnitPrice" Real NOT NULL,
	"updateDate" TIMESTAMP NOT NULL,
	CONSTRAINT "PK" PRIMARY KEY ("recordNo")
);
	
CREATE OR REPLACE FUNCTION "monitorProductChangingTR1"()
RETURNS TRIGGER 
AS
$$
BEGIN
    IF NEW."UnitPrice" <> OLD."UnitPrice" THEN
        INSERT INTO "monitorProductChanging"("productNo", "oldUnitPrice", "newUnitPrice", "updateDate")
        VALUES(OLD."ProductID", OLD."UnitPrice", NEW."UnitPrice", CURRENT_TIMESTAMP::TIMESTAMP);
    END IF;

    RETURN NEW;
END;
$$
LANGUAGE "plpgsql";

CREATE TRIGGER "productUnitPriceChancing"
BEFORE UPDATE ON "products"
FOR EACH ROW
EXECUTE PROCEDURE "monitorProductChangingTR1"();

UPDATE "products"
SET "UnitPrice" = 100
WHERE "ProductID" = 4 

-- * Before expression * -- 
-- Allows modification/control of new data in insert and update process


----TRIGER EXAMPLE 2------------------------ edit records before insert
CREATE OR REPLACE FUNCTION "addRecordTR1"()
RETURNS TRIGGER 
AS
$$
BEGIN
    NEW."CompanyName" = UPPER(NEW."CompanyName"); -- add after converting to uppercase
    NEW."ContactName" = LTRIM(NEW."ContactName"); -- Clear previous and next spaces
    RETURN NEW;
END;
$$
LANGUAGE "plpgsql";


CREATE TRIGGER "recordControl"
BEFORE INSERT ON "customers"  --The before statement allows data to be acted upon before inserting it
FOR EACH ROW
EXECUTE PROCEDURE "addRecordTR1"();

INSERT INTO "customers" ( "CustomerID","CompanyName", "ContactName") 
VALUES ( '45', 'Orka Ltd.', '    Ayşe Yalın     ' );




ALTER TABLE "products"
DISABLE TRIGGER "productUnitPriceChancing";

ALTER TABLE "products"
ENABLE TRIGGER "productUnitPriceChancing";

ALTER TABLE "products"
DISABLE TRIGGER ALL;

ALTER TABLE "products"
ENABLE TRIGGER ALL;


DROP TRIGGER "productUnitPriceChancing" ON "products";

DROP TRIGGER IF EXISTS "productUnitPriceChancing" ON "products";


--------------------------------------------------------------------------------------------------------------------------------
