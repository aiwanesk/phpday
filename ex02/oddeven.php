#!/usr/bin/php

<?PHP
$nbr;
while(1)
{
	echo "Entrez un nombre:";
	$fd = fopen("php://stdin", "r");
	$nbr = trim(fgets($fd), "\n");
	if (feof($fd))
		break;
	else if (!is_numeric($nbr))
		echo "$nbr n'est pas un nombre\n";
	else if ($nbr % 2 == 0)
		echo "Le nombre $nbr est pair\n";
	else if ($nbr % 2 == 1)
		echo "Le nomnbre $nbr est impair\n";
	else if ($nbr %2 == -1)
		echo "Le nomnbre $nbr est impair\n";
}
?>
