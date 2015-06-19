<?php

if ($_GET['todo'] == "set")
	setcookie($_GET['todo'], $_GET['value'], time() + 60 * 60 * 24 * 30);
else if ($_GET['todo'] == "get")
{
	$tmp = $_COOKIE[$_GET['todo']];
	if ($tmp)
		echo $tmp."\n";
}
else if ($_GET['todo'] == "del")
	setcookie($_GET['todo'], "", time() - 1 );
?>
