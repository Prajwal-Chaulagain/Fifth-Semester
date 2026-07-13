<?php include "Database.php" ?>
<?php

$sql = "UPDATE student SET name='Prajwal' WHERE name='Prajwal Chhaulagain'";
if ($conn->query($sql) === TRUE) {
    echo "Data inserted successfully<br>";
} else {
    echo "No data are saved in table instantly<br>";
}
?>
<?php
$read = "SELECT * FROM student";
$result = $conn->query($read);

if ($result->num_rows > 0) {
?>
<table border="1">
    <th>Id</th>
    <th>Name</th>
    <th>Address</th>
    <th>Email</th>
    <?php
    while ($row = $result->fetch_assoc()) {
        ?>
        <tr>
            <td><?= $row["id"]?></td>
            <td><?= $row["name"] ?></td>
            <td><?= $row["address"] ?></td>
            <td><?= $row["email"] ?></td>
        </tr>
        <?php
    }
    ?>
</table>
<?php
} else {
    echo "0 result";
}
$conn->close();
?>