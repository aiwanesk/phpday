<?php

Class Jaime extends Lannister
{
	public function sleepWith( $name )
	{
		if ( $name instanceof Cersei )
		{
			print( $this->inceste() . PHP_EOL );
		}
		else if ( $name instanceof Tyrion )
		{
			print( $this->noty() . PHP_EOL );
		}
		else if ( $name instanceof Sansa )
		{
			print( $this->well() . PHP_EOL );
		}
	}

}

?>
