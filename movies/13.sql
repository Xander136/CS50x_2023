-- In 13.sql, write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
-- Your query should output a table with a single column for the name of each person.
-- There may be multiple people named Kevin Bacon in the database. Be sure to only select the Kevin Bacon born in 1958.
-- Kevin Bacon himself should not be included in the resulting list.

SELECT p.name FROM people p
JOIN stars s ON s.person_id = p.id
JOIN movies m ON m.id = s.movie_id
WHERE m.id IN (
    SELECT m.id FROM movies m
    JOIN stars s ON s.movie_id = m.id
    JOIN people p ON p.id = s.person_id
    WHERE p.name = 'Kevin Bacon' AND p.birth = 1958
)   AND p.name != 'Kevin Bacon';