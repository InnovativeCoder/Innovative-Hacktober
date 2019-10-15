const myForm = document.querySelector('#my-form');
const unameInput = document.querySelector('#uname');
const emailInput = document.querySelector('#email');
const msg = document.querySelector('.msg');
const userList = document.querySelector('#users');

myForm.addEventListener('submit', onSubmit);

function onSubmit(e) {
    e.preventDefault();
    
    if(unameInput.value === '' || emailInput.value === ''){
        msg.innerHTML = 'Please enter all fields before submitting.';
        msg.classList.add('error');
        setTimeout(() => msg.remove(), 5000);
    }
    else {
    window.location = "page2.html";
    }


}
