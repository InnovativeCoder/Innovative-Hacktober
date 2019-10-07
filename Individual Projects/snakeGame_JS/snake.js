

export default class snake{
    constructor(width, height,){
        this.gameOver = 0;
        this.gameWidth = width;
        this.gameHeight = height;
        this.step = 20; // change in coordinates
        this.blockSize = 20;
        this.index = 0;
        this.snake = [
            {
                x: 200,
                y: 200
            },
            {
                x: 200,
                y: 220
            },
            {
                x: 200,
                y: 240
            }
        ];
        
        this.direction = {
            dir: 3,
            dx: 0,
            dy: -(this.step)
        }
        
    }
    eatingItself(){
        if(Boolean(this.gameOver) == true){
            console.log(Boolean(this.gameOver));
        }
        return Boolean(this.gameOver);
    }
    drawSnake(ctx){
        
        let i = 0;

        for(i=0 ; i!=this.snake.length ; i++){
            if(i != 0 && this.snake[i].x == this.snake[0].x && this.snake[i].y == this.snake[0].y){
                this.gameOver = 1;
            }
            ctx.fillStyle = "black";
            ctx.fillRect(this.snake[i].x,this.snake[i].y,this.blockSize, this.blockSize);
        }
    }
    growSnake(){
        let headX = this.snake[0].x;
        let headY = this.snake[0].y;

        headX += this.direction.dx;
        headY += this.direction.dy;

        let newHead = {
            x: headX,
            y: headY
        }
        this.snake.unshift(newHead);
    }

    isContact(fd){
        this.foodX = fd.getPositionX();
        this.foodY = fd.getPositionY();
        if(this.foodX == this.snake[0].x && this.foodY == this.snake[0].y)   {
            return 1;
        }
        else return 0;
    }

    /*
    {
        Left: 1
        Right: 2
        Up: 3
        Down: 4
    }
    */    
    moveLeft(){
        // console.log("moveLeft");
        if( this.direction.dir == 2 ) return;
        this.direction.dx = -(this.step);
        this.direction.dy = 0;
        this.direction.dir = 1;
    }
    moveRight(){
        if( this.direction.dir == 1 ) return;
        this.direction.dx = (this.step);
        this.direction.dy = 0;
        this.direction.dir = 2;
    }
    moveUp(){
        if( this.direction.dir == 4 ) return;
        this.direction.dx = 0;
        this.direction.dy = -(this.step);
        this.direction.dir = 3;
    }
    moveDown(){
        if( this.direction.dir == 3 ) return;
        this.direction.dx = 0;
        this.direction.dy = (this.step);
        this.direction.dir = 4;
    }

    updateSnake(){

        
        let newHead;
        newHead = this.snake.pop();
        newHead.x = this.snake[0].x + this.direction.dx;
        newHead.y = this.snake[0].y + this.direction.dy;
        this.snake.unshift(newHead);

        if(this.snake[0].x < 0) this.snake[0].x = this.gameWidth;
        if(this.snake[0].x  > this.gameWidth) this.snake[0].x = 0;
        if(this.snake[0].y < 0) this.snake[0].y = this.gameHeight;
        if(this.snake[0].y  > this.gameHeight) this.snake[0].y = 0;

        

    }
}