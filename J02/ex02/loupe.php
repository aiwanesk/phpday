#!/usr/bin/php
<?php
function upper($str)
{
	$dst = strtoupper($str[0]);
	return ($dst);
}

function rep_between_balise($subject)
{
	$pattern = '/>[^<]+</';
	$ret = preg_replace_callback($pattern, "rep_up", $subject[0]);
	return ($ret);
}

function rep_up($subject)
{
	$pattern = '/.*/';
	$ret = preg_replace_callback($pattern, "upper", $subject[0]);
	return($ret);
}

function rep_in_title($subject)
{
	$pattern = "/\".*\"/";
	$ret = preg_replace_callback($pattern, "upper", $subject[0]);
	return ($ret);
}

function rep_title($subject)
{
	$pattern = "/title=\"[^\"]+\"/";
	$ret = preg_replace_callback($pattern, "rep_in_title", $subject[0]);
	return ($ret);
}

if ($argc == 2)
{
	$tmp = file_get_contents($argv[1]);
	$pat_a = "/<a .*>.*a>/";

	$ptt = explode(PHP_EOL, $tmp);
	$page = implode("#####", $ptt);
	$ret = preg_replace_callback($pat_a, "rep_between_balise", $page);
	/*modif pour le title*/
	$end = preg_replace_callback($pat_a, "rep_title", $ret);
	/*modif pour le title*/
	$end = str_replace("#####", "\n", $end);
	echo ($end);
}
?>
