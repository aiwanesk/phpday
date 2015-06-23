SELECT UCASE(fiche_personne.nom) AS 'NOM', prenom, abonnement.prix
FROM fiche_personne
INNER JOIN membre ON fiche_personne.id_perso = membre,id_perso
INNER JOININ abonnement ON membre.id_abo = abonnement.id_aboWHERE abonnement.prix > 42
ORDER BY fiche_personne.nom, prenom;
