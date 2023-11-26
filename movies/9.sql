SELECT people.name, people.birth FROM people
WHERE people.id IN (SELECT person_id FROM stars
JOIN movies ON stars.movie_id = movies.id
WHERE movies.year == 2004) ORDER BY people.birth LIMIT 10;
