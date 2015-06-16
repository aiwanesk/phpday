#!/usr/bin/php
<?PHP
		function valid_day($str)
		{
			if ($str == "lundi")
				return (1);
			else if ($str == "mardi")
				return (2);
			else if ($str == "mercredi")
				return (3);
			else if ($str == "jeudi")
				return (4);
			else if ($str == "vendredi")
				return (5);
			else if ($str == "samedi")
				return (6);
			else if ($str == "dimanche")
				return (7);
//			else
//				exit ("error");
		}
		function found_minute($hms)
		{
			if ($hms <= 59 && $hms >= 0)
				return ($hms);
//			else
//				exit ("error");
		}
		function valid_month($hms)
		{
			if ($str == "janvier")
				return (1);
			else if ($str == "fevrier")
				return (2);
			else if ($str == "mars")
				return (3);
			else if ($str == "avril")
				return (4);
			else if ($str == "mai")
				return (5);
			else if ($str == "juin")
				return (6);
			else if ($str == "juillet")
				return (7);
			else if ($str == "aout")
				return (8);
			else if ($str == "septembre")
				return (9);
			else if ($str == "octobre")
				return (10);
			else if ($str == "novembre")
				return (11);
			else if ($str == "decembre")
				return (12);
//			else
//				exit ("error");
		}
		function valid_value($hms, $month)
		{
			if ($month ==1 OR $month ==3 OR $month ==5 OR $month ==7 OR $month == 8 OR $month == 10 OR $month ==12 AND ($hms <= 31 AND $hms >= 0))
				return ($hms);
			else if ($month == 2 AND ($hms >= 0 AND  $hms <= 28))
				return ($hms);
			else if ($month ==4 OR $month ==6 OR $month ==9 OR $month ==11 AND ($hms <= 30 AND $hms >= 0))
				return ($hms);
//			else
//				exit ("error");
		}
		function foundhour($hms)
		{
			if ($hms <= 23 && $hms >= 0)
				return ($hms);
//			else
//				exit ("error");
		}
		function valid_year($hms)
		{
			if ($hms >= 1 AND $hms <= 12)
				return($hms);
//			else
//				exit("error");
		}
	if ($argc == 2)
	{
		$str = explode(" ", $argv[1]);
		$day = valid_day(strtolower($str[0]));
		$month = valid_month(strtolower($str[2]));
		$value = valid_value(strtolower($str[1]), $month);
		$year = valid_year($str[3]); //> 1970
		$hms = explode(":", $str[4]);
		$hour = foundhour($hms[0]);
		$min = found_minute($hms[1]);
		$second = found_minute($hms[2]);
		echo $second."\n";
		echo $min."\n";
		echo $hour."\n";
		echo $day."\n";
		echo $value."\n";
		echo $year."\n";
		echo mktime ($hour, $min, $second, $month, $value, $year);
	}
?>

//explode la string
//function search day en effectuant un tolower
//funtion search day <= 31 >0
//search month tolower
//split le reste avec :
//value >=00 et < 24
//value >= 00 et <60
//pareil qu au dessus
