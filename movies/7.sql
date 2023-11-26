SELECT movies.title, ratings.rating FROM movies, ratings
JOIN ratings ON ratings.movie_id = movies.id
WHERE movies.year = 2010;
