<?php 
require_once "config.php";

if(isset($_POST)){
    $name = $_POST['name'];
    $dob = $_POST['dob'];
    $contact = $_POST['phone'];
    $email = $_POST['email'];
    echo $name . "<br>" . $dob . "<br>" . $contact . "<br>" . $email . "<br>";

    $sql = "INSERT INTO `person_info`(`name`, `dob`, `contact`, `email`) VALUES ('$name', '$dob', '$contact', '$email');";

    if($conn->query($sql) === TRUE){
        echo "Data successfully entered";    
    }
    else{
        echo "Error while inserting into table. <br>" . $conn->error;
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
