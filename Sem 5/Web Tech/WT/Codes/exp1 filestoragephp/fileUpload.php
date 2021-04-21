<?php 

$uploadPath = getcwd() . "/uploads/";

if(isset($_POST) && ($_FILES)){
    $email = $_POST['email'];
    $phone = $_POST['phone'];
    $fileName = $_FILES['myFile']['name'];
    $tmpName = $_FILES['myFile']['tmp_name'];
    $uploadPath = $uploadPath . $fileName;
    if(file_exists($uploadPath)){
        echo "File already exists!";
    }
    else{
        echo "Email: " . $email . "<br>";
        echo "Phone: " . $phone . "<br>";
        move_uploaded_file($tmpName, $uploadPath);
        echo "File saved at " . $uploadPath;
    }
}

?>