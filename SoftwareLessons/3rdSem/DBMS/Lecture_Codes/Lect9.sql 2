

-- *** Basic SQL (SQL DDL Commands; CREATE, ALTER, DROP, ADD, SET, CONSTRAINTS) *** -- 

-- CREATE --
-- it is used to create Object (database, schema, table, view, function etc.).




-- CREATE DATABASE --
-- It is used to create database.

-- For Windows

CREATE DATABASE "ShoppingApp"
ENCODING='UTF-8'
LC_COLLATE='Turkish_Turkey.1254'-- This property cannot be changed later (for search, sorting)
LC_CTYPE='Turkish_Turkey.1254'	-- This property cannot be changed later (accent)
OWNER postgres
TEMPLATE=template0;




-- CREATE SCHEMA --
-- It is used to logically partition the database.
-- It is similiar with the folder structure on hard disks. In this way, the database
-- easier to manage. Multiple people can work on the same project (namespace).
-- security gets easier,for example some schemas can be defined as read-only.
 
CREATE SCHEMA "schema1";




-- CREATE TABLE --
-- It is used to create a table.

-- Data Types
-- In case the appropriate data type is selected;
-- speed increases, resources are used effectively,
-- data is stored consistently (verification), and
-- measures are taken against some attacks.
Data types in PostgreSQL can be accessed from the following page.
-- https://www.postgresql.org/docs/10/static/datatype.html


CREATE TABLE "schema1"."Products" (
    "productNo" SERIAL,
	"ID" CHAR(6) NOT NULL,
	"name" VARCHAR(40) NOT NULL,
	"productionDate" DATE DEFAULT '2019-01-01',
	"unitPrice" MONEY,
	"Amount" SMALLINT DEFAULT 0,
	CONSTRAINT "productsPK" PRIMARY KEY("productNo"),
	CONSTRAINT "productUnique" UNIQUE("ID"),
	CONSTRAINT "productCheck" CHECK("Amount" >= 0)
);




-- DROP TABLE

DROP TABLE "Products";

DROP TABLE "schema1"."Products";


-- DROP SCHEMA

DROP SCHEMA "schema1"




-- DROP DATABASE

DROP DATABASE "ShoppingApp";



 
-- TRUNCATE TABLE
-- It is used to delete all data inside a table.
CREATE TABLE "Product" (
	 "productNo" SERIAL,
	"ID" CHAR(6) NOT NULL,
	"name" VARCHAR(40) NOT NULL,
	"productionDate" DATE DEFAULT '2019-01-01',
	"unitPrice" MONEY,
	"Amount" SMALLINT DEFAULT 0,
	CONSTRAINT "productsPK" PRIMARY KEY("productNo"),
	CONSTRAINT "productUnique" UNIQUE("ID"),
	CONSTRAINT "productCheck" CHECK("Amount" >= 0)
);

INSERT INTO "Product" 
("ID", "name", "unitPrice", "productionDate", "Amount")
VALUES
('el001', 'TV', '13', '2019-10-30', 5);

INSERT INTO "Product" 
("ID", "name", "unitPrice", "productionDate", "Amount")
VALUES
('el002', 'TV', '13', '2019-10-30', 5);

TRUNCATE TABLE "Product";




-- ALTER TABLE
-- It is used to edit the structure of the table.

CREATE TABLE "Product1" (
	 "productNo" SERIAL,
	"ID" CHAR(6) NOT NULL,
	"name" VARCHAR(40) NOT NULL,
	"productionDate" DATE DEFAULT '2019-01-01',
	"unitPrice" MONEY,
	"Amount" SMALLINT DEFAULT 0,
	CONSTRAINT "productsPK" PRIMARY KEY("productNo"),
	CONSTRAINT "productUnique" UNIQUE("ID"),
	CONSTRAINT "productCheck" CHECK("Amount" >= 0)
);

ALTER TABLE "Product1" ADD COLUMN "productionPlace" VARCHAR(30);

