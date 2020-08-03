SELECT name
FROM people JOIN stars ON people.id = stars.person_id
JOIN movies ON movies.id = stars.movie_id
WHERE title = "Toy Story";

--linked 3 tables basically where the stars id is equal to movies id is equal to people id 