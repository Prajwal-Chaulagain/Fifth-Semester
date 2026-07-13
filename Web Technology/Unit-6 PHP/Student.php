<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>PHP Form Handling</title>
</head>

<body>
    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $name = $_POST["sname"];
        $address = $_POST["saddress"];
        $dob = $_POST["sdob"];
        $email = $_POST["semail"];
    }
    ?>
    <h2>The Students Information is:</h2>
    <table border="2px">
        <tr>
            <th>Name</th>
            <th>Address</th>
            <th>Age</th>
            <th>Email</th>
        </tr>
        <tr>
            <td><?= $name ?></td> <!-- expression Tag-->
            <td><?= $address ?></td>
            <td><?= $dob ?></td>
            <td><?= $email ?></td>
        </tr>
    </table>
</body>

</html>