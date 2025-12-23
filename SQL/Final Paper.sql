-- CREATE DATABASE final_paper;
USE final_paper;

-- CREATE TABLE Students (
--     Std_ID INT PRIMARY KEY,
--     Std_Name VARCHAR(50),
--     Std_Age INT
-- );

-- INSERT INTO Students VALUES
-- (1, 'Ali Hassan', 20),
-- (2, 'Sara Khan', 21),
-- (3, 'Bilal Ahmed', 22),
-- (4, 'Ayesha Noor', 20);

-- CREATE TABLE Enrollments (
--     Std_ID INT,
--     Course_ID VARCHAR(10),
--     Grade CHAR(1),
--     FOREIGN KEY (Std_ID) REFERENCES Students(Std_ID)
-- );

-- INSERT INTO Enrollments VALUES
-- (1, 'DB101', 'A'),
-- (2, 'CS102', 'B'),
-- (3, 'SE103', 'A');

-- CREATE TABLE Alumni (
--     Std_ID INT PRIMARY KEY,
--     Std_Name VARCHAR(50),
--     Std_Age INT
-- );

-- INSERT INTO Alumni VALUES
-- (5, 'Hamza Ali', 24),
-- (6, 'Noor Fatima', 23);

-- CREATE TABLE Course_Registrations (
--     Std_ID INT,
--     Course_Code VARCHAR(10),
--     Grade CHAR(1)
-- );

-- INSERT INTO Course_Registrations VALUES
-- (1, 'DB101', 'A'),
-- (2, 'CS102', 'B'),
-- (3, 'SE103', 'A');

-- question 1 a
SELECT 
    s.Std_ID,
    s.Std_Name,
    s.Std_Age,
    e.Course_ID,
    e.Grade
FROM Students s
LEFT JOIN Enrollments e
ON s.Std_ID = e.Std_ID;

-- question 1b
SELECT Std_ID, Std_Name, Std_Age
FROM Students
UNION
SELECT Std_ID, Std_Name, Std_Age
FROM Alumni;

-- requisites for question2
-- CREATE TABLE Departments (
--     Dept_ID INT PRIMARY KEY,
--     Dept_Name VARCHAR(30) UNIQUE
-- );

-- INSERT INTO Departments VALUES
-- (10, 'IT'),
-- (20, 'HR'),
-- (30, 'Finance');

-- CREATE TABLE Employees (
--     Emp_ID INT PRIMARY KEY,
--     Emp_Name VARCHAR(50) NOT NULL,
--     Department VARCHAR(30),
--     Salary INT CHECK (Salary > 0) DEFAULT 30000
-- );

-- INSERT INTO Employees VALUES
-- (1, 'Ali Khan', 'IT', 60000),
-- (2, 'Sara Ahmed', 'HR', 75000),
-- (3, 'Usman Raza', 'IT', 50000),
-- (4, 'Ayesha Noor', 'Finance', 90000),
-- (5, 'Bilal Shah', 'HR', 45000);



-- question2a
SELECT Emp_Name, Salary
FROM Employees
WHERE Salary =
      (SELECT MAX(Salary) FROM Employees);

-- multi-row
SELECT Emp_Name, Department
FROM Employees
WHERE Department IN
      (SELECT Dept_Name FROM Departments);


-- corelated query
SELECT Emp_Name, Salary,Department
FROM Employees e
WHERE Salary >
      (SELECT AVG(Salary)
       FROM Employees
       WHERE Department = e.Department);

-- question2b
CREATE TABLE Employee_Constraints ( -- dummy table to add constraints
    Emp_ID INT,
    Emp_Name VARCHAR(50),
    Salary INT,
    Dept_ID INT
);

-- primary key
ALTER TABLE Employee_Constraints
ADD CONSTRAINT pk_emp
PRIMARY KEY (Emp_ID);

-- not null
ALTER TABLE Employee_Constraints
MODIFY Emp_Name VARCHAR(50) NOT NULL;

-- check
ALTER TABLE Employee_Constraints
ADD CONSTRAINT chk_salary
CHECK (Salary > 0);

-- default
ALTER TABLE Employee_Constraints
MODIFY Salary INT DEFAULT 30000;

-- foreign key
ALTER TABLE Employee_Constraints
ADD CONSTRAINT fk_dept
FOREIGN KEY (Dept_ID)
REFERENCES Departments(Dept_ID);


-- requisites for question 3
-- CREATE TABLE Bank_Accounts (
--     Account_ID INT PRIMARY KEY,
--     Account_Holder VARCHAR(50),
--     Balance INT
-- );

-- INSERT INTO Bank_Accounts VALUES
-- (1001, 'Ali Khan', 80000),
-- (1002, 'Sara Ahmed', 55000),
-- (1003, 'Usman Raza', 30000);


-- question 3
START TRANSACTION;

SAVEPOINT sp1;
select * from bank_accounts;

UPDATE Bank_Accounts
SET Balance = Balance - 10000
WHERE Account_ID = 1001;

select * from bank_accounts;

commit;

select * from bank_accounts;
-- requisites for question 4

-- CREATE TABLE Employee (
--     Emp_ID INT PRIMARY KEY,
--     Emp_Name VARCHAR(50),
--     Salary INT
-- );

-- INSERT INTO Employee VALUES
-- (401, 'Ali Khan', 48000),
-- (402, 'Sara Ahmed', 52000),
-- (403, 'Usman Raza', 45000),
-- (404, 'Ayesha Noor', 70000);

-- question 4
DELIMITER //

CREATE PROCEDURE Update_Salary(IN p_emp_id INT)
BEGIN
    DECLARE v_salary INT;
    DECLARE v_new_salary DECIMAL(10,2);

    SELECT Salary INTO v_salary
    FROM Employee
    WHERE Emp_ID = p_emp_id;

    IF v_salary > 50000 THEN
        SET v_new_salary = v_salary * 1.10;
    ELSE
        SET v_new_salary = v_salary * 1.05;
    END IF;

    SELECT
        Emp_ID AS Employee_ID,
        Emp_Name AS Employee_Name,
        v_salary AS Original_Salary,
        v_new_salary AS Updated_Salary
    FROM Employee
    WHERE Emp_ID = p_emp_id;
    UPDATE Employee SET Salary = v_new_salary WHERE Emp_ID = p_emp_id;
END//

DELIMITER ;

CALL Update_Salary(401);



DELIMITER $$

CREATE TRIGGER before_employee_insert
BEFORE INSERT ON Employee
FOR EACH ROW
BEGIN
    IF NEW.Salary < 20000 THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Salary cannot be less than 20,000';
    END IF;
END$$

DELIMITER ;

INSERT INTO Employee VALUES
(405, 'bhino', 18000);











































