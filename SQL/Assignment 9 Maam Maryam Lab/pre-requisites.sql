-- Create database
CREATE DATABASE trigger_demo;
USE trigger_demo;


CREATE TABLE customers (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100),
    balance DECIMAL(10,2) DEFAULT 0
);


CREATE TABLE employees (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100),
    salary DECIMAL(10,2),
    last_modified DATETIME
);


CREATE TABLE salary_history (
    id INT AUTO_INCREMENT PRIMARY KEY,
    employee_id INT,
    old_salary DECIMAL(10,2),
    new_salary DECIMAL(10,2),
    changed_at DATETIME,
    FOREIGN KEY (employee_id) REFERENCES employees(id)
);


CREATE TABLE students (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100)
);


CREATE TABLE products (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100),
    quantity INT
);


-- Customers
INSERT INTO customers (name, balance) VALUES
('Alice', 0.00),
('Bob', 120.50),
('Charlie', 0.00);


-- Employees
INSERT INTO employees (name, salary, last_modified) VALUES
('John Doe', 45000, NOW()),
('Sarah Smith', 52000, NOW()),
('Mark Lee', 61000, NOW());


-- Students
INSERT INTO students (name) VALUES
('john'),
('maria'),
('steve');

-- Products
INSERT INTO products (name, quantity) VALUES
('Keyboard', 10),
('Mouse', 25),
('Monitor', 5);
