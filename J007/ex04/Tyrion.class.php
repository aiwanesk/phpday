<?php

Class Tyrion extends Lannister
{
	public function sleepWith( $name )
	{
		if ( $name instanceof Cersei )
		{
			print( $this->noty() . PHP_EOL );
		}
		else if ( $name instanceof Jaime )
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
