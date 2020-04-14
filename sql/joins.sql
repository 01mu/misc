DROP DATABASE fun;
CREATE DATABASE fun;
USE fun;

# Students

CREATE TABLE students (
    name VARCHAR(30), student_id INT(3),
    INDEX (student_id),
    PRIMARY KEY(student_id)
);

# Hobbies

CREATE TABLE hobbies (
    hobby VARCHAR(30), cost INT(3),
    INDEX (hobby),
    PRIMARY KEY(hobby)
);

# Hobbies followed by students

CREATE TABLE student_hobbies (
    student_id INT(3), hobby VARCHAR(30),
    PRIMARY KEY(student_id, hobby),
    FOREIGN KEY (student_id) REFERENCES students (student_id)
        ON UPDATE CASCADE
        ON DELETE CASCADE,
    FOREIGN KEY (hobby) REFERENCES hobbies (hobby)
        ON UPDATE CASCADE
        ON DELETE CASCADE
);

# Hobby ratings provided by students

CREATE TABLE student_hobby_ratings (
    student_id INT(3), hobby VARCHAR(30), rating INT(3),
    PRIMARY KEY(student_id, hobby, rating),
    FOREIGN KEY (student_id) REFERENCES students (student_id)
        ON UPDATE CASCADE
        ON DELETE CASCADE,
    FOREIGN KEY (hobby) REFERENCES hobbies (hobby)
        ON UPDATE CASCADE
        ON DELETE CASCADE
);

# Insert into tables

INSERT INTO students VALUES ("Joe", 123), ("Sally", 456), ("Martin", 789),
    ("Martin", 1000), ("Lisa", 1), ("Dirt", 2);

#+--------+------------+
#| name   | student_id |
#+--------+------------+
#| Lisa   |          1 |
#| Dirt   |          2 |
#| Joe    |        123 |
#| Sally  |        456 |
#| Martin |        789 |
#| Martin |       1000 |
#+--------+------------+

INSERT INTO hobbies VALUES ("Golfing", 23), ("Swimming", 55), ("Hiking", 100),
    ("Dancing", 1), ("Painting", 222), ("Astroturfing", 1000), ("Rowing", 1);

#+--------------+------+
#| hobby        | cost |
#+--------------+------+
#| Astroturfing | 1000 |
#| Dancing      |    1 |
#| Golfing      |   23 |
#| Hiking       |  100 |
#| Painting     |  222 |
#| Rowing       |    1 |
#| Swimming     |   55 |
#+--------------+------+

INSERT INTO student_hobbies VALUES (123, "Golfing"), (456, "Swimming"),
    (789, "Hiking"), (789, "Swimming"), (1, "Swimming"), (456, "Hiking"),
    (2, "Astroturfing"), (123, "Rowing");

#+------------+--------------+
#| student_id | hobby        |
#+------------+--------------+
#|          2 | Astroturfing |
#|        456 | Hiking       |
#|        789 | Hiking       |
#|          1 | Swimming     |
#|        456 | Swimming     |
#|        789 | Swimming     |
#+------------+--------------+

INSERT INTO student_hobby_ratings VALUES (123, "Golfing", 10),
    (1000, "Swimming", 5), (123, "Swimming", 5), (2, "Painting", 0),
    (123, "Hiking", 100);

#+------------+----------+--------+
#| student_id | hobby    | rating |
#+------------+----------+--------+
#|        123 | Hiking   |    100 |
#|          2 | Painting |      0 |
#|        123 | Swimming |      5 |
#|       1000 | Swimming |      5 |
#+------------+----------+--------+

# Find hobbies that have no followers

SELECT hobbies.hobby
FROM student_hobbies
RIGHT JOIN hobbies
    ON student_hobbies.hobby = hobbies.hobby
WHERE student_hobbies.hobby is NULL;

#+----------+
#| hobby    |
#+----------+
#| Dancing  |
#| Painting |
#+----------+

# Find students that do not have a hobby but have provided a hobby rating

