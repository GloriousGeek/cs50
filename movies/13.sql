-- SELECT DISTINCT people.name FROM people
-- JOIN stars ON stars.person_id = people.id
-- JOIN movies ON movies.id = stars.movie_id
-- WHERE movies.id IN (SELECT movies.id FROM stars
-- JOIN people ON stars.person_id = people.id
-- WHERE people.name = 'Kevin Bacon' AND people.birth = 1958)
-- AND people.name != 'Kevin Bacon';


SELECT DISTINCT p.name
FROM people p
JOIN stars s ON p.id = s.person_id
JOIN movies m ON s.movie_id = m.id
JOIN stars k ON m.id = k.movie_id
JOIN people kb ON k.person_id = kb.id
WHERE kb.name = 'Kevin Bacon' AND kb.birth = 1958
  AND p.name != 'Kevin Bacon';
