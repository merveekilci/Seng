

-- *** Role management *** --


-- ** psql  ** --


-- Working in psql

psql -U postgres -h localhost

psql -U postgres


postgres=#

postgres=# \l --lists all databases in the server 
postgres=# \c Northwind --connect the Northwind database
Northwind=# \d+   --list all tables in Northwind database
Northwind=# select "ProductID", "ProductName"  from products;    --query in psql
(press q for quiting)

-- psql quit

postgres=# \q
postgres=#
postgres=# \du --lists roles and users


postgres=# \q
postgres=#



------------------------------------------------------------------------------------------------------------------------

---------------------------- Authorization Procedures-------------------------------------------------------------------

-- Authorization is determining the priviliges of users /roles on objects 

-- The following permissions can be given according to the type of objects (table, view, function).

-- SELECT, INSERT, UPDATE, DELETE, TRUNCATE, REFERENCES, TRIGGER, CREATE, CONNECT, TEMPORARY, EXECUTE, USAGE ...

---------------------------------------------------------------------------------------------------------------------------
-- ** User / Role Actions ** --


-- Set session authorization as postgres role.
-- Thus, we can perform all operations with all the privileges that the postgres role has.

SET SESSION AUTHORIZATION "postgres";



-- search pg_authid, pg_roles, pg_user catalogs.
-- Information about roles is available in these catalogs.


SELECT * FROM "pg_roles";
SELECT * FROM "pg_user";

-----------------------------------------------------------------------------------------------------------------------------

--While we are creating a user/role we can define it with some authorization. Such as:

-- SUPERUSER, CREATEDB, CREATEROLE, CREATEUSER, INHERIT, LOGIN, 
-- REPLICATION, BYPASSRLS, NOSUPERUSER, NOCREATEDB, NOCREATEROLE, 
-- NOCREATEUSER, NOINHERIT, NOLOGIN, NOREPLICATION, NOBYPASSRLS


-- Create a role without any authorization.
-- The role also does not have a password.

CREATE ROLE "rol1";

-- Create role with SUPERUSER privilege.
-- SUPERUSER has the authority to do everything related to objects.

CREATE ROLE "rol2" WITH SUPERUSER;



-- Roles can be edited after they are created.

ALTER ROLE "rol1" WITH SUPERUSER CREATEDB;
ALTER ROLE "rol1" WITH NOSUPERUSER;

ALTER ROLE "rol1" WITH LOGIN;
ALTER ROLE "rol1" WITH NOLOGIN;


-------------------------------------------------------------------------------------------------------------------------
-- Create a user named "user1" with password abc.
-- The abc password is encoded with the MD5 algorithm.

CREATE USER "user1" WITH PASSWORD 'abc';

 
-- CREATE USER expression is almost same with CREATE ROLE expression. 
-- Just diiferences between them is LOGIN settings.
-- The CREATE USER statement creates a role with LOGIN authority by default.
-- CREATE ROLE statement creates role without LOGIN authorization by default.

-- With 8.1, the concept of role was introduced instead of the concept of user and group.
-- A role can be a user, a group, or both.
---------------------------------------------------------------------------------------------------------------------------------
CREATE ROLE "rol3" WITH PASSWORD 'abc' LOGIN;


-- The password is stored by coding.
-- The expiry date of the password is also indicated.

CREATE ROLE "rol4" WITH PASSWORD 'abc' VALID UNTIL '2020-01-01';

--------------------------------------------------------------------------------------------------------------------------------------

-- Delete user/role

DROP USER "rol4";
DROP ROLE "rol3";
--------------------------------------------------------------------------------------------------------------------------------

-- When creating the object, the owner of this object (the role that runs the CREATE command) is also assigned.
-- The object owner or SUPERUSER has all rights over the object.
-- Before deleting a database owner role, we must transfer database ownership to another role.
-- We can do this with ALTER DATABASE.

CREATE ROLE "rol1";
ALTER DATABASE "app1" OWNER TO "rol1";
DROP ROLE "rol1";

