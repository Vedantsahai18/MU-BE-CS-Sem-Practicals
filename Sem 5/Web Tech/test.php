<html>
<head>
<body>
<form name ="form1" action="" method="post">


<input type="text" name="id" required><br>
username 
<input type="text" name="username"><br>
password 
<input type="password" name="password"><br>
Email
<input type="email" name="email"><br>

<input type = "submit" name= "submit1" value="Insert">
<input type = "submit" name= "submit2" value="Delete">
<input type = "submit" name= "submit3" value="Update">
</body>
</form>


<?php
$ser="localhost";
$user="root";
$pass="";
$db="test";
$con=mysqli_connect("$ser","$user","$pass","$db") or die("connction failed");
if ($con)
echo "connection sucess";

if (isset($_POST["submit1"]))

mysqli_query($con," insert into new_sample values ('$_POST[id]','$_POST[username]','$_POST[password]','$_POST[email]')");

if (isset($_POST["submit2"]))
mysqli_query($con," delete from new_sample where id='$_POST[id]'");


if (isset($_POST["submit3"]))
mysqli_query($con," update from new_sample where id='$_POST[id]'");
?>