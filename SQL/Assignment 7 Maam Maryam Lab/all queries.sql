USE assignment_7;
SELECT * FROM employees;

-- Q1. Count employees per department
-- Write a query to display the number of employees in each department.

SELECT department,COUNT(employee_id) AS No_of_employees FROM employees GROUP BY department;

-- Q2. Find average salary per department
-- Display each department’s name along with the average salary of its employees.

SELECT department,AVG(salary) AS Avg_salary FROM employees GROUP BY department;

-- Q3. Departments with more than 2 employees
-- Display department names that have more than 2 employees. (Use HAVING clause)

SELECT department, COUNT(employee_id) AS Total_employees FROM employees GROUP BY department HAVING Total_employees > 2;

-- Q4. Maximum salary per city
-- Write a query to find the maximum salary in each city

SELECT city,MAX(salary) AS max_salary FROM employees GROUP BY city;

-- Q5. Sort employees by hire date (oldest first)
-- Display employee name, hire date, and department, sorted by oldest joining date.

SELECT employee_name,hire_date,department FROM employees ORDER BY hire_date;

-- Q6. Create a simple index on department
-- Write a query to create an index on the department column.

CREATE INDEX idx_department ON employees(department);


-- Q7. Create a composite index on department and salary
-- Create an index named idx_dept_salary on both columns department and salary.

CREATE INDEX idx_dept_salary ON employees(department,salary);