-- 16:18:33 Kernel error: ERROR:  role "rol1" cannot be dropped because some objects depend on it
-- DETAIL:  owner of database app1

ALTER DATABASE "app1" OWNER TO "postgres";
DROP ROLE "rol1";



-- Before deleting a database owner role, we must transfer database ownership to another role. We can also do this with REASSIGN.

CREATE ROLE "rol1";
ALTER DATABASE "app1" owner to "rol1";
DROP ROLE "rol1";

-- 16:18:33 Kernel error: ERROR:  role "rol1" cannot be dropped because some objects depend on it
-- DETAIL:  owner of database app1

-- All objects owned by "role1" become new owner "postgres".
REASSIGN OWNED BY "rol1" TO "postgres";
DROP ROLE "rol1";

-----------------------------------------------------------------------------------------------------------------------------------------------

-- We can use a role as a group.
-- Other roles can inherit privileges from this role.

CREATE ROLE "gruprol";

-- Add the privileges of the role named grouprol to the privileges of the role named rol1.
CREATE ROLE "rol1";
GRANT "gruprol" TO "rol1";



--In order to do this, the role named rol1 must have the authority to inherit. (In new versions of Postgresql, INHERIT is granted when creating a role).

ALTER ROLE "rol1" WITH INHERIT;  

CREATE ROLE "rol2" WITH INHERIT;

GRANT "gruprol" TO "rol2";



-- Revoking the privileges (grouprole privileges) given to the role named role1.

REVOKE "gruprol" FROM "rol1";

--------------------------------------------------------------------------------------------------------------
--Following example is related with NorthWin Database

-- Authorization Procedures

-- PUBLIC: All roles/users
-- userName: single user
-- ALL: All priviliges.


-- Allow the role named rol1 to make selections on the customers table.

GRANT SELECT ON "customers" TO "rol1";


-- Allow all roles to add records on the customers table.

GRANT INSERT ON "customers" TO PUBLIC;


-- Grant a user named rol1 all privileges on the customers table.

GRANT ALL ON "customers" TO "rol1";


-- Revoke the update privilege of the role named rol1 on the customers table.

REVOKE UPDATE ON "customers" FROM "rol1";


-- Revoke all privileges of the role named rol1 on the customers table.

REVOKE ALL ON "customers" FROM "rol1";


-- Revoke all privileges of rol1 user for objects in Schema1.

REVOKE ALL ON SCHEMA "Schema1" FROM "rol1";


-- We cannot delete a role that has privileges on an object.

CREATE ROLE "rol1";
GRANT SELECT ON "customers" TO "rol1";
DROP ROLE "rol1"; 

-- 16:12:44 Kernel error: ERROR:  role "rol1" cannot be dropped because some objects depend on it
-- DETAIL:  privileges for table customers

-- Solution: First delete all privileges owned by rol1 (constraints cannot be violated), After delete rol1.

DROP OWNED BY "rol1";
DROP ROLE "rol1";
-----------------------------------------------------------------------------------------------------------------------------------------------

-- ** Example (using Northwind Database) ** --


CREATE ROLE "rol1";

SET SESSION AUTHORIZATION "rol1";

SELECT * FROM "customers"; 

--Kernel error: ERROR:  permission denied for relation customer

-- because rol1 has not any privileges on customer table.


GRANT SELECT ON "customers" TO "rol1"; 

SELECT * FROM "customers";  ---gives error. Because the current user is customer. customer can not give privileges to itself.

-- Set session authorization to "postgres" user to be able to authenticate.

SET SESSION AUTHORIZATION "postgres";

GRANT SELECT ON "customers" TO "rol1";

SET SESSION AUTHORIZATION "rol1";


-- The query works.

SELECT * FROM "customers";



------------------------------------------------------------------------------------------------------

--** Functions and Authorization ** --


CREATE OR REPLACE FUNCTION "ConvertMiletoKM"(valueMile REAL, OUT valueKM REAL)
AS $$
BEGIN
    valueKM = valueMile * 1.6;
