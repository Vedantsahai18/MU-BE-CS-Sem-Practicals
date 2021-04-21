<?php 
require_once "config.php";
if(isset($_POST)){
    $del = $_POST['del'];
    $field = $_POST['choice'];
    echo $del . "<br>" . $field . "<br>";

    $sql = "DELETE FROM `person_info` WHERE `$field` = '$del';";

    if($conn->query($sql) === TRUE){
        echo "Data successfully deleted";    
    }
    else{
        echo "Error while deleting from table. <br>" . $conn->error;
    }
}
else{
    echo "Error occured while receiving data";
}
$conn->close();

?>

<html>
    <button><a href="index.php">Home</a></button>
</html>