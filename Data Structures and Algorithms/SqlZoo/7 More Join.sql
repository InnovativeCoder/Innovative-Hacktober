1 ## List the films where the yr is 1962 [Show id, title]

select id, title from movie
where yr = 1962

2 ## When was Citizen Kane released?

select yr from movie
where title = 'Citizen Kane'

3 ## List all of the Star Trek movies, include the id, title and yr (all of these movies include the words Star Trek in the title). Order results by year.

select id, title, yr from movie
where title like 'Star Trek%'

4 ## What id number does the actor 'Glenn Close' have?

select id from actor
where name = 'Glenn Close'

5 ## What is the id of the film 'Casablanca'

select id from movie
where title= 'Casablanca'

6 ## Obtain the cast list for 'Casablanca'.

what is a cast list?
Use movieid=11768, (or whatever value you got from the previous question)

select name
from actor,casting
where casting.actorid = actor.id and casting.movieid = (select id from movie
where title= 'Casablanca')

7 ## Obtain the cast list for the film 'Alien

select name
from actor,casting
where casting.actorid = actor.id and casting.movieid = (select id from movie
where title= 'Alien')

8 ## List the films in which 'Harrison Ford' has appeared

select title
from movie, casting, actor
where movie.id = casting.movieid and casting.actorid = actor.id and actor.name = 'Harrison Ford'

9 ## List the films where 'Harrison Ford' has appeared - but not in the starring role. [Note: the ord field of casting gives the position of the actor. If ord=1 then this actor is in the starring role]

select title
from movie, casting, actor
where movie.id = casting.movieid and casting.actorid = actor.id and actor.name = 'Harrison Ford' and casting.ord <> 1


10 ## List the films together with the leading star for all 1962 films.

select title, name
from movie, casting, actor
where movie.id = casting.movieid and casting.actorid = actor.id and movie.yr = 1962 and ord = 1

11 ## Which were the busiest years for 'John Travolta', show the year and the number of movies he made each year for any year in which he made more than 2 movies.

SELECT yr,COUNT(title) FROM
movie JOIN casting ON movie.id=movieid
JOIN actor ON actorid=actor.id
where name='John Travolta'
GROUP BY yr
HAVING COUNT(title)=(SELECT MAX(c) FROM
(SELECT yr,COUNT(title) AS c FROM
movie JOIN casting ON movie.id=movieid
JOIN actor ON actorid=actor.id
where name='John Travolta'
GROUP BY yr) AS t
)

12 ## List the film title and the leading actor for all of the films 'Julie Andrews' played in.

Did you get "Little Miss Marker twice"?
Julie Andrews starred in the 1980 remake of Little Miss Marker and not the original(1934).

Title is not a unique field, create a table of IDs in your subquery

select title, name FROM
movie JOIN casting ON movie.id=movieid
JOIN actor ON actorid=actor.id
where ord = 1 and movie.id in (
select distinct(movieid) name FROM
casting JOIN actor ON actorid=actor.id
where actor.name = 'Julie Andrews'
)

13 ## Obtain a list, in alphabetical order, of actors who've had at least 30 starring roles.

select name
from casting join actor on casting.actorid = actor.id
where casting.ord = 1
group by name
having count(name) >= 30

14 ## List the films released in the year 1978 ordered by the number of actors in the cast, then by title.

select title, count(title)
from movie join casting on movie.id = casting.movieid
where movie.yr = 1978
group by title
order by count(title) DESC, title

15 ## List all the people who have worked with 'Art Garfunkel'.

select name FROM
movie JOIN casting ON movie.id=movieid
JOIN actor ON actorid=actor.id
where casting.movieid in (select movieid from casting join actor on casting.actorid = actor.id
where name = 'Art Garfunkel') and actor.name <> 'Art Garfunkel'


