/*
  Author : Rafael Douglas
  Date: 22-10-2019
	
*/
function isPalindrome(str){
  let inv = str.split("").reverse().join("");
  if(inv != str){
    return false
  }
  return true
}
console.log(isPalindrome("dead"));
console.log(isPalindrome("daad"));
