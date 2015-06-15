#!/usr/bin/php
<?PHP
if ($argc == 2)
{
	$tab = explode(" ", $argv[1]);
	$tab = array_filter($tab);
	$nbr = count($tab);
	foreach($tab as $val)
	{
		echo $val;
		if ($nbr != 1)
			echo " ";
		$nbr--;
	}
	echo "\n";
}
?>
