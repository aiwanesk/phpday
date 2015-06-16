#!/usr/bin/php
<?php
	function error($nbr)
	{
		if ($nbr == 0)
			echo "Incorrect Parameters\n";
		else if ($nbr == 1)
			echo "Syntax Error\n";
		exit;
	}

	if ($argc != 2)
		error(0);
	$tab = explode(" ", $argv[1]);
	$str = implode("", $tab);
	$i = 0;
	$nbr = 0;
	while ($str[$i] != NULL)
	{
		if (is_numeric($str[$i]))
			;
		else if (($str[$i] == "+" || $str[$i] == "-" || $str[$i] == "/" || $str[$i] == "*" || $str[$i] == "%") && $nbr == 0)
		{
			$op = $str[$i];
			$nbr = 1;
		}
		else
			error(1);
		$i++;
	}
	$tab = explode($op, $str);
	if ($op == "+")
		$res = $tab[0] + $tab[1];
	else if ($op == "-")
		$res = $tab[0] - $tab[1];
	else if ($op == "*")
		$res = $tab[0] * $tab[1];
	else if ($op == "/" && $tab[1] != "0")
		$res = $tab[0] / $tab[1];
	else if ($op == "%")
		$res = $tab[0] % $tab[1];
	else
		error(1);
	if ($op != "/" || ($op == "/" && $tab[1] != "0"))
		echo "$res\n";
?>
