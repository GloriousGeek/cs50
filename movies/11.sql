SELECT movies.title, ratings.rating, people.name FROM movies
JOIN stars ON stars.movie_id = movies.id
JOIN ratings ON ratings.movie_id = stars.movie_id
JOIN people ON people.id = stars.person_id
WHERE people.name = 'Chadwick Boseman' ORDER BY ratings.rating DESC LIMIT 5;
