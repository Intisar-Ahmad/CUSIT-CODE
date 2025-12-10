USE lbbs;

-- screenshot 1
SELECT s.full_name, bo.title, b.borrow_date
FROM STUDENT s
JOIN BORROW b ON s.student_id = b.student_id
JOIN BORROW_DETAIL bd ON b.borrow_id = bd.borrow_id
JOIN BOOK_COPY bc ON bd.copy_id = bc.copy_id
JOIN BOOK bo ON bc.book_id = bo.book_id;

-- screenshot 2
SELECT s.full_name, b.borrow_id
FROM STUDENT s
LEFT JOIN BORROW b ON s.student_id = b.student_id;
-- screenshot 3
SELECT s.full_name, COUNT(b.borrow_id) AS total_borrows
FROM STUDENT s
LEFT JOIN BORROW b ON s.student_id = b.student_id
GROUP BY s.student_id;
-- screenshot 4
SELECT full_name
FROM STUDENT
WHERE student_id IN (
    SELECT BORROW.student_id
    FROM BORROW
    JOIN FINE ON BORROW.borrow_id = FINE.borrow_id
    WHERE status = 'Unpaid'
);
-- screenshot 5
SELECT title
FROM BOOK
WHERE book_id IN (
    SELECT bc.book_id
    FROM BORROW_DETAIL bd
    JOIN BOOK_COPY bc ON bd.copy_id = bc.copy_id
);
-- screenshot 6
SELECT a.full_name AS author, bo.title, s.full_name AS borrowed_by
FROM AUTHOR a
JOIN BOOK_AUTHOR ba ON a.author_id = ba.author_id
JOIN BOOK bo ON ba.book_id = bo.book_id
JOIN BOOK_COPY bc ON bo.book_id = bc.book_id
JOIN BORROW_DETAIL bd ON bc.copy_id = bd.copy_id
JOIN BORROW b ON bd.borrow_id = b.borrow_id
JOIN STUDENT s ON b.student_id = s.student_id;

-- screenshot 7
CREATE VIEW v_student_borrow_summary AS
SELECT 
    s.student_id,
    s.full_name,
    COUNT(b.borrow_id) AS total_borrows,
    SUM(CASE WHEN b.return_date IS NULL THEN 1 ELSE 0 END) AS currently_borrowed,
    SUM(CASE WHEN f.status = 'Unpaid' THEN 1 ELSE 0 END) AS unpaid_fines
FROM STUDENT s
LEFT JOIN BORROW b ON s.student_id = b.student_id
LEFT JOIN FINE f ON b.borrow_id = f.borrow_id
GROUP BY s.student_id;
SELECT * FROM v_student_borrow_summary;

-- screenshot 8
DELIMITER //
CREATE PROCEDURE getStudentBorrowInfo(IN p_student_id INT)
BEGIN
    SELECT 
        s.full_name,
        b.borrow_id,
        b.borrow_date,
        b.due_date,
        b.return_date,
        f.amount AS fine_amount,
        f.status AS fine_status
    FROM STUDENT s
    LEFT JOIN BORROW b ON s.student_id = b.student_id
    LEFT JOIN FINE f ON b.borrow_id = f.borrow_id
    WHERE s.student_id = p_student_id;
END //
DELIMITER ;

CALL getStudentBorrowInfo(5);



















