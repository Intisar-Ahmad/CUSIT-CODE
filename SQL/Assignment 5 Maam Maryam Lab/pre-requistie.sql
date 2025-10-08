-- Create database
CREATE DATABASE IF NOT EXISTS Assignment5;
USE Assignment5;


-- Students table
CREATE TABLE students (
    student_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(50),
    math INT,
    cs INT,
    eng INT
);

-- Employees table
CREATE TABLE employees (
    emp_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(50),
    department VARCHAR(30),
    bonus DECIMAL(10,2)
);

-- Products table
CREATE TABLE products (
    product_id INT PRIMARY KEY AUTO_INCREMENT,
    product_name VARCHAR(50)
);

-- Orders table (for products)
CREATE TABLE orders (
    order_id INT PRIMARY KEY AUTO_INCREMENT,
    product_id INT,
    FOREIGN KEY (product_id) REFERENCES products(product_id)
);

-- Customers (Online)
CREATE TABLE online_customers (
    customer_id INT PRIMARY KEY AUTO_INCREMENT,
    customer_name VARCHAR(50)
);

-- Customers (Store)
CREATE TABLE store_customers (
    customer_id INT PRIMARY KEY AUTO_INCREMENT,
    customer_name VARCHAR(50)
);

-- Supplier product tables
CREATE TABLE supplier1_products (
    product_name VARCHAR(50)
);

CREATE TABLE supplier2_products (
    product_name VARCHAR(50)
);


INSERT INTO students (name, math, cs, eng) VALUES
('Sam', 80, 75, 90),
('Sara', 70, 65, 60),
('John', 55, 40, 35),
('Steve', 90, 85, 80),
('Alice', 60, 70, 65),
('Mike', 45, 50, 55),
('Sandra', 85, 80, 88);

INSERT INTO employees (name, department, bonus) VALUES
('Tom', 'IT', NULL),
('Jerry', 'Finance', 500),
('Lucy', 'HR', NULL),
('Mark', 'IT', 1000),
('Anna', 'Sales', 300);

INSERT INTO products (product_name) VALUES
('Laptop'),
('Mouse'),
('Keyboard'),
('Monitor'),
('Tablet');

INSERT INTO orders (product_id) VALUES
(1), (2), (4);

INSERT INTO online_customers (customer_name) VALUES
('David'), ('Eve'), ('Frank'), ('Grace'), ('Helen');

INSERT INTO store_customers (customer_name) VALUES
('Eve'), ('Isaac'), ('Helen'), ('John');

INSERT INTO supplier1_products (product_name) VALUES
('SSD'), ('RAM'), ('CPU');

INSERT INTO supplier2_products (product_name) VALUES
('CPU'), ('GPU'), ('Motherboard');

