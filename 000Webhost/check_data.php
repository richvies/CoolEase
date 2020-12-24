<?php 

    $fp         = fopen('data.csv', 'r');
	$arr        = array();
	$arr[0]     = fgetcsv($fp);
	$arr[1]     = fgetcsv($fp);
	$num_rows   = $arr[1][1];
	$i          = 0;
	for($i = 2; $i < $num_rows; $i++)
	{
	    $arr[$i] = fgetcsv($fp);
	}
	fclose($fp);

    echo json_encode($arr)
?>