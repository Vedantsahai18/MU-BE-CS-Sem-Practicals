<?php 
function getUserIpAddr(){
    if(!empty($_SERVER['HTTP_CLIENT_IP'])){
        //ip from share internet
        $ip = $_SERVER['HTTP_CLIENT_IP'];
    }elseif(!empty($_SERVER['HTTP_X_FORWARDED_FOR'])){
        //ip pass from proxy
        $ip = $_SERVER['HTTP_X_FORWARDED_FOR'];
    }else{
        $ip = $_SERVER['REMOTE_ADDR'];
    }
    return $ip;
}

function getBrowser(){
    if(strpos($_SERVER['HTTP_USER_AGENT'], 'Trident') !== FALSE) //For Supporting IE 11
        echo 'Internet explorer';
    elseif(strpos($_SERVER['HTTP_USER_AGENT'], 'Edge') !== FALSE)
        echo 'Edge';
    elseif(strpos($_SERVER['HTTP_USER_AGENT'], 'Firefox') !== FALSE)
        echo 'Mozilla Firefox';
    elseif(strpos($_SERVER['HTTP_USER_AGENT'], 'Chrome') !== FALSE)
        echo 'Google Chrome';
    elseif(strpos($_SERVER['HTTP_USER_AGENT'], 'Opera Mini') !== FALSE)
        echo "Opera Mini";
    elseif(strpos($_SERVER['HTTP_USER_AGENT'], 'Opera') !== FALSE)
        echo "Opera";
    elseif(strpos($_SERVER['HTTP_USER_AGENT'], 'Safari') !== FALSE)
        echo "Safari";
    else
        echo 'Something else';
}

function email_validation($str) { 
    $email = filter_var($str, FILTER_SANITIZE_EMAIL); 
  
    // Validate Email 
    if (filter_var($email, FILTER_VALIDATE_EMAIL)) { 
        echo("$email is a valid email address"); 
    }  
    else { 
        echo("$email is not a valid email address"); 
    } 
} 

echo $_SERVER['HTTP_USER_AGENT'] . "<br>";
echo "User Real IP: " . getUserIpAddr() . "<br>";
getBrowser();
echo "<br>";
email_validation("something@somehow.com");
echo "<br>";
echo show_source("perform.php") . "<br>";
?>