import snake from "./snake.js"

export default class inputHandler{
    constructor(snake){
        document.addEventListener("keydown",event => {
            //alert(event.key);
            switch(event.key){
                case "ArrowLeft":
                    // console.log("Left");
                    snake.moveLeft();
                    break;
                
                case "ArrowUp":
                    snake.moveUp();
                    break;
                
                case "ArrowRight":
                    // console.log("Right");
                    snake.moveRight();
                    break;
                
                case "ArrowDown":
                    snake.moveDown();
                    break;

                default:
                    break;
            }
        });
    }
}