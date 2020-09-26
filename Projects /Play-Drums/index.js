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
        case "r":
            var crash = new Audio("sounds/crash rock.flac");
            var kick = new Audio("sounds/kick-bass.mp3");
            crash.play();
            kick.play();
            break;
            
        case "d":
            var highhat = new Audio("sounds/highhat(rock).flac");
            highhat.play();
            break;

        case "c":
            var snare = new Audio("sounds/snare.mp3");
            snare.play();
            break;

        case "v":
            var kick = new Audio("sounds/kick-bass.mp3");
            kick.play();
            break;

        case "g":
            var tom1 = new Audio("sounds/tom-1.mp3");
            tom1.play();
            break;

        case "h":
            var tom2 = new Audio("sounds/tom-2.mp3");
            tom2.play();
            break;

        case "j":
            var ftom1 = new Audio("sounds/ftom-1.mp3");
            ftom1.play();
            break;
        
        case "k":
            var ftom2 = new Audio("sounds/ftom-2.mp3");
            ftom2.play();
            break;
        
        case "s":
            var cymbal = new Audio("sounds/cymbal rock.flac");
            cymbal.play();
            break;

        default: console.log(sound);
    }
}

function buttonAnimation(currentKey)
{
    var actvbtn=document.querySelector("."+currentKey);
    actvbtn.classList.add("pressed");
    setTimeout(function() {        
        actvbtn.classList.remove("pressed");},90);
}