<?php 
function numberTable($num){
    for($i = 1; $i <= 10; $i++){
        echo $num . " * " . $i . " = " . $num * $i . "<br>";
    }
}

function checkPrime($num){
    $sqrnum = intval(sqrt($num));
    for($i = 2; $i <= $sqrnum; $i++){
        if($sqrnum % $i == 0){
            echo "$num is not a prime <br>";
            return;
        }
    }
    echo "$num is a prime <br>";
}

function checkPalin($str){
    if($str == strrev($str)){
        echo "$str is a palindrome <br>";
    }
    else{
        echo "$str is not a palindrome <br>";
    }
}

function factorial($num){
    $ans = 1;
    while($num > 0){
        $ans = $ans * $num;
        $num--;
    }
    echo "Factorial of $num is $ans <br>";
}

function fibo($num){
    $a = 0;
    $b = 1;
    echo "Term 1 is $a <br>";
    echo "Term 2 is $b <br>";
    $a = $b;
    for($i = 3; $i <= $num; $i++){
        echo "Term $i is $b <br>";
        $t = $b;
        $b = $a + $b;
        $a = $t;
    }
}

numberTable(5);
checkPrime(31);
checkPalin("helleh");
checkPalin("ads");
factorial(5);
fibo(10);

?>