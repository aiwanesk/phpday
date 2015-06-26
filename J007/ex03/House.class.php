<?PHP

Abstract Class House
{
	Abstract public function getHouseName();
	Abstract public function getHouseSeat();
	Abstract public function getHouseMotto();

	public function introduce()
	{
		echo "House".$this->getHouseName()." of ".$this->getHouseSeat.": \"".$this->getHouseMotto()."\"".PHP_EOL;
	}
}
?>
