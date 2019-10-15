export default class food{
    constructor(ctx){
        // console.log("foodConstructor");
        this.foodSize = 20;
        this.position = {
            x: 0,
            y: 0
        }
        
        this.updateFood();
    }
    drawFood(ctx){
        ctx.fillStyle = "red";
        ctx.fillRect(this.position.x,this.position.y, this.foodSize, this.foodSize);
    }
    updateFood(){
        this.position.x = Math.round((Math.random() * 1000))% 400;
        this.position.y = Math.round((Math.random() * 1000))% 400;
        let remX = this.position.x % 20;
        let remY = this.position.y % 20;
        if(remX  >10) this.position.x += (20 - remX);
        else this.position.x -= remX;

        if(remY > 10) this.position.y += (20 - remY);
        else this.position.y -= remY;


    }
    getPositionX(){
        return this.position.x;
    }
    getPositionY(){
        return this.position.y;
    }
}