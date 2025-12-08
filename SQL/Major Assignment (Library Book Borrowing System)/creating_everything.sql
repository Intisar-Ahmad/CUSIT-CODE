-- screenshot 1
CREATE DATABASE LBBS;
USE LBBS;

-- screenshot 2
CREATE TABLE STUDENT (
    student_id INT PRIMARY KEY AUTO_INCREMENT,
    full_name VARCHAR(100) NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL,
    phone VARCHAR(20),
    gender ENUM('Male','Female','Other') NOT NULL,
    membership_id INT,
    address VARCHAR(255),
    created_at DATETIME DEFAULT CURRENT_TIMESTAMP
);

INSERT INTO STUDENT (full_name, email, phone, gender, membership_id, address)
VALUES
('Alice Johnson','alice.johnson@example.com','123-456-7890','Female',1,'123 Maple St'),
('Bob Smith','bob.smith@example.com','234-567-8901','Male',2,'456 Oak St'),
('Charlie Brown','charlie.brown@example.com','345-678-9012','Male',1,'789 Pine St'),
('Diana Prince','diana.prince@example.com','456-789-0123','Female',2,'321 Elm St'),
('Ethan Hunt','ethan.hunt@example.com','567-890-1234','Male',1,'654 Cedar St'),
('Fiona Apple','fiona.apple@example.com','678-901-2345','Female',1,'987 Birch St'),
('George Lucas','george.lucas@example.com','789-012-3456','Male',2,'159 Spruce St'),
('Hannah Montana','hannah.montana@example.com','890-123-4567','Female',1,'753 Willow St'),
('Ian McKellen','ian.mckellen@example.com','901-234-5678','Male',2,'852 Poplar St'),
('Julia Roberts','julia.roberts@example.com','012-345-6789','Female',1,'951 Ash St'),
('Kevin Hart','kevin.hart@example.com','123-456-7891','Male',1,'147 Fir St'),
('Laura Croft','laura.croft@example.com','234-567-8902','Female',2,'258 Palm St'),
('Michael Jordan','michael.jordan@example.com','345-678-9013','Male',1,'369 Cypress St'),
('Natalie Portman','natalie.portman@example.com','456-789-0124','Female',2,'471 Redwood St'),
('Oscar Isaac','oscar.isaac@example.com','567-890-1235','Male',1,'582 Hickory St');


-- screenshot 3

CREATE TABLE MEMBERSHIP_TYPE (
    membership_id INT PRIMARY KEY AUTO_INCREMENT,
    membership_name VARCHAR(50) NOT NULL,
    borrow_limit INT NOT NULL,
    validity_days INT NOT NULL
);

-- Insert 15 sample membership types
INSERT INTO MEMBERSHIP_TYPE (membership_name, borrow_limit, validity_days)
VALUES
('Standard',5,30),
('Premium',10,60),
('Gold',15,90),
('Silver',7,45),
('Bronze',3,15),
('Student',5,30),
('Faculty',12,120),
('Guest',2,7),
('VIP',20,365),
('Basic',4,20),
('Advanced',8,50),
('Pro',10,60),
('Elite',15,90),
('Trial',1,7),
('Extended',6,40);

-- screenshot 4
-- Create STAFF table
CREATE TABLE STAFF (
    staff_id INT PRIMARY KEY AUTO_INCREMENT,
    full_name VARCHAR(100) NOT NULL,
    role VARCHAR(50) NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL,
    phone VARCHAR(20),
    hired_date DATE
);

-- Insert 15 sample staff members
INSERT INTO STAFF (full_name, role, email, phone, hired_date)
VALUES
('Alice Warren','Librarian','alice.warren@example.com','111-222-3333','2020-01-15'),
('Bob Carter','Admin','bob.carter@example.com','222-333-4444','2019-05-10'),
('Catherine Hale','Librarian','catherine.hale@example.com','333-444-5555','2021-03-20'),
('David Smith','Librarian','david.smith@example.com','444-555-6666','2022-07-12'),
('Emma Brown','Admin','emma.brown@example.com','555-666-7777','2018-11-30'),
('Frank Miller','Librarian','frank.miller@example.com','666-777-8888','2020-09-05'),
('Grace Lee','Librarian','grace.lee@example.com','777-888-9999','2019-12-18'),
('Henry Adams','Admin','henry.adams@example.com','888-999-0000','2021-01-22'),
('Isla Moore','Librarian','isla.moore@example.com','999-000-1111','2022-04-11'),
('Jack White','Librarian','jack.white@example.com','000-111-2222','2019-08-14'),
('Karen Scott','Admin','karen.scott@example.com','111-222-3334','2020-06-06'),
('Liam Turner','Librarian','liam.turner@example.com','222-333-4445','2021-10-19'),
('Mia Phillips','Librarian','mia.phillips@example.com','333-444-5556','2022-02-28'),
('Nathan Hill','Admin','nathan.hill@example.com','444-555-6667','2018-07-25'),
('Olivia King','Librarian','olivia.king@example.com','555-666-7778','2020-12-09');

