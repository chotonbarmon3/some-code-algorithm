<?php
include 'connection.php';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = $conn->real_escape_string($_POST['signupName']);
    $email = $conn->real_escape_string($_POST['signupEmail']);
    $password = $conn->real_escape_string($_POST['signupPassword']);
    $confirmPassword = $conn->real_escape_string($_POST['signupConfirmPassword']);

    if ($password !== $confirmPassword) {
        die("Passwords do not match. Please try again.");
    }

    // Hash the password
    $hashedPassword = password_hash($password, PASSWORD_DEFAULT);

    // Insert into the database
    $sql = "INSERT INTO users (user_name, user_email, user_password) VALUES ('$name', '$email', '$hashedPassword')";
    if ($conn->query($sql) === TRUE) {
        echo "Sign-up successful!";
    } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }
}

$conn->close();
?>