ALTER TABLE "Product1" DROP COLUMN "productionPlace";

ALTER TABLE "Product1" ADD "productionPlace" VARCHAR(30);

ALTER TABLE "Product1" ALTER COLUMN "productionPlace" TYPE CHAR(20);




-- Auto increment example - SERIAL usage

CREATE TABLE "Product1" (
	 "productNo" SERIAL,
	"ID" CHAR(6) NOT NULL,
	"name" VARCHAR(40) NOT NULL,
	"productionDate" DATE DEFAULT '2019-01-01',
	"unitPrice" MONEY,
	"Amount" SMALLINT DEFAULT 0,
	CONSTRAINT "productsPK" PRIMARY KEY("productNo"),
	CONSTRAINT "productUnique" UNIQUE("ID"),
	CONSTRAINT "productCheck" CHECK("Amount" >= 0)
);




-- Auto increment example- SEQUENCE USAGE 1-- (insert using commands)


CREATE TABLE "Product4" (
	"productNo" INTEGER,
	"ID" CHAR(6) NOT NULL,
	"name" VARCHAR(40) NOT NULL,
	"productionDate" DATE DEFAULT '2019-01-01',
	"unitPrice" MONEY,
	"Amount" SMALLINT DEFAULT 0,
	CONSTRAINT "productsPK4" PRIMARY KEY("productNo"),
	CONSTRAINT "productUnique4" UNIQUE("ID"),
	CONSTRAINT "productCheck4" CHECK("Amount" >= 0)
);

CREATE SEQUENCE "counter4";

---ALTER SEQUENCE "counter4" OWNED BY "Product4"."productNo";

INSERT INTO "Product4" 
("productNo", "ID","name", "unitPrice", "productionDate", "Amount")
VALUES
(NEXTVAL('"counter4"'),'EL001', 'TV', '13', '2019-10-30', 5);

INSERT INTO "Product4" 
("productNo", "ID","name", "unitPrice", "productionDate", "Amount")
VALUES
(NEXTVAL('"counter4"'),'tv001', 'TV', '13', '2019-10-30', 5);

-- We can get the next value of the SEQUENCE object using NEXTVAL.
-- We can learn the SEQUENCE processing functions from the link below.
-- https://www.postgresql.org/docs/10/static/functions-sequence.html

SELECT NEXTVAL('counter4');

SELECT CURRVAL('counter4');






-- Auto increment example- SEQUENCE USAGE 2

CREATE SEQUENCE "counter3";
CREATE TABLE "Product3" (
	 "productNo" INTEGER DEFAULT NEXTVAL('counter3'),
	"ID" CHAR(6) NOT NULL,
	"name" VARCHAR(40) NOT NULL,
	"productionDate" DATE DEFAULT '2019-01-01',
	"unitPrice" MONEY,
	"Amount" SMALLINT DEFAULT 0,
	CONSTRAINT "productsPK3" PRIMARY KEY("productNo"),
	CONSTRAINT "productUnique3" UNIQUE("ID"),
	CONSTRAINT "productCheck3" CHECK("Amount" >= 0)
);






-- CONSTRAINTS
-- It helps maintain data integrity.




-- NOT NULL --
-- The defined field cannot be empty. Data must be entered.

CREATE TABLE "Product" (
	"productNo" SERIAL,
	"ID" CHAR(6) NOT NULL,
	"name" VARCHAR(40) NOT NULL,
	"productionDate" DATE DEFAULT '2019-01-01',
	"unitPrice" MONEY,
	"Amount" SMALLINT DEFAULT 0,
	CONSTRAINT "productsPK3" PRIMARY KEY("productNo"),
	CONSTRAINT "productUnique3" UNIQUE("ID"),
	CONSTRAINT "productCheck3" CHECK("Amount" >= 0)
);


-- We get an error when no data is entered in the "ID" field.

INSERT INTO "Product" 
("name", "unitPrice", "productionDate", "Amount")
VALUES
('TV', '13', '2019-10-30', 5);

