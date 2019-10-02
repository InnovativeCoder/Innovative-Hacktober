firebase.auth().onAuthStateChanged(function(user) {
  if (user) {
    // User is signed in.
    document.getElementById("login_btn").style.display = "none";
    document.getElementById("logout_btn").style.display = "block";
    document.getElementById("sign_up").style.display = "none";

    var user = firebase.auth().currentUser;
      var email = user.email;
      document.getElementById("navbarDropdown").innerHTML = "Welcome" +'<br> ' + email;

    document.getElementById("Complaint_submission").style.display = "block";
   document.getElementById("Complaint").style.display = "block";

  }
   else {
    // No user is signed in.
    document.getElementById("login_btn").style.display = "block";
    document.getElementById("logout_btn").style.display = "none";
    document.getElementById("sign_up").style.display = "block";
    document.getElementById("navbarDropdown").innerHTML = "Login";
    document.getElementById("Complaint_submission").style.display = "none";
    document.getElementById("Complaint").innerHTML = "<center><b>Please return to Home page</b></center>";
  }
});

function login(){
  var user_email= document.getElementById("login_email").value;
  var user_psw = document.getElementById("login_password").value;
  var login_popup = document.getElementById("id01");
  login_popup.style.display = "none";

  firebase.auth().signInWithEmailAndPassword(user_email, user_psw).catch(function(error) {
  // Handle Errors here.
  var errorCode = error.code;
  var errorMessage = error.message;

  window.alert("Error: " + errorMessage);
});
}

function logout(){
  firebase.auth().signOut();
  document.getElementById("login_btn").innerHTML="Login";
  document.getElementById("logout_btn").innerHTML="Logout";

}
