<?PHP
function ft_split($str)
{
	$tab = explode (" ", $str);
	$tab = array_filter($tab);
	sort($tab, SORT_NATURAL);
	return ($tab);
}
?>