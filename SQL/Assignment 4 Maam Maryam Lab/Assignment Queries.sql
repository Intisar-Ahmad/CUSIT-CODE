USE db_demo;

-- Arithmetic Queries

-- Q0. Compute total_compensation (salary + bonus), but show 0 if salary or bonus is NULL
SELECT 
  emp_id,
  name,
  IFNULL(salary, 0) + IFNULL(bonus, 0) AS total_compensation
FROM employees;

-- Q1. For each product, compute total value of stock (price * stock) and order results by highest total value
SELECT 
  product_id,
  name,
  price * stock AS total_value
FROM products
ORDER BY total_value DESC;

-- Q2. Find employees whose monthly salary (salary / 12) is less than 500
SELECT 
  emp_id,
  name,
  salary / 12 AS monthly_salary
FROM employees
WHERE salary / 12 < 500;

-- Q3. Update total_amount in orders (price * qty) using UPDATE ... JOIN ...
SET SQL_SAFE_UPDATES = 0; -- this is optional. if the query doesn't work try this
UPDATE orders_table o
JOIN products p ON o.product_id = p.product_id
SET o.total_amount = p.price * o.qty;

-- Q4. Show remainder when stock is divided by 7 (%) and label as leftover_boxes
SELECT 
  product_id,
  name,
  stock % 7 AS leftover_boxes
FROM products;


-- Logical Queries

-- Q1. Retrieve employees who are active AND in department Finance or HR
SELECT *
FROM employees
WHERE active = 1 
  AND (department = 'Finance' OR department = 'HR');

-- Q2. Get students who passed both math and cs with marks >= 50
SELECT *
FROM students
WHERE math >= 50 AND cs >= 50;

-- Q3. Find orders where status is NOT delivered
SELECT *
FROM orders_table
WHERE NOT status = 'delivered';

-- Q4. Retrieve employees aged >= 30 and (salary > 6000 OR bonus >= 400)
SELECT *
FROM employees
WHERE age >= 30 
  AND (salary > 6000 OR bonus >= 400);

-- Q5. Create column is_high that shows 1 when salary > 6000 XOR bonus >= 400, else 0
SELECT 
  emp_id,
  name,
  salary,
  bonus,
  ( (salary > 6000) XOR (bonus >= 400) ) AS is_high
FROM employees;


-- Comparison Queries

-- Q1. List employees with salary >= 5000 and age <= 35
SELECT *
FROM employees
WHERE salary >= 5000 AND age <= 35;

-- Q2. Show students whose math score is exactly 50
SELECT *
FROM students
WHERE math = 50;

-- Q3. Find employees where department is not equal to IT
SELECT *
FROM employees
WHERE department <> 'IT';

-- Q4. Use NULL-safe operator <=> to find which employees explicitly have bonus as NULL
SELECT *
FROM employees
WHERE bonus <=> NULL;

-- Q5. Find products where price < 20 and stock > 10
SELECT *
FROM products
WHERE price < 20 AND stock > 10;

SET SQL_SAFE_UPDATES = 1;