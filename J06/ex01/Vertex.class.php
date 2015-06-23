<?php
class Vertex
{
	private	$_x = 0;
	private	$_y = 0;
	private	$_z = 0;
	private	$_w = 1.0;
	private	$_color = 0;
	public	static $verbose = FALSE;

	public static function doc()
	{
		return (file_get_contents('Vertex.doc.txt'));
	}
	public function __toString()
	{
		if (self::$verbose === TRUE)
		{
			return (sprintf('Vrtex( x: %.2f, y: %.2f, z: %.2f, w: %.2f,  %s )', $this->_x, $this->_y, $this->_z, $this->_w, $this->_color) );
		}
		else if (self::$verbose === FALSE)
		{
			return (sprintf ('Vertex( x: %.2f, y: %.2f, z: %.2f, w: %.2f, %s)', $this->_x, $this->_y, $this->_z, $this->_w, $this->_color) );
		}
	}

	public function getX()
	{
		return $this->_x;
	}
	public function getY()
	{
		return $this->_y;
	}
	public function getZ()
	{
		return $this->_z;
	}
	public function getW()
	{
		return $this->_w;
	}
	public function getColor()
	{
		return $this->_color;
	}

	public function setX()
	{
		$this->_x = clone $val; 
		return;
	}
	public function setY()
	{
		$this->_y = clone $val; 
		return;
	}
	public function setZ()
	{
		$this->_z = clone $val; 
		return;
	}
	public function setW()
	{
		$this->_w = clone $val; 
		return;
	}
	public function setColor()
	{
		$this->_color = clone $val; 
		return;
	}

	public function __get( $att)
	{
		return ("trying to access".$att);
	}
	public function __set($att, $value)
	{
		return ("trying to set".$att);
	}

	public function __construct(array $args)
	{
		$this->_x = $args['x'];
		$this->_y = $args['y'];
		$this->_z = $args['z'];
		if (array_key_exists('w', $args))
			$this->_w = $args['w'];
		if (array_key_exists('color', $args))
			$this->_color = $args['color'];
		else
			$this->_color = new Color(array('red' => 255, 'green' => 255, 'blue' => 255));
		if (self::$verbose === TRUE)
			echo $this.' constructed'.PHP_EOL;
		return;
	}
}
?>
