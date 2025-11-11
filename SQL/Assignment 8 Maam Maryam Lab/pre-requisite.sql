CREATE DATABASE assignment_8;
USE assignment_8;

CREATE TABLE Drinks (
  id INT AUTO_INCREMENT PRIMARY KEY ,
  drink VARCHAR(20)
);
CREATE TABLE Addons (addon VARCHAR(20));

INSERT INTO Drinks(drink) VALUES ('Espresso'), ('Latte');
INSERT INTO Addons VALUES ('ExtraShot'), ('VanillaSyrup'), ('None');


CREATE TABLE Breads (bread VARCHAR(20));
CREATE TABLE Fillings (filling VARCHAR(20));
CREATE TABLE Sauces (sauce VARCHAR(20));

INSERT INTO Breads VALUES ('White'), ('WholeGrain'), ('Multigrain');
INSERT INTO Fillings VALUES ('Chicken'), ('Tuna'), ('Egg'), ('Veggie');
INSERT INTO Sauces VALUES ('Mayo'), ('Mustard');



CREATE TABLE Sizes (
  id INT PRIMARY KEY,
  size VARCHAR(20)
);

INSERT INTO Sizes VALUES (1, 'Small'), (2, 'Medium'), (3, 'Large');
