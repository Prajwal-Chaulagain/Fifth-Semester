<?php include "Database.php" ?>
<?php
if($_SERVER["REQUEST_METHOD"] == "POST"){
    $name = $_POST["sname"];
    $address = $_POST["saddress"];
    $email = $_POST["semail"];
    $sql = "INSERT INTO student(name,address,email)
    VALUES('". $name . "','" . $address ."','" . $email . "')";
    if($conn->query($sql) === TRUE){
        echo "Data inserted successfully<br>";
    }else{
        echo "No data are saved in table instantly<br>";
} 
} else{
    echo "GET Data are not retrieved<br>";
}  
?>