ALTER TABLE "Product" ALTER COLUMN "ID" DROP NOT NULL;

ALTER TABLE "Product" ALTER "ID" SET NOT NULL;



-- DEFAULT --
-- A default value is assigned if no value is entered in the defined field.

CREATE TABLE "Product" (
	"productNo" SERIAL,
	"ID" CHAR(6) NOT NULL,
	"name" VARCHAR(40) NOT NULL,
	"productionDate" DATE DEFAULT '2019-01-01',
	"unitPrice" MONEY,
	"Amount" SMALLINT DEFAULT 0,
	CONSTRAINT "productsPK3" PRIMARY KEY("productNo"),
	CONSTRAINT "productUnique3" UNIQUE("ID"),
	CONSTRAINT "productCheck3" CHECK("Amount" >= 0)
);


INSERT INTO "Product" 
("ID","name", "unitPrice", "Amount")
VALUES
('EL002','TV', '13', 5);

ALTER TABLE "Product" ALTER "productionDate" DROP DEFAULT;

ALTER TABLE "Product" ALTER COLUMN "productionDate" SET DEFAULT '2019-01-01';




-- UNIQUE --
-- If we define an area as UNIQUE constraints, the value for this fields will be singular. 

CREATE TABLE "Product" (
	"productNo" SERIAL,
	"ID" CHAR(6) NOT NULL,
	"name" VARCHAR(40) NOT NULL,
	"productionDate" DATE DEFAULT '2019-01-01',
	"unitPrice" MONEY,
	"Amount" SMALLINT DEFAULT 0,
	CONSTRAINT "productsPK" PRIMARY KEY("productNo"),
	CONSTRAINT "productUnique" UNIQUE("ID"),
	CONSTRAINT "productCheck" CHECK("Amount" >= 0)
);

ALTER TABLE "Product" DROP CONSTRAINT "produstsUnique";

ALTER TABLE "Product" ADD CONSTRAINT "productsUnique" UNIQUE ("ID");



-- Example of UNIQUE with two fields (APPLY--add data in wizard)

CREATE TABLE "Product5" (
	"productNo" SERIAL,
	"ID" CHAR(6) NOT NULL,
	"name" VARCHAR(40) NOT NULL,
	"productionDate" DATE DEFAULT '2019-01-01',
	"unitPrice" MONEY,
	"Amount" SMALLINT DEFAULT 0,
	CONSTRAINT "productsPK1" PRIMARY KEY("productNo"),
	CONSTRAINT "productUnique1" UNIQUE("ID","name"),
	CONSTRAINT "productCheck1" CHECK("Amount" >= 0)
);

ALTER TABLE "Product5" DROP CONSTRAINT "productUnique1";

ALTER TABLE "Product5" ADD CONSTRAINT "productUnique1" UNIQUE ("ID", "name");






-- CHECK --
-- It is used to limit the range of values in the defined field.

CREATE TABLE "Product" (
	"productNo" SERIAL,
	"ID" CHAR(6) NOT NULL,
	"name" VARCHAR(40) NOT NULL,
	"productionDate" DATE DEFAULT '2019-01-01',
	"unitPrice" MONEY,
	"Amount" SMALLINT DEFAULT 0,
	CONSTRAINT "productsPK" PRIMARY KEY("productNo"),
	CONSTRAINT "productUnique" UNIQUE("ID","name"),
	CONSTRAINT "productCheck" CHECK("Amount" >= 0)
);

INSERT INTO "Product" 
("ID","name", "unitPrice", "Amount")
VALUES
('EL002','TV', '13', -2);


ALTER TABLE "Product" DROP CONSTRAINT "productCheck";

ALTER TABLE "Product" ADD CONSTRAINT "productCheck" CHECK ("miktari" >= 0);






--PRIMARY KEY --

