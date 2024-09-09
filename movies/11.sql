SELECT title FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON stars.person.id = people.id
JOIN ratings ON movies.id
