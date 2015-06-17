#!/usr/bin/php
<?PHP
	function upper($match)
	{
		return (strtoupper($match[0]));
	}
	function lower($match)
	{
		return (strtolower($match[0]));
	}
		if ($argc == 2)
	{
		if (($data = file_get_contents($argv[1])) === FALSE)
			return (0);
		$new_data = preg_replace_callback("/<a.*([^>])(?=<)/", 'upper', $data);
		$new_data = preg_replace_callback("/[^<]*(?=>)/", 'lower', $new_data);
		$new_data = preg_replace_callback("/((?<=title=\")(^\")+)(?=\")/",'upper', $new_data);
		echo $new_data;
	}
?>
