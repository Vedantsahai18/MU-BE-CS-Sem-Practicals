PRIME.html

<html>
<head><title> php prime no </title>
</head>
<body>
<form action="request-script.php" method="post">

<h1> Enter the range to find prime numbers </h1>

<input type="text" name="firstno" placeholder="First Number" />

<input type="text" name="secondno" placeholder="Second number" />

<input type="submit" name="submit" />
</form> 
</body>
</html>

REQUEST_SCRIPT.php

<!DOCTYPE HTML>  
<html>
<head>
</head>
<body>  
<?php
if ( isset( $_POST['submit'] ) ) 
{ 
$firstno = $_POST['firstno']; 
$secondno = $_POST['secondno']; 
echo '<br>Your given range  is ' . $firstno . ' --- ' . $secondno . '<br>' ; 
for( $j = $firstno; $j <= $secondno; $j++ )
{
for( $k = 2; $k < $j; $k++ )
{
if( $j % $k == 0 )
{
break;
}

}
if( $k == $j )
echo ' <br> Prime Numbers are ==>  : '. $j; 
}
}
?>
</body>
</html>