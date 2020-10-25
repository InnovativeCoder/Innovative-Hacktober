let letters = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"];

let table = [letters]

let plaintext = "ATTACKATDAWN";
let key = "LEMON";
let repeatKey = "";
let solution = "";

let remainder = plaintext.length % key.length;
let round = Math.round(plaintext.length / key.length);

for(let i = 0; i < round; i++){
  repeatKey += key;
}

for(let i = 0; i < remainder; i++){
  repeatKey += key[i];
}


//Set up tables
function getLetterSet(set, index){
  let first = set[0];
  let newSet = [];
  for(let i = 1; i <= 25; i++){
    newSet.push(set[i])
  }
  newSet.push(first);
  table.push(newSet);
  if(index <= 23){
    getLetterSet(newSet, index + 1);
  }else{
    return table;
  }
}

let newTable = getLetterSet(letters, 0);


//Solution
for(let i = 0; i < plaintext.length; i++){
  let plainLetter = plaintext[i];
  let keyLetter = repeatKey[i];
  let rowNum = letters.indexOf(keyLetter);
  let colNum = letters.indexOf(plainLetter);
  let cipher = table[rowNum][colNum];
  solution += cipher;
}

console.log(solution)
