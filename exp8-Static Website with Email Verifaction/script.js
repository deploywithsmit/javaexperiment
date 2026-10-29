function showMessage() {
    const message = document.getElementById("message");
    message.textContent = "Thank you for clicking! Enjoy browsing  ";
}

function validateEmail() {
    const emailInput = document.getElementById("email");
    const email = emailInput.value;

    if (email.indexOf("@") === -1 || email.indexOf(".") === -1) {
        alert("Invalid email address. Please include '@' and '.' characters.");
        emailInput.focus();
        return false;
    }
    alert("Email is valid!");
    return true;
}