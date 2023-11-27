SELECT movies.title FROM movies
JOIN stars ON stars.movie_id = movies.id
JOIN people ON people.id = stars.person_id
WHERE people.name = 'Bradley Cooper' AND people.name = 'Jennifer Lawrence';