-- screenshot 5
-- Create USER_ACCOUNT table for staff authentication
CREATE TABLE USER_ACCOUNT (
    user_id INT PRIMARY KEY AUTO_INCREMENT,
    username VARCHAR(50) UNIQUE NOT NULL,
    password_hash VARCHAR(255) NOT NULL,
    staff_id INT NOT NULL,
    role_id INT,
    status ENUM('Active','Disabled') DEFAULT 'Active',
    created_at DATETIME DEFAULT CURRENT_TIMESTAMP,
    last_login DATETIME,
    FOREIGN KEY (staff_id) REFERENCES STAFF(staff_id)
);

-- Insert 15 sample user accounts
INSERT INTO USER_ACCOUNT (username, password_hash, staff_id, role_id, status)
VALUES
('alicew','hash1',1,2,'Active'),
('bobc','hash2',2,1,'Active'),
('cathh','hash3',3,2,'Active'),
('davids','hash4',4,2,'Active'),
('emmab','hash5',5,1,'Active'),
('frankm','hash6',6,2,'Active'),
('gracel','hash7',7,2,'Active'),
('henrya','hash8',8,1,'Active'),
('islam','hash9',9,2,'Active'),
('jackw','hash10',10,2,'Active'),
('karens','hash11',11,1,'Active'),
('liamt','hash12',12,2,'Active'),
('miap','hash13',13,2,'Active'),
('nathanh','hash14',14,1,'Active'),
('oliviak','hash15',15,2,'Active');


-- screenshot 6

-- Create USER_ROLE table
CREATE TABLE USER_ROLE (
    role_id INT PRIMARY KEY AUTO_INCREMENT,
    role_name VARCHAR(50) NOT NULL,
    permissions TEXT
);

-- Insert 15 sample roles (for demonstration we’ll repeat some)
INSERT INTO USER_ROLE (role_name, permissions)
VALUES
('Admin','{"manage_staff":true,"view_reports":true,"manage_books":true}'),
('Librarian','{"manage_students":true,"approve_borrow":true,"handle_fines":true}'),
('Admin','{"manage_staff":true,"view_reports":true,"manage_books":true}'),
('Librarian','{"manage_students":true,"approve_borrow":true,"handle_fines":true}'),
('Admin','{"manage_staff":true,"view_reports":true,"manage_books":true}'),
('Librarian','{"manage_students":true,"approve_borrow":true,"handle_fines":true}'),
('Admin','{"manage_staff":true,"view_reports":true,"manage_books":true}'),
('Librarian','{"manage_students":true,"approve_borrow":true,"handle_fines":true}'),
('Admin','{"manage_staff":true,"view_reports":true,"manage_books":true}'),
('Librarian','{"manage_students":true,"approve_borrow":true,"handle_fines":true}'),
('Admin','{"manage_staff":true,"view_reports":true,"manage_books":true}'),
('Librarian','{"manage_students":true,"approve_borrow":true,"handle_fines":true}'),
('Admin','{"manage_staff":true,"view_reports":true,"manage_books":true}'),
('Librarian','{"manage_students":true,"approve_borrow":true,"handle_fines":true}'),
('Admin','{"manage_staff":true,"view_reports":true,"manage_books":true}');


-- screenshot 7
-- Create AUTHOR table
CREATE TABLE AUTHOR (
    author_id INT PRIMARY KEY AUTO_INCREMENT,
    full_name VARCHAR(100) NOT NULL,
    nationality VARCHAR(50),
    birth_year INT
);

-- Insert 15 sample authors
INSERT INTO AUTHOR (full_name, nationality, birth_year)
VALUES
('J.K. Rowling','British',1965),
('George R.R. Martin','American',1948),
('J.R.R. Tolkien','British',1892),
('Agatha Christie','British',1890),
('Stephen King','American',1947),
('Isaac Asimov','Russian',1920),
('Mark Twain','American',1835),
('Ernest Hemingway','American',1899),
('Jane Austen','British',1775),
('Charles Dickens','British',1812),
('F. Scott Fitzgerald','American',1896),
('Leo Tolstoy','Russian',1828),
('H.G. Wells','British',1866),
('Arthur Conan Doyle','British',1859),
('Dan Brown','American',1964);

