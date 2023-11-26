SELECT AVG(energy) FROM songs
WHERE name IN (SELECT name FROM artists) == 'Drake';
