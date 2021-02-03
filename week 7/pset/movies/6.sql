/* SELECT avg(rating) FROM ratings
JOIN movies ON ratings.movie_id = movies.id
WHERE year = 2012; */

SELECT avg(rating) FROM ratings where movie_id in (select id from movies where year = 2012);