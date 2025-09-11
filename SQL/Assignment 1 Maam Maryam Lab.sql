-- 1.	Write the query to create a database named University.
-- 2.	Write the query to create a table named student with columns: Id, Firstname, Lastname, Email, DateOfBirth, and reg_date.
-- 3.	Write the SQL query to insert the following record into the student table:
-- •	Firstname: Ali
-- •	Lastname: Khan
-- •	Email: ali.khan@gmail.com
-- •	DateOfBirth: 2000-05-20
-- 4.	Write the SQL query to select all the data from the student table.


-- Question#1
CREATE DATABASE University;


-- make sure the correct db is selected
USE University;


-- Question#2
CREATE TABLE student(
Id INT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
FirstName VARCHAR(30) NOT NULL,
LastName VARCHAR(30) NOT NULL,
Email VARCHAR(30) UNIQUE,
DateOfBirth DATE,
reg_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

-- Question#3
INSERT INTO student (FirstName,LastName,Email,DateOfBirth) VALUES 
('Ali', 'Khan', 'ali.khan@gmail.com' , '2000-05-20');

-- Question#4
SELECT * FROM student;
