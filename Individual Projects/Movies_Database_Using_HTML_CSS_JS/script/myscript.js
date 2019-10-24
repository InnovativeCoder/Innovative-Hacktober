function change2(nameID,imageID,buttonID){
  var imagePath=document.getElementById(imageID);
  var backgroundPath=document.getElementById(nameID);
  var buttonPath=document.getElementById(buttonID);
  if(buttonPath.innerHTML=="Like"){
    console.log(buttonPath.innerHTML);
    imagePath.src='img/like.png';
    backgroundPath.style.backgroundColor="#A7E8AB";
    buttonPath.innerHTML="Dislike";
  }
  else{
    imagePath.src="img/dislike.png";
    backgroundPath.style.backgroundColor="#FF9A84";
    buttonPath.innerHTML="Like"
  }
}

function resetIframe(frameID){
  document.getElementById(frameID).src="";
}

function deleterow(rowID){
  document.getElementById(rowID).style.display="none"
}

function onLinkClick() {
  document.getElementById('frame').scrollIntoView();
  // will scroll to 4th h3 element
}
