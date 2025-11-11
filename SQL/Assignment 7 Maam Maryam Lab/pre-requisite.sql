-- Create Database
CREATE DATABASE assignment_7;
USE assignment_7;
-- Create Employees Table
CREATE TABLE Employees (
 employee_id INT PRIMARY KEY,
 employee_name VARCHAR(50),
 department VARCHAR(50),
 job_title VARCHAR(50),
 salary DECIMAL(10,2),
 hire_date DATE,
 city VARCHAR(50),
 manager_id INT
);
-- Insert Sample Data
INSERT INTO Employees VALUES
(1, 'Ali Khan', 'HR', 'HR Manager', 95000, '2020-03-15', 'Lahore', NULL),
(2, 'Sara Ahmed', 'HR', 'HR Assistant', 55000, '2021-06-01', 'Lahore', 1),
(3, 'Bilal Hussain', 'IT', 'Software Engineer', 120000, '2019-02-10', 'Karachi',
7),
(4, 'Ayesha Noor', 'IT', 'System Analyst', 110000, '2020-05-20', 'Karachi', 7),
(5, 'Usman Rafiq', 'Sales', 'Sales Executive', 80000, '2021-07-25',
'Islamabad', 9),
(6, 'Fatima Tariq', 'Sales', 'Sales Manager', 115000, '2018-04-12',
'Islamabad', NULL),
(7, 'Ahmad Iqbal', 'IT', 'IT Manager', 150000, '2017-01-05', 'Karachi', NULL),
(8, 'Hina Javed', 'Finance', 'Accountant', 90000, '2019-09-15', 'Lahore', 10),
(9, 'Zain Ali', 'Sales', 'Regional Head', 140000, '2016-11-22', 'Islamabad',
NULL),
(10, 'Nimra Shah', 'Finance', 'Finance Head', 155000, '2015-12-01',
'Lahore', NULL),
(11, 'Rashid Khan', 'IT', 'Database Admin', 125000, '2022-02-10', 'Karachi',
7),
(12, 'Maryam Aslam', 'HR', 'Recruiter', 60000, '2023-08-10', 'Lahore', 1);
