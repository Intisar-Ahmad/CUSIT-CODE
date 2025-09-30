CREATE DATABASE IF NOT EXISTS db_demo;
USE db_demo;
-- Employees table
CREATE TABLE employees (
 emp_id INT PRIMARY KEY,
 name VARCHAR(50),
 department VARCHAR(30),
 salary DECIMAL(10,2),
 bonus DECIMAL(10,2),
 age INT,
 active TINYINT(1),
 hire_date DATE
);
INSERT INTO employees VALUES
(1,'Aisha','IT',6000.00,300.00,28,1,'2020-03-15'),
(2,'Bilal','HR',4500.00,150.00,35,1,'2019-07-01'),
(3,'Fatima','Sales',5200.00,400.00,30,0,'2021-01-10'),
(4,'Omar','IT',7000.00,500.00,40,1,'2018-11-20'),
(5,'Sara','Finance',4800.00,NULL,27,1,'2022-06-05');
-- Products table
CREATE TABLE products (
 product_id INT PRIMARY KEY,
 name VARCHAR(50),
 category VARCHAR(30),
 price DECIMAL(10,2),
 stock INT
);
INSERT INTO products VALUES
(101,'USB Cable','Accessory',10.00,100),
(102,'Mouse','Accessory',15.00,50),
(103,'Keyboard','Accessory',25.00,30);
-- Orders table
CREATE TABLE orders_table (
 order_id INT PRIMARY KEY,
 customer VARCHAR(50),
 product_id INT,
 qty INT,
 order_date DATE,
 status VARCHAR(20),
 total_amount DECIMAL(10,2)
);
INSERT INTO orders_table VALUES
(1001,'Ali',101,3,'2025-09-20','delivered',NULL),
(1002,'Zain',102,2,'2025-09-21','processing',NULL),
(1003,'Hina',103,1,'2025-09-22','delivered',NULL);
-- Two simple sets for set-operations demos
CREATE TABLE online_customers (customer VARCHAR(50));
CREATE TABLE store_customers (customer VARCHAR(50));
INSERT INTO online_customers VALUES ('Ali'),('Hina'),('Noor'),('Zain');
INSERT INTO store_customers VALUES ('Bilal'),('Noor'),('Aisha'),('Hina');
-- Students table for special examples (LIKE / BETWEEN)
CREATE TABLE students (
 id INT PRIMARY KEY,
 name VARCHAR(50),
 math INT,
 cs INT,
 eng INT
);
INSERT INTO students VALUES
(1,'Amal',78,82,70),
(2,'Bilal',65,72,68),
(3,'Sana',45,55,60),
(4,'Zara',90,88,92),
(5,'Tariq',50,49,53);