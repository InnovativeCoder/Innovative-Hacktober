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

  }
   else {
    // No user is signed in.
    document.getElementById("login_btn").style.display = "block";
    document.getElementById("logout_btn").style.display = "none";
    document.getElementById("sign_up").style.display = "block";
    document.getElementById("navbarDropdown").innerHTML = "Login";
    document.getElementById("Complaint_submission").style.display = "none";
  }
});


function signup(){

  var signupRef = firebase.database().ref().child("Signup_form");

  document.getElementById("sign_up_form").addEventListener('submit' , submitForm);
   function submitForm(e){
   	e.preventDefault();

     var user_name = document.getElementById("username").value;
     var user_mobile = document.getElementById("mobile_no").value;
     var user_psw = document.getElementById("psw").value;
     var user_email = document.getElementById("email").value;
     var user_aadhar = document.getElementById("aadhar").value;
     var user_state = document.getElementById("state_select").value;
     var user_pinCode = document.getElementById("pincode").value;

   	saveForm(user_name, user_mobile, user_psw, user_email,user_aadhar,user_state,user_pinCode);
   }

   function saveForm(user_name, user_mobile, user_psw, user_email,user_aadhar,user_state,user_pinCode){
  	var newSignupRef = signupRef.push();
   	newSignupRef.set({
  		Name:user_name,
  		Mobile:user_mobile,
   		Psw:user_psw,
   		Email:user_email,
       Aadhar:user_aadhar,
       State:user_state,
      Pincode:user_pinCode
   	});
   }

   document.getElementById("sign_up_form").style.display = "none";
   window.alert("Your details have been submitted successfully. Please log in with emailID = 'mangreat64@gmail.com' and password= 'password' as the data is in the database but not able to add to users list of firebase..thanks");

var database =firebase.database();
   function writeUserData(user_name, user_mobile, user_psw, user_email,user_aadhar,user_state,user_pinCode) {
 firebase.database().ref('users/' + userId).set({
   username: user_name,
   mobile: user_mobile,
   psw:user_psw,
   email:user_email,
   aadhar:user_aadhar,
   state:user_state,
   pincode:user_pinCode
 });
 }

 firebase.auth().signInWithEmailAndPassword(user_email, user_psw).catch(function(error) {
  // Handle Errors here.
  var errorCode = error.code;
  var errorMessage = error.message;
  // ...
});
}



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
