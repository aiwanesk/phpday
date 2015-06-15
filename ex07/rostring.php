#!/usr/bin/php
<?PHP

	$tab = explode(" ", $argv[1]);
	$tab = array_filter($tab);
	$str = $tab[0];
	unset($tab[0]);
	foreach ($tab as $val)
		echo "$val ";
	echo "$str\n";
?>