END;
$$
LANGUAGE plpgsql;



SET SESSION AUTHORIZATION "rol1";

SELECT * FROM "ConvertMiletoKM"(3);  ----we didnot set any authorization on the functions. Functions are run by default for the PUBLIC group



SET SESSION AUTHORIZATION "postgres";

REVOKE ALL ON FUNCTION "ConvertMiletoKM"(REAL, OUT REAL) FROM "rol1";


-- The following statement works. Functions are run by default for the PUBLIC group. We can not revoke it for a user. But we can revoke it for public usage.

SET SESSION AUTHORIZATION "rol1";
SELECT * FROM "ConvertMiletoKM"(3);



SET SESSION AUTHORIZATION "postgres";

REVOKE ALL ON FUNCTION "ConvertMiletoKM"(REAL, OUT REAL) FROM PUBLIC;

SET SESSION AUTHORIZATION "rol1";


-- The following query will not work.

SELECT * FROM "ConvertMiletoKM"(3);


---------------------------------------------------------------------------------------------------------------------------------


-- ** Encryption ** --


-- User passwords and confidential information should not be stored without encryption.


-- Encode the password "database" with the md5 algorithm.

SELECT MD5('database');






-----------------------------------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------------------------------------------------------------------------

ADDITONAL INFO (SELF-STUDY - we applied same/similar queries in Valentina Studio, you can also apply it in psql )


-- ** psql - Creating user ** --



-- Example

postgres=# CREATE USER testk1 WITH PASSWORD '111111';
CREATE ROLE
postgres=#
postgres=# \du
                                   List of roles
 Role name |                         Attributes                         | Member of
-----------+------------------------------------------------------------+-----------
 postgres  | Superuser, Create role, Create DB, Replication, Bypass RLS | {}
 testk1    |                                                            | {}

postgres=#



-- Example

-- CREATE USER expression is almost same with CREATE ROLE expression. 
-- Just diiferences between them is LOGIN settings.
-- https://www.postgresql.org/docs/9.6/static/sql-createrole.html

postgres=# CREATE ROLE testk2 WITH PASSWORD '111111';
CREATE ROLE
postgres=# \du
                                   List of roles
 Role name |                         Attributes                         | Member of
-----------+------------------------------------------------------------+-----------
 postgres  | Superuser, Create role, Create DB, Replication, Bypass RLS | {}
 testk1    |                                                            | {}
 testk2    | Cannot login                                               | {}

postgres=#



-- Example

postgres=# CREATE ROLE testk3 WITH PASSWORD '111111' LOGIN;
CREATE ROLE
postgres=# \du
                                   List of roles
 Role name |                         Attributes                         | Member of
-----------+------------------------------------------------------------+-----------
 postgres  | Superuser, Create role, Create DB, Replication, Bypass RLS | {}
 testk1    |                                                            | {}
 testk2    | Cannot login                                               | {}
 testk3    |                                                            | {}

postgres=#



-- Example

postgres=# CREATE ROLE testk4 WITH PASSWORD '111111' LOGIN CREATEDB;
CREATE ROLE
postgres=# \du
                                   List of roles
 Role name |                         Attributes                         | Member of
-----------+------------------------------------------------------------+-----------
 postgres  | Superuser, Create role, Create DB, Replication, Bypass RLS | {}
 testk1    |                                                            | {}
 testk2    | Cannot login                                               | {}
 testk3    |                                                            | {}
 testk4    | Create DB                                                  | {}

postgres=#



-- Example

postgres=# ALTER ROLE testk2 WITH LOGIN;
ALTER ROLE
postgres=# \du
                                   List of roles
 Role name |                         Attributes                         | Member of
-----------+------------------------------------------------------------+-----------
 postgres  | Superuser, Create role, Create DB, Replication, Bypass RLS | {}
 testk1    |                                                            | {}
 testk2    |                                                            | {}
 testk3    |                                                            | {}
 testk4    | Create DB                                                  | {}

postgres=#
