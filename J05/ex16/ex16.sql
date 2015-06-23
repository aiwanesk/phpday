SELECT COUNT(titre) AS 'films'
FROM film
WHERE DATE(date_debut_affiche) BETWEEN '2006-10-30' AND '2007-07-27'
OR DATE(date_debut_affiche) LIKE '%-12-24';
