<?php 
require_once "config.php";
if(isset($_POST)){
    $old = $_POST['old'];
    $new = $_POST['new'];
    $field = $_POST['choice'];
    echo $old . "<br>" . $new . "<br>" . $field . "<br>";

    $sql = "UPDATE `person_info` SET `$field` = '$new' WHERE `$field` = '$old';";

    if($conn->query($sql) === TRUE){
        echo "Data successfully updated";    
    }
    else{
        echo "Error while updating table. <br>" . $conn->error;
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