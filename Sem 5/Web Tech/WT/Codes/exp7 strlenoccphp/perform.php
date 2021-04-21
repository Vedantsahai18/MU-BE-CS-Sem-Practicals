<?php 
function perform($str){
    $wordArr = explode(" ", $str);

    $lenStr = 0;
    $longStr = "";
    foreach($wordArr as $word){
        if(strlen($word) > $lenStr){
            $longStr = $word;
            $lenStr = strlen($word);
        }
    }

    $occTimes = 0;
    $occStr = "";
    foreach(array_count_values($wordArr) as $word => $value){
        if($value > $occTimes){
            $occStr = $word;
            $occTimes = $value;
        }
    }
    echo "$occStr $longStr <br>";
}

perform("Thank you for your comment and your participation.");

?>