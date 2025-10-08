-- =========================
-- QUESTIONS AND SOLUTIONS
-- =========================

-- 1. Select students whose names start with S
SELECT * FROM students
WHERE name LIKE 'S%';

-- 2. Find employees where department is IN the list (IT, Finance)
SELECT * FROM employees
WHERE department IN ('IT', 'Finance');

-- 3. Get students with total score (math + cs + eng) BETWEEN 150 and 250
SELECT *, (math + cs + eng) AS total_score
FROM students
WHERE (math + cs + eng) BETWEEN 150 AND 250;

-- 4. Show products that have never been ordered (use LEFT JOIN ... IS NULL)
SELECT p.product_name
FROM products p
LEFT JOIN orders o ON p.product_id = o.product_id
WHERE o.product_id IS NULL;

-- 5. Replace NULL bonus with 0 in the select output (use COALESCE)
SELECT name, department, COALESCE(bonus, 0) AS bonus
FROM employees;


-- 6. Get a single list of unique customers across online and store (UNION)
SELECT customer_name FROM online_customers
UNION
SELECT customer_name FROM store_customers;

-- 7. Get a list of customers from both sources including duplicates (UNION ALL)
SELECT customer_name FROM online_customers
UNION ALL
SELECT customer_name FROM store_customers;

-- 8. Find customers who bought both online and in-store (common customers)
SELECT o.customer_name
FROM online_customers o
INNER JOIN store_customers s
ON o.customer_name = s.customer_name;

-- 9. Find customers who bought online but never in-store (simulate EXCEPT)
SELECT o.customer_name
FROM online_customers o
LEFT JOIN store_customers s
ON o.customer_name = s.customer_name
WHERE s.customer_name IS NULL;

-- 10. Combine product lists from two supplier tables and tag which supplier each row came from
SELECT product_name, 'Supplier1' AS supplier
FROM supplier1_products
UNION ALL
SELECT product_name, 'Supplier2' AS supplier
FROM supplier2_products;
