var board = [0, 0, 0, 0, 0, 0, 0, 0, 0];
document.value = 0;
document.count = 0;

function StartGame() {
  board = [0, 0, 0, 0, 0, 0, 0, 0, 0];
  document.value = 0;
  document.count = 0;
  for(var i = 0; i < 9; i++) {
    document.getElementById("s" + i).innerText = "";
  }
  // ComputerMove(board);
}
function setMessage(msg) {
  document.getElementById('message').innerText = msg;
}

function Win(board) {
	var wins = [[0, 1, 2], [3, 4, 5], [6, 7, 8], [0, 3, 6], [1, 4, 7], [2, 5, 8], [0, 4, 8], [2, 4, 6]];
	for(var i = 0; i < 8; i++) {
    if(board[wins[i][0]] != 0 && board[wins[i][0]] == board[wins[i][1]] && board[wins[i][1]] == board[wins[i][2]])
			return 	board[wins[i][0]];
	}
	return 0;
}
function checkForWinner(board) {
  var winner = Win(board);
  if(winner == -1) {
    window.alert("You Won!!!");
  }
  else if(winner == 1) {
    window.alert("Computer Won!!!");
  }
  if(document.count == 8) {
    window.alert("Tie");
  }
}
function minmax(board, player) {
	  var winner = Win(board);
    if(winner != 0)
      return winner*player;

    var move = -1;
    var score = -2;
    var i;
    for(i = 0; i < 9; ++i) {
        if(board[i] == 0) {
            board[i] = player;
            var Score = -minmax(board, player * (-1));
            if(Score > score) {
                score = 	Score;
                move = i;
            }
            board[i] = 0;
        }
    }
    if(move == -1)
    	return 0;
    return score;
}

function ComputerMove(board) {
  checkForWinner(board)
	var move = -1;
  var score = -2;
  var i;
  for(i = 0; i < 9; ++i) {
      if(board[i] == 0) {
          board[i] = 1;
          var tempScore = -minmax(board, -1);
          board[i] = 0;
          if(tempScore > score) {
              score = tempScore;
              move = i;
          }
      }
  }
  board[move] = 1;
  var id = "s" + move;
  //window.alert(id + board);
  document.getElementById(id).innerText = 'o';
  checkForWinner(board)
  document.count++;
}

function nextMove(value) {
  var id = 's' + value;
  //document.value = value;
  if(board[value] == 0 && document.getElementById(id).innerText == "") {
    document.getElementById(id).innerText = "x" ;
    board[value] = -1;
    checkForWinner(board);
    document.count++;
    //window.alert(board);
    ComputerMove(board);
  }
  //window.alert(board);

  else {
    setMessage("Not valid move!");
  }
}