SELECT students.student_id, students.name, student_hobby_ratings.hobby,
student_hobby_ratings.rating
FROM students
LEFT JOIN student_hobbies
    ON students.student_id = student_hobbies.student_id
INNER JOIN student_hobby_ratings
    ON students.student_id = student_hobby_ratings.student_id
WHERE student_hobbies.hobby is NULL;

#+------------+--------+----------+--------+
#| student_id | name   | hobby    | rating |
#+------------+--------+----------+--------+
#|       1000 | Martin | Swimming |      5 |
#+------------+--------+----------+--------+

# Find hobbies shared between multiple students and the names of the students

SELECT DISTINCT (students.student_id), students.name, a.hobby
FROM student_hobbies as a
INNER JOIN student_hobbies as b
    ON a.hobby = b.hobby AND a.student_id <> b.student_id
INNER JOIN students
    ON a.student_id = students.student_id;

#+------------+--------+----------+
#| student_id | name   | hobby    |
#+------------+--------+----------+
#|        456 | Sally  | Hiking   |
#|        789 | Martin | Hiking   |
#|          1 | Lisa   | Swimming |
#|        456 | Sally  | Swimming |
#|        789 | Martin | Swimming |
#+------------+--------+----------+

# Get shared hobbies that have more than one student rating

SELECT a.hobby, COUNT(rating) as rating_count
FROM student_hobby_ratings as a
INNER JOIN (SELECT DISTINCT (a.hobby)
    FROM student_hobbies as a
    INNER JOIN student_hobbies as b
        ON a.hobby = b.hobby AND a.student_id <> b.student_id
    INNER JOIN students
        ON a.student_id = students.student_id) as b
    ON a.hobby = b.hobby
GROUP BY (a.hobby)
HAVING (rating_count > 1);

#+----------+--------------+
#| hobby    | rating_count |
#+----------+--------------+
#| Swimming |            2 |
#+----------+--------------+

# For each student, get the number of their hobbies and the sum of their costs

SELECT students.student_id, students.name,
COUNT(student_hobbies.student_id) as hobby_count,
SUM(hobbies.cost) as hobby_cost_sum
FROM hobbies
INNER JOIN student_hobbies
    ON hobbies.hobby = student_hobbies.hobby
INNER JOIN students
    ON student_hobbies.student_id = students.student_id
GROUP BY(students.student_id)
ORDER BY hobby_cost_sum DESC;

#+------------+--------+-------------+----------------+
#| student_id | name   | hobby_count | hobby_cost_sum |
#+------------+--------+-------------+----------------+
#|          2 | Dirt   |           1 |           1000 |
#|        456 | Sally  |           2 |            155 |
#|        789 | Martin |           2 |            155 |
#|          1 | Lisa   |           1 |             55 |
#|        123 | Joe    |           2 |             24 |
#+------------+--------+-------------+----------------+

# Delete the hobbies enjoyed by the student with the lowest cost sum

DELETE hobbies
FROM hobbies
INNER JOIN (SELECT hobby # hobbies of the lowest sum student
    FROM student_hobbies
    INNER JOIN (SELECT students.student_id, # student_id of lowest sum student
        SUM(hobbies.cost) as hobby_cost_sum
        FROM hobbies
        INNER JOIN student_hobbies
            ON hobbies.hobby = student_hobbies.hobby
        INNER JOIN students
            ON student_hobbies.student_id = students.student_id
        GROUP BY(students.student_id)
        ORDER BY hobby_cost_sum ASC
        LIMIT 1) as a
    ON student_hobbies.student_id = a.student_id) as a
ON hobbies.hobby = a.hobby;

SELECT * FROM hobbies;

#+--------------+------+
#| hobby        | cost |
#+--------------+------+
#| Astroturfing | 1000 |
#| Dancing      |    1 |
#| Hiking       |  100 |
#| Painting     |  222 |
#| Swimming     |   55 |
#+--------------+------+

INSERT INTO hobbies VALUES ("Golfing", 23), ("Rowing", 1);
