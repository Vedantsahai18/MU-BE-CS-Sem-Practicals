<html>
<head>
<body>
<form name ="form1" action="test.php" method="post">

id 
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
<input type = "submit" name= "submit4" value="View">
</body>
</form>


<?php
$ser="localhost";
$user="root";
$pass="";
$db="cruddb";
$con=mysqli_connect("$ser","$user","$pass","$db") or die("connction failed");
if ($con)
echo "connection sucess";

if (isset($_POST["submit1"]))
mysqli_query($con,"INSERT into person_info values('$_POST[email]','$_POST[password]','$_POST[id]','$_POST[username]')");

if (isset($_POST["submit2"])){
    if(mysqli_query($con,"DELETE FROM person_info WHERE id='$_POST[id]'")===TRUE)
        echo "Data successfully deleted";
}

if (isset($_POST["submit3"])){
if(mysqli_query($con,"UPDATE FROM person_info WHERE id='$_POST[id]'")===TRUE)
    echo "Data successfully update";
}

if (isset($_POST["submit4"]))
{
$result=mysqli_query($con,"SELECT * FROM person_info  WHERE id='$_POST[id]'");
if($result->num_rows === 0){
    echo "No Data Available";
}
else{
    while($row = $result->fetch_assoc()){
        echo "<br>ID : " . $row['id'] . " <br> Username : " . $row['username'] . " <br> Email : " . $row['email'] . " <br> Password : " . $row['password'] . "<br>";
    }
}
}
?>