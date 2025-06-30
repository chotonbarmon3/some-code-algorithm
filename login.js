// Simulated user database
const users = [];

// Show sign-up page
function showSignUp() {
    document.getElementById('signUpPage').classList.remove('hidden');
    document.getElementById('loginPage').classList.add('hidden');
}

// Show login page
function showLogin() {
    document.getElementById('loginPage').classList.remove('hidden');
    document.getElementById('signUpPage').classList.add('hidden');
}

function signUp() {
    const name = document.getElementById('signupName').value.trim(); // Get name
    const email = document.getElementById('signupEmail').value.trim();
    const password = document.getElementById('signupPassword').value;
    const confirmPassword = document.getElementById('signupConfirmPassword').value;

    // Validate all fields are filled
    if (!name || !email || !password || !confirmPassword) {
        alert("Please fill in all fields!");
        return;
    }

    // Validate name (example: must be at least 3 characters)
    if (name.length < 3) {
        alert("Name must be at least 3 characters long!");
        return;
    }

    // Validate password matching
    if (password !== confirmPassword) {
        alert("Passwords do not match!");
        return;
    }

    // Check if email is already registered
    if (users.some(user => user.email === email)) {
        alert("This email is already registered!");
        return;
    }

    // Save user information
    users.push({ name, email, password }); // Add name to the user object
    alert(`Sign-up successful! Welcome, ${name}. You can now log in.`);
    showLogin(); // Redirect to login
}

// Log in a user
function login() {
    const email = document.getElementById('email').value.trim();
    const password = document.getElementById('password').value;

    const user = users.find(user => user.email === email && user.password === password);
    if (user) {
        alert("Login successful!");
        // Redirect to another webpage after successful login
        window.location.href = "dashboard.html"; // Replace with your target URL or path
    } else {
        alert("Invalid email or password!");
    }
}


