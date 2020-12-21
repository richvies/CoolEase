<?php
define('DB_SERVER', 'cooleasedbserver.mysql.database.azure.com:3306');
define('DB_USERNAME', 'benmoylan@cooleasedbserver');
define('DB_PASSWORD', 'CoolEase420');
define('DB_DATABASE', 'cooleasedb');
    function UpdateTemperature() {
    	$db = new mysqli(DB_SERVER, DB_USERNAME, DB_PASSWORD, DB_DATABASE);
        if(isset($_GET['temp'])) {
        	$temp = $_GET['temp'];
            if(mysqli_query($db, "UPDATE fridges SET temperature = ".$temp." WHERE fridge_id = 1")) {
                echo "success";
            } else {
                echo "DB connection error";
            }
        } else {
            echo "temp variable not set";
        }
    }
    UpdateTemperature();
?>