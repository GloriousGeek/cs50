SELECT people.name, ratings.rating FROM people
WHERE people.id IN (SELECT person_id FROM directors
JOIN ratings ON ratings.movie_id = directors.movie_id
WHERE rating >= 9.0);
