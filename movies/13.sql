SELECT people.name FROM people
JOIN stars ON stars.person_id = people.id
JOIN movies ON movies.id = stars.movie_id
WHERE movies.title IN (SELECT DISTINCT movies.title FROM people
JOIN stars AS s2 ON s2.person_id = people.id
JOIN movies AS m2 ON m2.id = s2.movie_id
WHERE people.name = 'Kevin Bacon' AND people.birth = 1958)
AND people.name != 'Kevin Bacon';

