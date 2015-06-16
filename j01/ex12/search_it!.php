#!/usr/bin/php
<?php
	if ($argc > 2)
	{
		$tab = $argv;
		$str = $tab[1];
		unset($tab[0]);
		unset($tab[1]);
		foreach ($tab as $val)
		{
			$val = explode(":", $val);
			if ($str == $val[0])
			{
				$res = $val[1];
				$ind = 1;
			}
		}
		if ($ind == 1)
			echo "$res\n";
	}

?>
