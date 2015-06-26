<?PHP

class NightsWatch implements IFighter
{
	private		$_go;

	public function __construct()
	{
		$this->_go = array();
	}

	public function recruit($everyone)
	{
		if (isset(class_implements($everyone)['IFighter']))
			$this->_go[] = $everyone;
	}

	public function fight()
	{
		foreach($this->_go as $everyone)
		{
			$everyone->fight();
		}
	}
}

?>
