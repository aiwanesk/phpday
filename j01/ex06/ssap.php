#!/usr/bin/php
<?PHP
if($argc > 1)
{
	$str = implode(" ", $argv);
	$tab = explode(" ", $str);
	unset($tab[0]);
	sort($tab, SORT_REGULAR);
	foreach ($tab as $val)
		echo "$val\n";
}
?>
