SELECT movies.title FROM movies
JOIN ratings ON ratings.movie_id = movies.id
JOIN people ON 
