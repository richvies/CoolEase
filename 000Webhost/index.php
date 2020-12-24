<!DOCTYPE html>
<html>
<head>
<title>Test Site 1</title>
<script src="https://code.jquery.com/jquery-3.4.1.js"></script>

</head>
    
<body>
    <h1>CoolEase Test Site</h1>
    <table border="1" id="table1">
    <tr>
        <th>Customer ID</th>
        <th>Sensor ID</th>
        <th>Temperature</th>
        <th>Battery</th>
        <th>Total Packets</th>
        <th>OK Packets</th>
        <th>Accuracy</th>
        <th>Signal Strength</th>
        <th>Time</th>
    </tr>
    </table>
    <script>
    update();
    setInterval(update, 1000);
    function update() {
        $.ajax({
            url: 'check_data.php',
            dataType: 'json',
            encode: true,
            success: function(data) 
            {
                var table = document.getElementById("table1");
                table.innerHTML = ""
                
                var row = table.insertRow();
                var cell1 = row.insertCell(0);
                var cell2 = row.insertCell(1);
                var cell3 = row.insertCell(2);
                var cell4 = row.insertCell(3);
                var cell5 = row.insertCell(4);
                var cell6 = row.insertCell(5);
                var cell7 = row.insertCell(6);
                var cell8 = row.insertCell(7);
                var cell9 = row.insertCell(8);
                
                cell1.innerHTML = "Customer ID";
                cell2.innerHTML = "Sensor ID";
                cell3.innerHTML = "Temperature";
                cell4.innerHTML = "Battery";
                cell5.innerHTML = "Total Packets";
                cell6.innerHTML = "OK Packets";
                cell7.innerHTML = "Accuracy";
                cell8.innerHTML = "Signal Strength";
                cell9.innerHTML = "Time";
                
                var num_rows = data[1][1];
                for(var i = 2; i < num_rows; i++)
                {
                    if(data[i][2] > 32767)
                    {
                        data[i][2] = data[i][2] - 65536;
                    }
                    
                    if(data[i][6] > 32767)
                    {
                        data[i][6] = data[i][6] - 65536;
                    }
                    
                    var row = table.insertRow();
                    var cell1 = row.insertCell(0);
                    var cell2 = row.insertCell(1);
                    var cell3 = row.insertCell(2);
                    var cell4 = row.insertCell(3);
                    var cell5 = row.insertCell(4);
                    var cell6 = row.insertCell(5);
                    var cell7 = row.insertCell(6);
                    var cell8 = row.insertCell(7);
                    var cell9 = row.insertCell(8);
                    
                    cell1.innerHTML = data[i][0];
                    cell2.innerHTML = data[i][1];
                    cell3.innerHTML = data[i][2]/100 + ' &#176;C';
                    cell4.innerHTML = data[i][3]/100 + ' V';
                    cell5.innerHTML = data[i][4];
                    cell6.innerHTML = data[i][5];
                    cell7.innerHTML = 100 * data[i][5] / data[i][4] + '%';
                    cell8.innerHTML = data[i][6] + ' dbm';
                    cell9.innerHTML = data[i][7]
                }
            }
        })
    }
    </script>
</body>
</html>