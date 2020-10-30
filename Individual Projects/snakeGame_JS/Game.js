import food from "./food.js";
import snake from "./snake.js";

console.log("");
let canvas = document.getElementById("gameScreen");
let ctx = canvas.getContext("2d");

const WIDTH = 400;
const HEIGHT = 400;


let lastTime = 0;


const field = new Image();
field.src = "http://maculacenter.com/wp/wp-content/uploads/2012/08/amsler.gif"

////////

let direction;

document.addEventListener("keydown",event => {
    switch(event.key){
        case "ArrowLeft":
            direction = 1;
            break;
        
        case "ArrowRight":
            direction = 2;
            break;
            
        case "ArrowUp":
            direction = 3;
            break;
        
        case "ArrowDown":
            direction = 4;
            break;

        default:
            break;
    }
});


////////


let fd = new food(ctx);
let snk = new snake(WIDTH,HEIGHT);
// new inputHandler(snk);

function gameLoop(){
    ctx.clearRect(0,0,400,400);

    ctx.drawImage(field,0,0);
    

    if(direction == 1) snk.moveLeft();
    if(direction == 2) snk.moveRight();
    if(direction == 3) snk.moveUp();
    if(direction == 4) snk.moveDown();
        

    fd.drawFood(ctx);

    if(snk.isContact(fd)){
        snk.growSnake();
        snk.updateSnake();
        fd.updateFood();
        snk.drawSnake(ctx);
    }
    else{
        // console.log("else");
    snk.updateSnake();
    // fd.updateFood();

    snk.drawSnake(ctx);
    }

    if(snk.eatingItself()){
        alert("Next Time ?");
        clearInterval(game); 
    }

    // requestAnimationFrame(gameLoop);
}



let game = setInterval(gameLoop,100);
