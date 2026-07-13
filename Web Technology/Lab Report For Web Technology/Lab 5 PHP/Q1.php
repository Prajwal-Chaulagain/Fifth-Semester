<!-- Write a program to implement CRUD operations using PHP.-->
 <?php
// Database connection
$conn = new mysqli("localhost", "root", "", "crud_app");

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// CREATE
if (isset($_POST['add'])) {
    $name = $_POST['name'];
    $email = $_POST['email'];

    $stmt = $conn->prepare("INSERT INTO users (name, email) VALUES (?, ?)");
    $stmt->bind_param("ss", $name, $email);
    $stmt->execute();
    header("Location: Q1.php");
}

// DELETE
if (isset($_GET['delete'])) {
    $id = $_GET['delete'];

    $stmt = $conn->prepare("DELETE FROM users WHERE id=?");
    $stmt->bind_param("i", $id);
    $stmt->execute();
    header("Location: Q1.php");
}

// UPDATE (fetch existing data)
$editData = null;
if (isset($_GET['edit'])) {
    $id = $_GET['edit'];
    $result = $conn->query("SELECT * FROM users WHERE id=$id");
    $editData = $result->fetch_assoc();
}

// UPDATE (save changes)
if (isset($_POST['update'])) {
    $id = $_POST['id'];
    $name = $_POST['name'];
    $email = $_POST['email'];

    $stmt = $conn->prepare("UPDATE users SET name=?, email=? WHERE id=?");
    $stmt->bind_param("ssi", $name, $email, $id);
    $stmt->execute();
    header("Location: Q1.php");
}
?>

<!DOCTYPE html>
<html>

<head>
    <title>PHP CRUD</title>
</head>

<body>
    <h1>Name:Prajwal Chaulagain</h1>
    <h1>Symbol No.:80010773</h1>

    <h2><?php echo $editData ? "Update User" : "Add User"; ?></h2>

    <form method="POST">
        <input type="hidden" name="id" value="<?php echo $editData['id'] ?? ''; ?>">

        Name: <input type="text" name="name" required value="<?php echo $editData['name'] ?? ''; ?>"><br><br>

        Email: <input type="email" name="email" required value="<?php echo $editData['email'] ?? ''; ?>"><br><br>

        <?php if ($editData): ?>
            <button type="submit" name="update">Update</button>
        <?php else: ?>
            <button type="submit" name="add">Add</button>
        <?php endif; ?>
    </form>

    <hr>

    <h2>User List</h2>

    <table border="1" cellpadding="10">
        <tr>
            <th>ID</th>
            <th>Name</th>
            <th>Email</th>
            <th>Action</th>
        </tr>

        <?php
        $result = $conn->query("SELECT * FROM users");

        while ($row = $result->fetch_assoc()):
            ?>
            <tr>
                <td><?php echo $row['id']; ?></td>
                <td><?php echo $row['name']; ?></td>
                <td><?php echo $row['email']; ?></td>
                <td>
                    <a href="Q1.php?edit=<?php echo $row['id']; ?>">Edit</a> |
                    <a href="Q1.php?delete=<?php echo $row['id']; ?>"
                        onclick="return confirm('Delete this record?')">Delete</a>
                </td>
            </tr>
        <?php endwhile; ?>

    </table>

</body>

</html>