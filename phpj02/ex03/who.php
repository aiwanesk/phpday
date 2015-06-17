#!/usr/bin/php
<?
date_default_timezone_set('CET');
$fd = fopen("/var/run/utmpx", "r");
while ($utmpx = fread($fd, 628))
{
	$utmpx_open = unpack("a256user/a4id/a32line/ipid/itype/I2time/a256host/i16pad", $utmpx);
	if ($utmpx_open["type"] == 7)
	{
		$user[$utmpx_open["line"]] = array("user" => $utmpx_open["user"],"time" => $utmpx_open["time1"]);
	}
}
ksort($user);
foreach($user as $line => $data)
{
		printf("% -7s % -7s  %s \n", $data["user"], $line, date("M  j H:i", $data["time"]));
}
?>
