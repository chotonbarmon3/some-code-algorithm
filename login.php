<?php
session_start();
include 'connection.php'; // Include the database connection file

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Retrieve and sanitize inputs
    $email = $conn->real_escape_string($_POST['email']);
    $password = $conn->real_escape_string($_POST['password']);

    // Query to find the user by email
    $sql = "SELECT * FROM users WHERE user_email = '$email'";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
        $user = $result->fetch_assoc();

        // Verify the password
        if (password_verify($password, $user['user_password'])) {
            // Set session variables
            $_SESSION['user_name'] = $user['user_name'];
            $_SESSION['user_email'] = $user['user_email'];

            // Redirect to dashboard or home page
            header("Location: index.html");
            exit();
        } else {
            // Invalid password
            header("Location: index.html");
            exit();
          //  echo "Invalid email or password. Please try again.";
        }
    } else {
        // User not found
        echo "user not found";
    }
}

$conn->close(); // Close the database connection
?>
