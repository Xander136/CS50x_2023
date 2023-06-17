-- In 8.sql, write a SQL query to list the names of all people who starred in Toy Story.
-- Your query should output a table with a single column for the name of each person.
-- You may assume that there is only one movie in the database with the title Toy Story.

SELECT people.name FROM people WHERE people.id IN
(SELECT stars.person_id FROM stars
WHERE stars.movie_id = (SELECT movies.id FROM movies WHERE movies.title = 'Toy Story'));