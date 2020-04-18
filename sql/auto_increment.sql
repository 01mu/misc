source clear.sql;

CREATE TABLE inc (id int AUTO_INCREMENT PRIMARY KEY, thing int);
DESCRIBE inc;

INSERT INTO inc (thing) VALUES (3), (66), (NULL), (100), (NULL), (3000), (68),
    (102), (NULL), (69), (NULL), (NULL);

SELECT * FROM inc;
SELECT LAST_INSERT_ID() AS last FROM inc;
