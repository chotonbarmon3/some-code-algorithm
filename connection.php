<?php
// Database configuration
$servername = "localhost";  // Host name
$username = "root";         // Database username
$password = "";             // Database password
$dbname = "db";          // Your database name

// Create a connection using MySQLi
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection and handle errors
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

?>
