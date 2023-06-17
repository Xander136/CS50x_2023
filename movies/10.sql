-- In 10.sql, write a SQL query to list the names of all people who have directed a movie that received a rating of at least 9.0.
-- Your query should output a table with a single column for the name of each person.
-- If a person directed more than one movie that received a rating of at least 9.0, they should only appear in your results once.

SELECT p.name FROM people p
WHERE p.id IN
(SELECT d.person_id FROM directors d
WHERE d.movie_id IN
(SELECT r.movie_id FROM ratings r
WHERE r.rating >= 9.0));
