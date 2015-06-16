#!/usr/bin/php
<?PHP
if ($argc == 4)
{
	$elem1 = trim ($argv[1]);
	$elem2 = trim($argv[2]);
	$elem3 = trim($argv[3]);
	if ($elem2 == "+")
		echo $elem1 + $elem3;
	else if ($elem2 == "-")
		echo $elem1 - $elem3;
	else if ($elem2 == "/")
		echo $elem1 / $elem3;
	else if ($elem2 == "*")
		echo $elem1 * $elem3;
	else if ($elem2 == "%")
		echo $elem1 % $elem3;
}
else
	echo "erreur nb arg, or * without backquote";
?>
