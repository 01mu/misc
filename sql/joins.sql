# Load tables

source tables/student_hobbies.sql;

# Find hobbies that have no followers

SELECT hobbies.hobby
FROM student_hobbies
RIGHT JOIN hobbies
    ON student_hobbies.hobby = hobbies.hobby
WHERE student_hobbies.hobby IS NULL;

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
WHERE student_hobbies.hobby IS NULL;

#+------------+--------+----------+--------+
#| student_id | name   | hobby    | rating |
#+------------+--------+----------+--------+
#|       1000 | Martin | Swimming |      5 |
#+------------+--------+----------+--------+

# Insert tudents who do not have hobbies with hobbies nobody prefers

START TRANSACTION;

INSERT INTO student_hobbies
    (SELECT b.student_id, a.hobby
    FROM (SELECT hobbies.hobby
        FROM student_hobbies
        RIGHT JOIN hobbies
            ON student_hobbies.hobby = hobbies.hobby
        WHERE student_hobbies.hobby IS NULL) AS a
    INNER JOIN (SELECT students.student_id, students.name
        FROM students
        LEFT JOIN student_hobbies
            ON students.student_id = student_hobbies.student_id
        WHERE student_hobbies.hobby IS NULL) AS b);

SELECT * from student_hobbies;

ROLLBACK;

#+------------+--------------+
#| student_id | hobby        |
#+------------+--------------+
#|          2 | Astroturfing |
#|       1000 | Dancing      |
#|        123 | Golfing      |
#|        456 | Hiking       |
#|        789 | Hiking       |
#|       1000 | Painting     |
#|        123 | Rowing       |
#|          1 | Swimming     |
#|        456 | Swimming     |
#|        789 | Swimming     |
#+------------+--------------+

# Find hobbies shared between multiple students and the names of the students

SELECT DISTINCT (students.student_id), students.name, a.hobby
FROM student_hobbies AS a
INNER JOIN student_hobbies AS b
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

SELECT a.hobby, COUNT(rating) AS rating_count
FROM student_hobby_ratings AS a
INNER JOIN (SELECT DISTINCT (a.hobby)
    FROM student_hobbies AS a
    INNER JOIN student_hobbies AS b
        ON a.hobby = b.hobby AND a.student_id <> b.student_id
    INNER JOIN students
        ON a.student_id = students.student_id) AS b
    ON a.hobby = b.hobby
GROUP BY (a.hobby)
HAVING (rating_count > 1);

#+----------+--------------+
#| hobby    | rating_count |
#+----------+--------------+
#| Swimming |            2 |
#+----------+--------------+

# For each student get the number of their hobbies and the sum of their costs

SELECT students.student_id, students.name,
COUNT(student_hobbies.student_id) AS hobby_count,
SUM(hobbies.cost) AS hobby_cost_sum
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

START TRANSACTION;

DELETE hobbies
FROM hobbies
INNER JOIN (SELECT hobby
    FROM student_hobbies
    INNER JOIN (SELECT students.student_id, SUM(hobbies.cost) AS hobby_cost_sum
        FROM hobbies
        INNER JOIN student_hobbies
            ON hobbies.hobby = student_hobbies.hobby
        INNER JOIN students
            ON student_hobbies.student_id = students.student_id
        GROUP BY(students.student_id)
        ORDER BY hobby_cost_sum ASC
        LIMIT 1) AS a
    ON student_hobbies.student_id = a.student_id) AS a
ON hobbies.hobby = a.hobby;

SELECT * FROM hobbies;

ROLLBACK;

#+--------------+------+
#| hobby        | cost |
#+--------------+------+
#| Astroturfing | 1000 |
#| Dancing      |    1 |
#| Hiking       |  100 |
#| Painting     |  222 |
#| Swimming     |   55 |
#+--------------+------+
