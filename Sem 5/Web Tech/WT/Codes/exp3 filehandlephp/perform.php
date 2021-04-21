<?php 
$str = "I am writing a line\n";
$str1 = "And another line\n";


echo "---Creating and Writing--- <br>";
$file = fopen("hello.txt", "w");
fwrite($file, $str);
fclose($file);

echo "---Appending--- <br>";
$file = fopen("hello.txt", "a");
fwrite($file, $str1);
fclose($file);

echo "---Reading--- <br>";
$file = fopen("hello.txt", "r");
echo fread($file, filesize("hello.txt"));
fclose($file);

echo "<br> ---Deleting--- <br>";
unlink("hello.txt");
?>