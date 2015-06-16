#!/usr/bin/php
<?PHP
if ($argv[1])
{
	$str = trim ($argv[1]);
	$tab = explode(" ", $str);
	$tab = array_filter($tab);
	$str = $tab[0];
	unset($tab[0]);
	foreach ($tab as $val)
		echo "$val ";
	echo "$str\n";
}
?>
