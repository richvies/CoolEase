<?php
if ($_SERVER["REQUEST_METHOD"] == "GET" ) 
{
	if(isset($_GET["s"]))
	{
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
	    
	   // Data from Get Request
	    $string         = $_GET["s"];
	    $customer       = intval(substr($string, 0, 8), 16);
	    $string_idx     = 8;
	    
	    // Find customer
	    $found = false;
	    
	   for($i = 2; $i < $num_rows; $i++)
	   {
	       if($arr[$i][0] == $customer)
	       {
	           echo "Found Customer\n";
	           $found = true;
	           break;
	       }
	   }
	   
	   if(!$found)
	   {
	       echo "Customer Not Found\n";
	   }
	   
	   date_default_timezone_set('Europe/London');
	    
	   // Fill array
	    while($string[$string_idx] != 'N')
	    {                               
	        $arr[$i++] = [$customer,    intval(substr($string, $string_idx, 8), 16), \      //Device ID
	                                    intval(substr($string, $string_idx + 8, 4), 16), \  //Temperature
	                                    intval(substr($string, $string_idx + 12, 4), 16), \ //Voltage   
                                        intval(substr($string, $string_idx + 16, 8), 16), \ //Total Packets
                                        intval(substr($string, $string_idx + 24, 8), 16), \ //OK Packets
                                        intval(substr($string, $string_idx + 32, 4), 16), \  //Sig Strength
                                        date('m/d/Y h:i:s a', time())];  //Time
            $string_idx += 36;
            
            if(!$found)
            {
                $num_rows++;
            }
	    }
	    
	    // Resave Array
	    $arr[1]     = ['Num Rows:', $num_rows, 'N/A', 'N/A'];
	    
	    $fp = fopen('data.csv', 'w');
	    
        foreach ($arr as $fields) 
        { 
            fputcsv($fp, $fields); 
        } 
  
        fclose($fp);
        
        echo "Done";
	}
	    
}
?>