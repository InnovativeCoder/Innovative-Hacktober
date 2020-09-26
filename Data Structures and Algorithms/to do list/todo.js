//to strike off/on the tasks completed
$("ul").on("click","li",function()
{
   $(this).toggleClass("completed");
});
//to remove a task
$("ul").on("click","span",function(event){
               
    $(this).parent().fadeOut(500,function(event)
        {                     
       $(this).remove();
    });
    
    event.stopPropagation();  //to prevent bubbling 
});
//for input
$("input").keypress(function(event){
    if(event.which===13)
        {
            var todo=$(this).val();
            $(this).val("");
            $("ul").append("<li><span><i class='fas fa-eraser'></i></span>"+"  "+todo+"</li>");
            
        }
});
// to make the pencil icon work
$(".fa-pencil-alt").click(function(){
    $("input").fadeToggle();
});
                   