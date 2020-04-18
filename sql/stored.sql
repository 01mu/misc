source clear.sql;

CREATE TABLE names (name VARCHAR(255) PRIMARY KEY, job TEXT);
INSERT INTO names VALUES ("Jack", "Carpenter"), ("Theodore", "Waiter");

SELECT * FROM names;

DELIMITER $

CREATE FUNCTION job_from_name(name_search TEXT)
RETURNS TEXT
READS SQL DATA
BEGIN
    RETURN (SELECT job FROM names WHERE name = name_search);
END$

CREATE PROCEDURE proc()
BEGIN
    DECLARE person VARCHAR(255);
    DECLARE ex bool;

    SET person = "Jack";
    SET ex = (SELECT EXISTS (SELECT name FROM names WHERE name = person));

    IF ex THEN
        SELECT job_from_name(person) as "Job";
    END IF;
END$

CALL proc();
