SELECT id FROM artists WHERE name == 'Post Malone';
SELECT name FROM songs WHERE artist_id == 54;

SELECT songs.name FROM songs
JOIN artists ON songs.artist_id = artists_id
WHERE artists.name == 'Post Malone';