-- screenshot 8

-- Create PUBLISHER table
CREATE TABLE PUBLISHER (
    publisher_id INT PRIMARY KEY AUTO_INCREMENT,
    publisher_name VARCHAR(150) NOT NULL,
    address VARCHAR(255),
    phone VARCHAR(20)
);

-- Insert 15 sample publishers
INSERT INTO PUBLISHER (publisher_name, address, phone)
VALUES
('Penguin Random House','1745 Broadway, New York, NY','111-222-3333'),
('HarperCollins','195 Broadway, New York, NY','222-333-4444'),
('Simon & Schuster','1230 Avenue of the Americas, NY','333-444-5555'),
('Hachette Book Group','1290 Avenue of the Americas, NY','444-555-6666'),
('Macmillan Publishers','120 Broadway, NY','555-666-7777'),
('Scholastic','557 Broadway, NY','666-777-8888'),
('Oxford University Press','198 Madison Ave, NY','777-888-9999'),
('Cambridge University Press','1 Liberty St, NY','888-999-0000'),
('Pearson','221 Main St, NY','999-000-1111'),
('Bloomsbury','50 Bedford Square, London','000-111-2222'),
('Wiley','111 River St, Hoboken','111-222-3334'),
('McGraw-Hill','1221 Avenue of the Americas, NY','222-333-4445'),
('Cengage','200 Pier 4 Blvd, Boston','333-444-5556'),
('Springer','233 Spring St, NY','444-555-6667'),
('Routledge','2 Park Square, London','555-666-7778');


-- screenshot 9
-- Create CATEGORY table
CREATE TABLE CATEGORY (
    category_id INT PRIMARY KEY AUTO_INCREMENT,
    category_name VARCHAR(100) NOT NULL
);

-- Insert 15 sample categories
INSERT INTO CATEGORY (category_name)
VALUES
('Fiction'),
('Science'),
('History'),
('Biography'),
('Mystery'),
('Fantasy'),
('Romance'),
('Thriller'),
('Science Fiction'),
('Self-Help'),
('Horror'),
('Children'),
('Adventure'),
('Philosophy'),
('Poetry');


-- screenshot 10

-- Create BOOK table
CREATE TABLE BOOK (
    book_id INT PRIMARY KEY AUTO_INCREMENT,
    title VARCHAR(200) NOT NULL,
    isbn VARCHAR(20) UNIQUE NOT NULL,
    publisher_id INT,
    category_id INT,
    publication_year INT,
    language VARCHAR(50),
    edition VARCHAR(50),
    FOREIGN KEY (publisher_id) REFERENCES PUBLISHER(publisher_id),
    FOREIGN KEY (category_id) REFERENCES CATEGORY(category_id)
);

-- Insert 15 sample books
INSERT INTO BOOK (title, isbn, publisher_id, category_id, publication_year, language, edition)
VALUES
('Harry Potter and the Sorcerer''s Stone','9780747532699',1,6,1997,'English','1st'),
('A Game of Thrones','9780553103540',2,6,1996,'English','1st'),
('The Hobbit','9780345339683',3,6,1937,'English','1st'),
('Murder on the Orient Express','9780062693662',4,5,1934,'English','1st'),
('The Shining','9780385121675',5,11,1977,'English','1st'),
('Foundation','9780553293357',6,9,1951,'English','1st'),
('Adventures of Huckleberry Finn','9780486280615',7,13,1884,'English','1st'),
('Pride and Prejudice','9781503290563',8,7,1813,'English','1st'),
('1984','9780451524935',9,9,1949,'English','1st'),
('To Kill a Mockingbird','9780446310789',10,1,1960,'English','1st'),
('The Great Gatsby','9780743273565',11,1,1925,'English','1st'),
('War and Peace','9781853260629',12,3,1869,'English','1st'),
('The Time Machine','9780812505047',13,9,1895,'English','1st'),
('The Da Vinci Code','9780385504201',14,5,2003,'English','1st'),
('Emma','9781503290587',15,7,1815,'English','1st');

-- screenshot 11

-- Create BOOK_AUTHOR junction table
CREATE TABLE BOOK_AUTHOR (
    book_id INT,
    author_id INT,
    PRIMARY KEY (book_id, author_id),
    FOREIGN KEY (book_id) REFERENCES BOOK(book_id),
    FOREIGN KEY (author_id) REFERENCES AUTHOR(author_id)
);

