
-- Write a SQL query to create a database named UniversityDB.
CREATE DATABASE UniversityDB;


-- Select this database for use.
USE UniversityDB;


-- Create a table named Student with the columns mentioned below.
-- • StudentID (unique for each student)
-- • FirstName
-- • LastName
-- • Age
-- • reg_date (date and time when the record was created/updated)
CREATE TABLE Student(
StudentID INT AUTO_INCREMENT PRIMARY KEY,
FirstName VARCHAR(30),
LastName VARCHAR(30),
Age INT,
reg_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
);


/*
4. Insert the following student records into the table:
o StudentID: 101, Name: Ali Khan, Age: 20
o StudentID: 102, Name: Sara Malik, Age: 22
o StudentID: 103, Name: Ahmed Hussain, Age: 19
*/
INSERT INTO Student(StudentID,FirstName,LastName,Age)
 VALUES 
 (101,'Ali','Khan',20),
 (102,'Sara', 'Malik', 22),
 (103,'Ahmed','Hussain',19);

-- 5. Write a query to display all student records from the table.
SELECT * FROM Student;


-- 6. Write a query to display only the FirstName and Age of all students
SELECT FirstName,Age FROM Student;


-- 7. Update the age of Ali Khan (StudentID = 101) to 21.
UPDATE Student SET Age = 21 WHERE StudentID = 101;


-- 8. Update the last name of Sara from Malik to Sheikh.
UPDATE Student SET LastName = 'Sheikh' WHERE StudentID = 102;


-- 9. Delete the record of Ahmed Hussain (StudentID = 103).
DELETE FROM Student WHERE StudentID = 103;


-- 10.Write a query to display the remaining student records after deletion.
SELECT * FROM Student;

