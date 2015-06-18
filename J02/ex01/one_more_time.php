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
			else
				exit ("Wrong format\n");
		}
		function found_minute($hms)
		{
			if ($hms <= 59 && $hms >= 0)
				return ($hms);
			else
				exit ("Wrong format\n");
		}
		function valid_month($hms)
		{
			if ($hms == "janvier")
				return (1);
			else if ($hms == "fevrier")
				return (2);
			else if ($hms == "mars")
				return (3);
			else if ($hms == "avril")
				return (4);
			else if ($hms == "mai")
				return (5);
			else if ($hms == "juin")
				return (6);
			else if ($hms == "juillet")
				return (7);
			else if ($hms == "aout")
				return (8);
			else if ($hms == "septembre")
				return (9);
			else if ($hms == "octobre")
				return (10);
			else if ($hms == "novembre")
				return (11);
			else if ($hms == "decembre")
				return (12);
			else
				exit ("Wrong format\n");
		}
		function valid_value($hms, $month)
		{
			if ($month ==1 OR $month ==3 OR $month ==5 OR $month ==7 OR $month == 8 OR $month == 10 OR $month ==12 AND ($hms <= 31 AND $hms >= 0))
				return ($hms);
			else if ($month == 2 AND ($hms >= 0 AND  $hms <= 28))
				return ($hms);
			else if ($month ==4 OR $month ==6 OR $month ==9 OR $month ==11 AND ($hms <= 30 AND $hms >= 0))
				return ($hms);
			else
				exit ("Wrong format\n");
		}
		function foundhour($hms)
		{
			if ($hms <= 23 && $hms >= 0)
				return ($hms);
			else
				exit ("Wrong format\n");
		}
		function valid_year($year)
		{
			if ($year >= 1970)
				return ($year);
			else
				exit ("Wrong format\n");
		}
	if ($argc == 2)
	{
		$str = explode(" ", $argv[1]);
		$day = valid_day(strtolower($str[0]));
		$month = valid_month(strtolower($str[2]));
		$value = valid_value(strtolower($str[1]), $month);
		$year = valid_year($str[3]);
		$hms = explode(":", $str[4]);
		$hour = foundhour($hms[0]);
		$min = found_minute($hms[1]);
		$second = found_minute($hms[2]);
/*		echo $second;
		echo "\n";
		echo $min;
		echo "\n";
		echo $hour;
		echo "\n";
		echo $month;
		echo "\n";
		echo $value;
		echo "\n";
		echo $year;*/
		date_default_timezone_set ("Europe/Paris");
		echo mktime($hour, $min, $second, $month, $value, $year)."\n";
	}
?>
