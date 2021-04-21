<html>
    <form action="perform.php" method="POST">
        <input type="date" name="date" id="date">
        <button type="submit">Submit</button>
    </form>
</html>

<?php 
if(isset($_POST['date'])){
    $date = strtotime($_POST['date']);
    $day = date('d', $date);
    $month = date('m', $date);
    $year = date('Y', $date);
    $time = mktime(0, 0, 0, $month, $day, $year);
    echo  date("jS F Y", $time) . " is a ". date("l", $time);
}



?>