source clear.sql;

CREATE TABLE ft (name CHAR(20), txt TEXT) ENGINE = MyISAM;
ALTER TABLE ft ADD FULLTEXT (txt), ADD FULLTEXT (name), ADD FULLTEXT (name, txt);
INSERT INTO ft (name, txt) VALUES ('Joe', 'Aa'), ('Sally', 'Bb'), ('Bill', 'A');
SELECT txt, MATCH(txt) AGAINST ('Bb') AS relevance FROM ft;
