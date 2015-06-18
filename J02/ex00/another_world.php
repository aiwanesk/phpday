#!/usr/bin/php
<?PHP
if ($argc == 2)
{
	$string = Preg_replace("/\s+/"," ", $argv[1]);
	$string = trim($string);
	echo $string."\n";
}
?>
