USE assignment_8;

-- Question:1 Answer: 5 * 4 = 20


-- Question2
SELECT d.drink, a.addon
FROM Drinks d
CROSS JOIN Addons a;


-- Question3
SELECT b.bread, f.filling, s.sauce
FROM Breads b
CROSS JOIN Fillings f
CROSS JOIN Sauces s;


-- Question4
-- printing all
SELECT d.drink,s.size
FROM Drinks d
CROSS JOIN Sizes s;



-- printing specified combos
SELECT d.drink, s.size
FROM Drinks d
CROSS JOIN Sizes s
WHERE d.drink = 'Latte' OR s.size = 'Small';


