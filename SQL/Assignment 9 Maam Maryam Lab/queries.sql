
USE trigger_demo;

-- 1. Trigger that prevents deletion of a customer whose balance > 0
DELIMITER $$

CREATE TRIGGER prevent_customer_delete
BEFORE DELETE ON customers
FOR EACH ROW
BEGIN
    IF OLD.balance > 0 THEN
        SIGNAL SQLSTATE '45000'
            SET MESSAGE_TEXT = 'Cannot delete customer with positive balance';
    END IF;
END$$

DELIMITER ;



-- 2. Trigger that auto-updates last_modified whenever an employee record is updated
DELIMITER $$

CREATE TRIGGER update_employee_timestamp
BEFORE UPDATE ON employees
FOR EACH ROW
BEGIN
    SET NEW.last_modified = NOW();
END$$

DELIMITER ;


-- 3. BEFORE INSERT trigger that converts inserted student names to UPPERCASE
DELIMITER $$

CREATE TRIGGER uppercase_student_name
BEFORE INSERT ON students
FOR EACH ROW
BEGIN
    SET NEW.name = UPPER(NEW.name);
END$$

DELIMITER ;


-- 4. AFTER UPDATE trigger that logs salary updates into salary_history
DELIMITER $$

CREATE TRIGGER log_salary_update
AFTER UPDATE ON employees
FOR EACH ROW
BEGIN
    IF OLD.salary <> NEW.salary THEN
        INSERT INTO salary_history (employee_id, old_salary, new_salary, changed_at)
        VALUES (OLD.id, OLD.salary, NEW.salary, NOW());
    END IF;
END$$

DELIMITER ;



-- 5. Trigger that prevents inserting a product with quantity < 1
DELIMITER $$

CREATE TRIGGER prevent_invalid_quantity
BEFORE INSERT ON products
FOR EACH ROW
BEGIN
    IF NEW.quantity < 1 THEN
        SIGNAL SQLSTATE '45000'
            SET MESSAGE_TEXT = 'Quantity must be at least 1';
    END IF;
END$$

DELIMITER ;
