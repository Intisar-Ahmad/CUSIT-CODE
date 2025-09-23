USE SchoolDB;

-- Q1. Convert Marks (Text → Integer)
-- A Student table has a column Marks stored as text (e.g., '85', '72', '90').
-- Write a query to:
-- • Convert Marks into integers.
-- • Show each student’s StudentID, FirstName, and the converted marks (MarksInt).
-- • Also calculate the average marks of all students.


SELECT StudentID,FirstName,CAST(Marks AS UNSIGNED) AS MarksInt FROM student;
SELECT AVG(CAST(Marks AS UNSIGNED)) AS avg_marks FROM student;


-- Q2. Sum of Fees (Text → Decimal)
-- The FeePaid column is stored as text (e.g., '1200.50', '1500').
-- Write a query to:
-- • Convert FeePaid into a proper decimal number.
-- • Show the total of all fees paid (TotalFees).

SELECT StudentID, CAST(Feepaid AS DECIMAL(10,2)) FROM student;
SELECT SUM((CAST(Feepaid AS DECIMAL(10,2)))) AS TotalFees FROM student;

-- Q3. Format Payment for Display
-- Write a query to:
-- • Convert FeePaid into decimal.
-- • Format the result into a currency string with $ sign, commas, and 2 decimal places.
-- • Example: '1200.5' → $1,200.50

SELECT StudentID, CONCAT('$', FORMAT(CAST(FeePaid AS DECIMAL(10,2)), 2)) AS PaymentFormatted FROM Student;

-- Q4. Work with Student DOB (Date Functions)
-- Each student has a DOB column.
-- Write a query to:
-- • Display StudentID, FirstName, and their current age in years.
-- • Format DOB in a readable format (e.g., "Tuesday, April 15, 2003").

SELECT StudentID,FirstName,TIMESTAMPDIFF(YEAR,DOB,CURDATE()) AS Age, DATE_FORMAT(DOB, '%W, %M %d, %Y') AS FormattedDOB FROM Student;


-- Q5. Enrollment Tracking
-- The Enrollment column stores the date when a student joined.
-- Write a query to:
-- • Show how many days each student has been enrolled.
-- • Calculate their certificate expiry date (6 months after enrollment).
-- • Show a reminder date (10 days before enrollment date).
-- • Format the enrollment date in this format: "01-Aug-2023 09:30 AM".

SELECT DATEDIFF(CURDATE(),Enrollment) AS DaysEnrolled, DATE_ADD(Enrollment,INTERVAL 6 Month) AS `Certificate Expiry`,
DATE_SUB(Enrollment, INTERVAL 10 DAY) AS `Reminder Date`, DATE_FORMAT(Enrollment, '%d-%b-%Y %h %i %p') AS `Formatted Enrollment Date`  FROM student;


-- change the names of the variables if they cause issues. Also you can use CONVERT(exp,type) instead of CAST(exp AS type)