CREATE TABLE "Product" (
	"productNo" SERIAL,
	"ID" CHAR(6) NOT NULL,
	"name" VARCHAR(40) NOT NULL,
	"productionDate" DATE DEFAULT '2019-01-01',
	"unitPrice" MONEY,
	"Amount" SMALLINT DEFAULT 0,
	CONSTRAINT "productsPK" PRIMARY KEY("productNo")
);


ALTER TABLE "Product" DROP CONSTRAINT "productsPK";

ALTER TABLE "Product" ADD CONSTRAINT "productsPK" PRIMARY KEY("productNo");



-- Example of a two-field primary key.
CREATE TABLE "Product1" (
	"productNo" SERIAL,
	"ID" CHAR(6) NOT NULL,
	"name" VARCHAR(40) NOT NULL,
	"productionDate" DATE DEFAULT '2019-01-01',
	"unitPrice" MONEY,
	"Amount" SMALLINT DEFAULT 0,
	CONSTRAINT "productsPK1" PRIMARY KEY("productNo","ID")
);

ALTER TABLE "Product1" DROP CONSTRAINT "productsPK1";

ALTER TABLE "Product1" ADD CONSTRAINT "productsPK1" PRIMARY KEY("productNo","ID");




-- FOREIGN KEY --

CREATE TABLE "ProductCategory" (
    "categoryNo" SERIAL,
    "categoryName" VARCHAR(30) NOT NULL,
	CONSTRAINT "ProductCategoryPK" PRIMARY KEY("categoryNo")
);

CREATE TABLE "Product" (
	"productNo" SERIAL,
	"ID" CHAR(6) NOT NULL,
	"name" VARCHAR(40) NOT NULL,
	"productionDate" DATE DEFAULT '2019-01-01',
	"unitPrice" MONEY,
    "categoryNo" INT,
	"Amount" SMALLINT DEFAULT 0,
	CONSTRAINT "productsPK" PRIMARY KEY("productNo"),
	CONSTRAINT "productCheck" CHECK("Amount" >= 0),
	CONSTRAINT "productFK" FOREIGN KEY("categoryNo") REFERENCES "ProductCategory"("categoryNo")	
);


-- This expression is the same as above. When ON DELETE and ON UPDATE are not specified what to do, it defaults to NO ACTION.

CREATE TABLE "Urunler" (
	"urunNo" SERIAL,
	"kodu" CHAR(6) NOT NULL,
	"adi" VARCHAR(40) NOT NULL,
	"urunTipi" INTEGER NOT NULL, 
	"uretimTarihi" DATE DEFAULT '2019-01-01',
	"birimFiyati" MONEY,
	"miktari" SMALLINT DEFAULT '0',
	CONSTRAINT "urunlerPK" PRIMARY KEY("urunNo"),
	CONSTRAINT "urunlerUnique" UNIQUE("kodu"),
	CONSTRAINT "urunlerCheck" CHECK("miktari" >= 0),
	CONSTRAINT "urunlerFK" FOREIGN KEY("urunTipi") REFERENCES "UrunTipleri"("tipNo") ON DELETE NO ACTION ON UPDATE NO ACTION
);


-- There are three behavior patterns: NO ACTION (default), RESTRICT, CASCADE

ALTER TABLE "Urunler" DROP CONSTRAINT "urunlerFK";

ALTER TABLE "Urunler"
ADD CONSTRAINT "urunlerFK" FOREIGN KEY("urunTipi") 
REFERENCES "UrunTipleri"("tipNo")
ON DELETE NO ACTION
ON UPDATE NO ACTION;

ALTER TABLE "Urunler"
ADD CONSTRAINT "urunlerFK" FOREIGN KEY("urunTipi") 
REFERENCES "UrunTipleri"("tipNo")
ON DELETE RESTRICT
ON UPDATE RESTRICT;

ALTER TABLE "Urunler"
ADD CONSTRAINT "urunlerFK" FOREIGN KEY("urunTipi") 
REFERENCES "UrunTipleri"("tipNo")
ON DELETE CASCADE
ON UPDATE CASCADE;

