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