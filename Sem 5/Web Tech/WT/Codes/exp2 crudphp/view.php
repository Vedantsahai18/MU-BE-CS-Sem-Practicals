<?php 
require_once "config.php";

$sql = "SELECT * FROM `person_info`";

$result = $conn->query($sql);

if($result->num_rows === 0){
    echo "No Data Available";
}
else{
    while($row = $result->fetch_assoc()){
        echo "Name: " . $row['name'] . " DOB: " . $row['dob'] . " Contact: " . $row["contact"] . " Email: " . $row["email"] . "<br>";
    }
}

$conn->close();

?>

<html>
    <button><a href="index.php">Home</a></button>
</html>