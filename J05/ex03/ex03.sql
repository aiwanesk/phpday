INSERT INTO ft_table (login, date_de_creation, groupe) SELECT nom, date_de_creation, "other" FROM fiche_personne WHERE nom LIKE '%a%' AND LENGTH(nom) < 9 ORDER BY nom LIMIT 10;
