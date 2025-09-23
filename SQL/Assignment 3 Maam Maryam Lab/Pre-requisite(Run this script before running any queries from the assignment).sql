CREATE DATABASE IF NOT EXISTS SchoolDB;
USE SchoolDB;
CREATE TABLE Student (
 StudentID INT PRIMARY KEY,
 FirstName VARCHAR(30),
 LastName VARCHAR(30),
 -- Note: Marks and FeePaid stored as strings to show conversions
 Marks VARCHAR(10),
 DOB DATE,
 Enrollment DATETIME,
 FeePaid VARCHAR(20)
);
INSERT INTO Student (StudentID, FirstName, LastName, Marks, DOB, Enrollment, FeePaid) VALUES
(1, 'Ali', 'Khan', '85', '2003-04-15', '2023-08-01 09:30:00', '1200.50'),
(2, 'Sara', 'Malik', '90', '2002-12-10', '2023-08-15 14:00:00', '1500.00'),
(3, 'Ahmed', 'Raza', '72', '2004-03-22', '2022-01-10 10:15:00', '800'),
(4, 'Ayesha', 'Iqbal', '95', '2001-07-30', '2023-01-05 08:45:00', '2000.75'),
(5, 'Bilal', 'Shah', '60', '2000-11-02', '2023-06-20 11:00:00', '0');
