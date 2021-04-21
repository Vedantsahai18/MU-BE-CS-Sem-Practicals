<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Home</title>
    <style type="text/css">
        body {
            padding: 0;
            margin: 0;
        }
        .homepage {
            display: flex;
            padding: 0px;
            margin: 0px;
            height: 100px;
            background-color: purple;
            color: white;
            align-items: center;
            justify-content: center;
            text-align: center;
        }
        .container {
            display: flex; 
            justify-content:center;
        }
        .person {
            margin-top: 20px;
            margin-right: 100px;
        }
    
    </style>
</head>
<body>
<?php
$json = array();
$jsonfile = file_get_contents("people.json");
$json = json_decode($jsonfile, true);


foreach($json as $item) { //foreach element in $arr
    
    $img1 =  $item[0]['imgSrc'];
    $img2 =  $item[1]['imgSrc'];
    $img3 =  $item[2]['imgSrc'];
        
}
    


?>
    <header class="homepage">
        <h1>Homepage</h1>
    </header>
    <div class="container">
        <div class="person">
            <img src="<?php echo $img3 ?>" alt="person1">
            <h2>Person One</h2>
            <a href="people.php?id=1">View profile</a>
        </div>
        <div class="person">
            <img src="<?php echo $img3 ?>" alt="person2">
            <h2>Person Two</h2>
            <a href="people.php?id=2">View profile</a>
        </div>
        <div class="person">
            <img src="<?php echo $img3 ?>" alt="person3">
            <h2>Person Three</h2>
            <a href="people.php?id=3">View profile</a>
        </div>

    </div>
</body>
</html>