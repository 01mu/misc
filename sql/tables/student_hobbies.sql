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
    PRIMARY KEY (hobby)
);

# Hobbies followed by students

CREATE TABLE student_hobbies (
    student_id INT(3), hobby VARCHAR(30),
    PRIMARY KEY (student_id, hobby),
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
    PRIMARY KEY (student_id, hobby, rating),
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