-- Insert sample book-author relationships (15 entries)
INSERT INTO BOOK_AUTHOR (book_id, author_id)
VALUES
(1,1),(2,2),(3,3),(4,4),(5,5),
(6,6),(7,7),(8,9),(9,10),(10,11),
(11,11),(12,12),(13,13),(14,15),(15,9);


-- screenshot 12

-- Create BRANCH table
CREATE TABLE BRANCH (
    branch_id INT PRIMARY KEY AUTO_INCREMENT,
    branch_name VARCHAR(100) NOT NULL,
    location VARCHAR(255)
);

-- Insert 15 sample branches
INSERT INTO BRANCH (branch_name, location)
VALUES
('Central Library','123 Main St'),
('East Branch','456 East Ave'),
('West Branch','789 West Blvd'),
('North Branch','101 North Rd'),
('South Branch','202 South St'),
('Downtown Library','303 Downtown Ave'),
('Uptown Library','404 Uptown Rd'),
('City Library','505 City Blvd'),
('Campus Library','606 Campus St'),
('Community Library','707 Community Ave'),
('River Branch','808 River Rd'),
('Mountain Branch','909 Mountain St'),
('Lakeside Branch','111 Lake Rd'),
('Valley Branch','222 Valley Blvd'),
('Forest Branch','333 Forest St');


-- screenshot 13
-- Create BOOK_COPY table
CREATE TABLE BOOK_COPY (
    copy_id INT PRIMARY KEY AUTO_INCREMENT,
    book_id INT,
    branch_id INT,
    status ENUM('Available','Borrowed','Reserved','Lost','Damaged') DEFAULT 'Available',
    added_date DATE,
    FOREIGN KEY (book_id) REFERENCES BOOK(book_id),
    FOREIGN KEY (branch_id) REFERENCES BRANCH(branch_id)
);

-- Insert 15 sample book copies
INSERT INTO BOOK_COPY (book_id, branch_id, status, added_date)
VALUES
(1,1,'Available','2023-01-10'),
(2,1,'Borrowed','2023-02-12'),
(3,2,'Available','2023-03-05'),
(4,2,'Reserved','2023-01-22'),
(5,3,'Available','2023-04-01'),
(6,3,'Lost','2023-02-28'),
(7,4,'Damaged','2023-03-15'),
(8,4,'Available','2023-01-18'),
(9,5,'Available','2023-02-10'),
(10,5,'Borrowed','2023-03-01'),
(11,6,'Available','2023-02-20'),
(12,6,'Available','2023-01-30'),
(13,7,'Reserved','2023-03-22'),
(14,7,'Available','2023-02-05'),
(15,8,'Available','2023-03-10');


-- screenshot 14

-- Create BORROW table
CREATE TABLE BORROW (
    borrow_id INT PRIMARY KEY AUTO_INCREMENT,
    student_id INT,
    staff_id INT,
    borrow_date DATE,
    due_date DATE,
    return_date DATE,
    FOREIGN KEY (student_id) REFERENCES STUDENT(student_id),
    FOREIGN KEY (staff_id) REFERENCES STAFF(staff_id)
);

-- Insert 15 sample borrow transactions
INSERT INTO BORROW (student_id, staff_id, borrow_date, due_date, return_date)
VALUES
(1,1,'2023-10-01','2023-10-15','2023-10-14'),
(2,2,'2023-10-02','2023-10-16',NULL),
(3,3,'2023-10-03','2023-10-17','2023-10-16'),
(4,4,'2023-10-04','2023-10-18',NULL),
(5,5,'2023-10-05','2023-10-19','2023-10-18'),
(6,6,'2023-10-06','2023-10-20',NULL),
(7,7,'2023-10-07','2023-10-21','2023-10-20'),
(8,8,'2023-10-08','2023-10-22',NULL),
(9,9,'2023-10-09','2023-10-23','2023-10-22'),
(10,10,'2023-10-10','2023-10-24',NULL),
(11,11,'2023-10-11','2023-10-25','2023-10-24'),
(12,12,'2023-10-12','2023-10-26',NULL),
(13,13,'2023-10-13','2023-10-27','2023-10-26'),
(14,14,'2023-10-14','2023-10-28',NULL),
(15,15,'2023-10-15','2023-10-29','2023-10-28');

-- screenshot 15

-- Create BORROW_DETAIL table
CREATE TABLE BORROW_DETAIL (
    borrow_id INT,
    copy_id INT,
    PRIMARY KEY (borrow_id, copy_id),
    FOREIGN KEY (borrow_id) REFERENCES BORROW(borrow_id),
    FOREIGN KEY (copy_id) REFERENCES BOOK_COPY(copy_id)
);

