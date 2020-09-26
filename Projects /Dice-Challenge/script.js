
    if (performance.navigation.type == 1) {
    


var p1=Math.random();
p1=Math.floor(p1*6);
p1=p1+1;

var p2=Math.random();
p2=Math.floor(p2*6);
p2=p2+1;
var srcimg1="images/dice"+p1+".png";
var srcimg2="images/dice"+p2+".png";

document.querySelector("img.img1").src=srcimg1; 
document.querySelector("img.img2").src=srcimg2; 


if(p1>p2)
{
    document.querySelector("h1").innerHTML="Player 1 Wins!";
}
else if(p2>p1)
{
    document.querySelector("h1").innerHTML="Player 2 Wins!";
}
else{
    document.querySelector("h1").innerHTML="Draw!";
}

    }

   