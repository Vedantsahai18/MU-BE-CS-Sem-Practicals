<?php/*
* Check if the 'id' GET variable is set
* Example - http://localhost/?id=1
*/
if (isset($_GET['id'])){
$id = $_GET['id'];

/* Setup the connection to the database */
$mysqli = new mysqli('localhost', 'dbuser', 'dbpasswd', 'sql_injection_example');

/* Check connection before executing the SQL query */
if ($mysqli->connect_errno) {
printf("Connect failed: %s\n", $mysqli->connect_error);
exit();
}

/* SQL query vulnerable to SQL injection */
$sql = "SELECT username
FROM users
WHERE id = $id";

/* Select queries return a result */
if ($result = $mysqli->query($sql)) {
while($obj = $result->fetch_object()){
print($obj->username);
}
}
/* If the database returns an error, print it to screen */
elseif($mysqli->error){
print($mysqli->error);
}
}