const myForm = document.querySelector('#my-form');
const fnameInput = document.querySelector('#fname');
const lnameInput = document.querySelector('#lname');
const unameInput = document.querySelector('#uname')
const emailInput = document.querySelector('#email');
const msg = document.querySelector('.msg');
const msg1 = document.querySelector('.msg1');
const userList = document.querySelector('#users');

myForm.addEventListener('submit', onSubmit);

function onSubmit(e) {
    e.preventDefault();
    
    if(fnameInput.value === '' || lnameInput.value === '' || emailInput.value === '' || unameInput.value === ''){
        msg.innerHTML = 'Please enter all fields before submitting.';
        msg.classList.add('error');
        setTimeout(() => msg.remove(), 5000);
    }
    else {
          msg1.innerHTML = 'Signed up successfully.';
          msg1.style.color = 'red';
        }
    

}
