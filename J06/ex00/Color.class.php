<?php
class Color
{
	public		$red = 0;
	public		$green = 0;
	public		$blue = 0;
	public static $verbose = FALSE;

	public static function doc()
	{
		echo "\n";
		return (file_get_contents('Color.doc.txt'));
	}

	public function __toString()
	{
		return (sprintf ('Color( red: % 3d, green: % 3d, blue: % 3d )', $this->red, $this->green, $this->blue) ) ;
	}

	public function __get($att)
	{
		return ("trying to access".$att.PHP_EOL);
	}

	public function __set( $att, $value )
	{
		return "trying to set '$att' at ".$value.PHP_EOL;
	}

	public function __construct(array $args)
	{
		$this->verif($args);
		if (self::$verbose === TRUE)
			echo $this.' constructed.'.PHP_EOL;
		return ;
	}

	public function __destruct()
	{
		if (self::$verbose === TRUE)
			echo $this.' destructed.'.PHP_EOL;
		return ;
	}

	public function validity ($int)
	{
		if ($int >= 0 && $int <= 255)
		{
			return $int;
		}
	}

	public function verif(array $args)
	{
		if ((array_key_exists('red', $args)) && $this->validity($args['red']))
		{
			$this->red = intval($args['red']);
		}
		if ((array_key_exists('green', $args)) && $this->validity($args['green']))
		{
			$this->green = intval($args['green']);
		}
		if ((array_key_exists('blue', $args)) && $this->validity($args['blue']))
		{
			$this->blue = intval($args['blue']);
		}
		if (array_key_exists('rgb', $args))
		{
			$this->red = intval($args['rgb'] >> 16);
			$this->green = intval($args['rgb'] >> 8 & 0xff);
			$this->blue = intval($args)['rgb'] & 0xff;
		}
	}

	public function add(Color $var)
	{
		$red = $this->red + $var->red;
		$green = $this->green + $var->green;
		$blue = $this->blue + $var->blue;
		return (new Color(array('red' => $red, 'green' => $green, 'blue' => $blue)));
	}

	public function sub(Color $var)
	{
		$red = $this->red - $var->red;
		$green = $this->greenn - $var->green;
		$blue = $this->blue - $var->blue;
		return (new Color(array('red' => $red, 'green' => $green, 'blue' => $blue)));
	}

	public function mult($var)
	{
		$red = $this->red * $var;
		$green = $this->green * $var;
		$blue = $this->blue * $var;
		return (new Color (array('red' => $red, 'green' => $green, 'blue' => $blue)));
	}
}
?>
