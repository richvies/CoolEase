<?php
	$arr        = array();
	$arr[0]     = ['Customer ID', 'Device ID', 'Temperature', 'Voltage', 'Total Packets', 'OK Packets', 'Signal Strength', 'Time'];
	$arr[1]     = ['Num Rows:', 2, 'N/A', 'N/A'];
	    
	$fp         = fopen('data.csv', 'w');
	
    foreach ($arr as $fields) 
    { 
        fputcsv($fp, $fields); 
    } 
  
    fclose($fp);
        
    echo "Data Wiped";
?>