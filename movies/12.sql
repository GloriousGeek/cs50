SELECT movies.title FROM movies
JOIN stars ON stars.movie_id = movies.id
JOIN people ON people.id = stars.person_id AND people.name = 'Bradley Cooper'
JOIN stars AS s2 ON s2.movie_id = movies.id
JOIN people AS p2 ON p2.id = s2.person_id AND p2.name = 'Jennifer Lawrence';

-- SELECT movies.title FROM movies
-- JOIN stars ON stars.movie_id = movies.id
-- JOIN people ON people.id = stars.person_id
-- WHERE people.name IN ('Bradley Cooper', 'Jennifer Lawrence')
-- GROUP BY movies.title
-- HAVING COUNT(people.name) > 1;
