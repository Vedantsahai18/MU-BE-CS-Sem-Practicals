<?php
$id = $_SERVER['QUERY_STRING'];

parse_str($_SERVER["QUERY_STRING"]);
parse_str($_SERVER["QUERY_STRING"], $query_array);

$id = $query_array["id"];
echo $id . '<br>';

$json = file_get_contents("people.json");
$json = json_decode($json, true);



foreach($json as $item) { //foreach element in $arr
    
    echo $item[$id-1]['firstname'] . '<br>';
    echo $item[$id-1]['lastname'] . '<br>'; 
        
}
?>