-- Insert 15 borrow-detail records
INSERT INTO BORROW_DETAIL (borrow_id, copy_id)
VALUES
(1,1),(2,2),(3,3),(4,4),(5,5),
(6,6),(7,7),(8,8),(9,9),(10,10),
(11,11),(12,12),(13,13),(14,14),(15,15);

-- screenshot 16
-- Create RESERVATION table
CREATE TABLE RESERVATION (
    reservation_id INT PRIMARY KEY AUTO_INCREMENT,
    student_id INT,
    book_id INT,
    reservation_date DATE,
    status ENUM('Pending','Approved','Cancelled') DEFAULT 'Pending',
    FOREIGN KEY (student_id) REFERENCES STUDENT(student_id),
    FOREIGN KEY (book_id) REFERENCES BOOK(book_id)
);

-- Insert 15 sample reservations
INSERT INTO RESERVATION (student_id, book_id, reservation_date, status)
VALUES
(1,2,'2023-10-05','Pending'),
(2,3,'2023-10-06','Approved'),
(3,4,'2023-10-07','Pending'),
(4,5,'2023-10-08','Cancelled'),
(5,6,'2023-10-09','Pending'),
(6,7,'2023-10-10','Approved'),
(7,8,'2023-10-11','Pending'),
(8,9,'2023-10-12','Cancelled'),
(9,10,'2023-10-13','Pending'),
(10,11,'2023-10-14','Approved'),
(11,12,'2023-10-15','Pending'),
(12,13,'2023-10-16','Cancelled'),
(13,14,'2023-10-17','Pending'),
(14,15,'2023-10-18','Approved'),
(15,1,'2023-10-19','Pending');


-- screenshot 17
-- Create FINE table
CREATE TABLE FINE (
    fine_id INT PRIMARY KEY AUTO_INCREMENT,
    borrow_id INT,
    amount DECIMAL(6,2),
    issued_date DATE,
    status ENUM('Unpaid','Paid') DEFAULT 'Unpaid',
    FOREIGN KEY (borrow_id) REFERENCES BORROW(borrow_id)
);

-- Insert 15 sample fines
INSERT INTO FINE (borrow_id, amount, issued_date, status)
VALUES
(1,5.00,'2023-10-16','Paid'),
(2,3.50,'2023-10-18','Unpaid'),
(3,0.00,'2023-10-17','Paid'),
(4,4.25,'2023-10-19','Unpaid'),
(5,0.00,'2023-10-18','Paid'),
(6,2.50,'2023-10-20','Unpaid'),
(7,0.00,'2023-10-20','Paid'),
(8,1.75,'2023-10-22','Unpaid'),
(9,0.00,'2023-10-22','Paid'),
(10,3.00,'2023-10-24','Unpaid'),
(11,0.00,'2023-10-24','Paid'),
(12,2.25,'2023-10-26','Unpaid'),
(13,0.00,'2023-10-26','Paid'),
(14,1.50,'2023-10-28','Unpaid'),
(15,0.00,'2023-10-28','Paid');

-- screenshot 18
-- Create PAYMENT table
CREATE TABLE PAYMENT (
    payment_id INT PRIMARY KEY AUTO_INCREMENT,
    fine_id INT,
    student_id INT,
    payment_date DATE,
    amount DECIMAL(6,2),
    method VARCHAR(50),
    FOREIGN KEY (fine_id) REFERENCES FINE(fine_id),
    FOREIGN KEY (student_id) REFERENCES STUDENT(student_id)
);

-- Insert 15 sample payments
INSERT INTO PAYMENT (fine_id, student_id, payment_date, amount, method)
VALUES
(1,1,'2023-10-16',5.00,'Cash'),
(3,3,'2023-10-17',0.00,'Card'),
(5,5,'2023-10-18',0.00,'Cash'),
(7,7,'2023-10-20',0.00,'Card'),
(9,9,'2023-10-22',0.00,'Cash'),
(11,11,'2023-10-24',0.00,'Card'),
(13,13,'2023-10-26',0.00,'Cash'),
(15,15,'2023-10-28',0.00,'Card'),
(2,2,'2023-10-18',3.50,'Cash'),
(4,4,'2023-10-19',4.25,'Card'),
(6,6,'2023-10-20',2.50,'Cash'),
(8,8,'2023-10-22',1.75,'Card'),
(10,10,'2023-10-24',3.00,'Cash'),
(12,12,'2023-10-26',2.25,'Card'),
(14,14,'2023-10-28',1.50,'Cash');































