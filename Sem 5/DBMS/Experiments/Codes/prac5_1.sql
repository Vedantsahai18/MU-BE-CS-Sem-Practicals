#prac5_1

CREATE TABLE EMP(
empno numeric(4),
ename varchar(10),
designation varchar(10),
salary numeric(8,2)
);

ALTER TABLE EMP ALTER COLUMN empno TYPE numeric(6);

ALTER TABLE EMP ADD COLUMN qualification varchar(6);

ALTER TABLE EMP ADD COLUMN qualification varchar(6);

ALTER TABLE EMP ADD COLUMN dob DATE, ADD COLUMN doj DATE;

ALTER TABLE EMP DROP COLUMN doj;

ALTER TABLE EMP DROP COLUMN dob, DROP COLUMN qualification;

TRUNCATE TABLE EMP;

DROP TABLE EMP;

SELECT * FROM EMP;

#prac5_2

CREATE TABLE products1(
product_no integer PRIMARY KEY,
name text,
price numeric
);

SELECT * FROM products1;
DROP TABLE products1;

insert into products1 values (18, 'ffef',21);
CREATE TABLE orders(
order_id integer PRIMARY KEY,
product_no integer REFERENCES products1(product_no),
quantity integer
);

SELECT * FROM orders;
DROP TABLE orders;

ALTER TABLE products1 ADD Constraint pk_pname PRIMARY KEY(product_no);
ALTER TABLE products1 DROP Constraint pk_pname;

ALTER TABLE products1 ADD CONSTRAINT price CHECK(price > 0);
ALTER TABLE products DROP CONSTRAINT price;

ALTER TABLE products1 ALTER COLUMN name SET NOT NULL;
ALTER TABLE products1 ALTER COLUMN name DROP NOT NULL;
