<?php

Class UnholyFactory {

	private $_classes;

	public function __construct() 
	{
		$this->_classes = array();
	}

	public function absorb($soldier) 
	{
		$valid = 0;
		if (get_parent_class($soldier) == "Fighter")
		{
			foreach ($this->_classes as $k => $v)
			{
				if ($v == get_class($soldier))
				{
					$valid = 1;
					break;
				}
			}
			if ($valid)
				print("(Factory already absorbed a fighter of type ".$soldier->class.")\n");
			else
			{
				$this->_classes[$soldier->class] = get_class($soldier);
				print("(Factory absorbed a fighter of type ".$soldier->class.")\n");
			}
		}
		else
			print("(Factory can't absorb this, it's not a fighter)\n");
	}

	public function fabricate($soldier) 
	{
		if (array_key_exists($soldier, $this->_classes))
		{
			$tmp = new $this->_classes[$soldier];
			$this->_classes[] = $tmp;
			print("(Factory fabricates a fighter of type $soldier)\n");
			return ($tmp);
		}
		print("(Factory hasn't absorbed any fighter of type $soldier)\n");
		return (null);
	}
}

?>
