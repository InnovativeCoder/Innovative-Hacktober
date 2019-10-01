for(var i=0;i<document.querySelectorAll(".drum").length;i++)
{
    document.querySelectorAll(".drum")[i].addEventListener("click",handleClick);
}
function handleClick()
{
    sound=this.innerHTML;
    makeSound(sound);
    buttonAnimation(sound);
}

document.addEventListener("keypress",handleKeyPress);

function handleKeyPress(e){
makeSound(e.key);
buttonAnimation(e.key);
}
function makeSound(sound)
{
    switch (sound) {
        case "w":
            var tom1 = new Audio("sounds/tom-1.mp3");
            tom1.play();
            break;
        case "a":
            var tom2 = new Audio("sounds/tom-2.mp3");
            tom2.play();
            break;
        case "s":
            var tom3 = new Audio("sounds/tom-3.mp3");
            tom3.play();
            break;
        case "d":
            var tom4 = new Audio("sounds/tom-4.mp3");
            tom4.play();
            break;
        case "j":
            var snare = new Audio("sounds/snare.mp3");
            snare.play();
            break;

        case "k":
        var crash = new Audio("sounds/crash.mp3");
        crash.play();
            break;

        case "l":
        var kick = new Audio("sounds/kick-bass.mp3");
        kick.play();
            break;

        default: console.log(sound);
    }
}

function buttonAnimation(currentKey)
{
    var actvbtn=document.querySelector("."+currentKey);
    actvbtn.classList.add("pressed");
    setTimeout(function() {        
        actvbtn.classList.remove("pressed");},100);
}