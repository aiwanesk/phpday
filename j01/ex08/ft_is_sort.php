<?PHP
	function ft_is_sort($tab)
	{
		$stab = $tab;
		$rtab = $tab;
		sort($tab, SORT_REGULAR);
		rsort($tab, SORT_REGULAR);
		if ($tab == $stab || $tab = $rtab)
			echo "Le tableau est trie\n";
		else
			echo "Le tableau n'est pas trie\n";
	}
?>
