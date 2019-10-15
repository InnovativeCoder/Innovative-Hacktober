$('#verify-otp').hide();
$('#request-otp').on('click',function(){
  $('#sign-in').hide();
  $('#verify-otp').show();
  $('#credential').hide();
});
$('.fa-chevron-left').on('click',function(){
  $('#sign-in').show();
  $('#verify-otp').hide();
  $('#credential').show();
});


/*timer*/

var h5 = document.getElementsByTagName("h5");
h5[0].innerHTML = "OTP will expire in";

var sec         = 600,
    countDiv    = document.getElementById("timer"),
    secpass,
    countDown   = setInterval(function () {
        'use strict';
        
        secpass();
    }, 1000);

function secpass() {
    'use strict';
    
    var min     = Math.floor(sec / 60),
        remSec  = sec % 60;
    
    if (remSec < 10) {
        
        remSec = '0' + remSec;
    
    }
    if (min < 10) {
        
        min = '0' + min;
    
    }
    countDiv.innerHTML = min + ":" + remSec;
    
    if (sec > 0) {
        
        sec = sec - 1;
        
    } else {
        
        clearInterval(countDown);
        
        countDiv.innerHTML = 'OTP expired';
        
    }
}


$('#model3').hide();

$('#request-otp').on('click',function(){
  $('#model3').show();
});
$('.fa-chevron-left').on('click',function(){
  $('#model3').hide();
});

$('#resend').on('click',function(){
  sec = 600;
secpass();
});
$('#request-otp').on('click',function(){
  sec = 600;
secpass();
});