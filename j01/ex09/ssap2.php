#!/usr/bin/php

<?PHP

if ($argc > 1)
{
	$str = implode(" ", $argv);
	$str = trim($str);
	$tab = explode(" ", $str);
	unset ($tab[0]);
	$alpha;
	$numeric;
	$else;
	$i = 1;
	$j = 0;
	$k = 0;
	$l = 0;

	while ($tab[$i])
	{
		$str = $tab[$i];
		if (($str[0] >= 'A' AND $str[0] <= 'Z') OR ($str[0] >= 'a' AND $str[0] <= 'z'))
		{
			$alpha[$j] = $str;
			$j++;
		}
		else if (is_numeric($str[0]))
		{
			$numeric[$k] = $str;
			$k++;
		}
		else
		{
			$else[$l] = $str;
			$l++;
		}
		$i++;
	}
	if ($alpha)
		sort($alpha, SORT_NATURAL | SORT_FLAG_CASE);
	if ($numeric)
		sort($numeric, SORT_STRING);
	if ($else)
		sort($else, SORT_STRING);
	$i = 0;
	while ($alpha[$i])
	{
		echo $alpha[$i];
		echo "\n";
		$i++;
	}
	$i = 0;
	while ($numeric[$i])
	{
		echo $numeric[$i];
		echo "\n";
		$i++;
	}
	$i = 0;
	while ($else[$i])
	{
		echo $else[$i];
		echo "\n";
		$i++;
	}
}
?>
