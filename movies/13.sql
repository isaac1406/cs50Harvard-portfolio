SELECT name FROM people
JOIN stars ON people.id = stars.person_id
WHERE movie_id =
(
    SELECT id FROM movies
    WHERE people.name = 'Kevin Bacon'
    AND people.birth = 1958
);
