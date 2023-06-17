-- In 11.sql, write a SQL query to list the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated.
-- Your query should output a table with a single column for the title of each movie.
-- You may assume that there is only one person in the database with the name Chadwick Boseman.

SELECT m.title FROM movies m
WHERE m.id IN
(SELECT s.movie_id FROM stars s
WHERE s.person_id =
(SELECT p.id FROM people p
WHERE p.name = 'Chadwick Boseman'))

LIMIT 5;