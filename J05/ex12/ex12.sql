SELECT nom, prenom
FROM fiche_personne
WHERE nom LIKE '%-%' XOR prenom '%-%'
ORDER BY nom,prenom;
