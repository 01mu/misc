DROP DATABASE fun;
CREATE DATABASE fun;
USE fun;

# Students (parent)

CREATE TABLE students (
    name VARCHAR(30), student_id INT(3),
    PRIMARY KEY(student_id)
);

# Hobbies and hobby cost (parent)

CREATE TABLE hobbies (
    hobby VARCHAR(30), cost INT(3),
    PRIMARY KEY(hobby)
);

# Student hobbies

CREATE TABLE student_hobbies (
    student_id INT(3), hobby VARCHAR(30),
    PRIMARY KEY(student_id, hobby),
    FOREIGN KEY (student_id) REFERENCES students (student_id),
    FOREIGN KEY (hobby) REFERENCES hobbies (hobby)
);

# Hobby ratings provided by students

CREATE TABLE student_hobby_ratings (
    student_id INT(3), hobby VARCHAR(30), rating INT(3),
    PRIMARY KEY(student_id, hobby, rating),
    FOREIGN KEY (student_id) REFERENCES students (student_id),
    FOREIGN KEY (hobby) REFERENCES hobbies (hobby)
);

# Insert into tables

INSERT INTO students VALUES ("Joe", 123), ("Sally", 456), ("Martin", 789),
    ("Martin", 1000);

INSERT INTO hobbies VALUES ("Golfing", 23), ("Swimming", 55), ("Hiking", 55),
    ("Dancing", 1), ("Meming", 222);

INSERT INTO student_hobbies VALUES (123, "Golfing"), (456, "Swimming"),
    (789, "Hiking"), (789, "Swimming");

INSERT INTO student_hobby_ratings VALUES (123, "Golfing", 10),
    (1000, "Swimming", 5);

# Find hobbies that have no followers

SELECT hobbies.hobby
FROM student_hobbies RIGHT JOIN hobbies
ON student_hobbies.hobby = hobbies.hobby
WHERE student_hobbies.hobby is NULL;

# Find student that does not have a hobby but has provided a hobby rating

SELECT students.name, student_hobby_ratings.hobby, student_hobby_ratings.rating
FROM students LEFT JOIN student_hobbies
ON students.student_id = student_hobbies.student_id
INNER JOIN student_hobby_ratings
ON students.student_id = student_hobby_ratings.student_id
WHERE student_hobbies.hobby is NULL;
