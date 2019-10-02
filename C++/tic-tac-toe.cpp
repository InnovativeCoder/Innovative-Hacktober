#include<iostream>
using namespace std;

	void draw_board(int *b) {
	int k=0;
	cout<<"----++---++----"<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<"| ";
			if(b[k] == 0){
				cout<<k+1<<" |";
			}
			else{
				if(b[k]==-1){
					cout<<"X |";
				}
				else{
					cout<<"O |";
				}
			}
			k++;
		}
			cout<<"\n----++---++----"<<endl;
	}
}
    

int win(const int *board) {
    //determines if a player has won, returns 0 otherwise.
    unsigned wins[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int i;
    for(i = 0; i < 8; ++i) {
        if(board[wins[i][0]] != 0 &&
  			board[wins[i][0]] == board[wins[i][1]] && board[wins[i][1]] == board[wins[i][2]])
            return board[wins[i][2]];
    }
    return 0;
}

int minimax(int *board, int player) {
    int winner = win(board);
    
    if(winner != 0)
    	return winner*player;

    int move = -1;
    int score = -2;
    
    for(int i = 0; i < 9; i++) {
        
        if(board[i] == 0) {
            
            board[i] = player;
            int thisScore = -minimax(board, player*-1);
            
            if(thisScore > score) {
                score = thisScore;
                move = i;
            }
            board[i] = 0;//Reset board after try
        }
    }
    if(move == -1)
     return 0;
    
    return score;
}

int computerMove(int *board) {
    int move = -1;
    int score = -2;

    for(int i = 0; i < 9; ++i) {
        
        if(board[i] == 0) {
            board[i] = 1;
            int tempScore = -minimax(board, -1);
            board[i] = 0;
            
            if(tempScore > score) {
                score = tempScore;
                move = i;
            }
        }
    }
    //returns a score based on minimax tree at a given node.
    return move;
}


int main(){
	cout <<"\n~~~~~~~~~~~~~Tic Tac Toe~~~~~~~~~~~~~\n";
	cout <<"\n\n   BOARD:\n";
	cout << "----++---++----" << endl;
	cout << "| 1 || 2 || 3 |" << endl;
	cout << "----++---++----" << endl;
	cout << "| 4 || 5 || 6 |" << endl;
	cout << "----++---++----" << endl;
	cout << "| 7 || 8 || 9 |" << endl;
	cout << "----++---++----" << endl << endl << endl;

	cout<<"Only legal moves are the numbers you see on the board\n\n";
	int board[9]={0};
	int moves=0,k;
	//Player = -1 ; Computer = 1
	while(moves < 9){
		int mv;
		cout<<"Enter Player 1's Move\n";
		cin>>mv;
		if(board[mv-1]==0){
			board[mv-1]=-1;
			moves++;
			cout<<"\n\nBoard after your move:\n";
			draw_board(board);
            if(win(board)==0){
            	k=computerMove(board);
            	board[k]=1;
            	cout<<"\n\nBoard after computer's move:\n";
            	draw_board(board);
				moves++;
				if (win(board) != 0){
					break;
				}
			}
            else
            	break;
		}
		else{
			cout<<"Illegal Move, Try again !! \n\n";
		}
	}
	 switch(win(board)) {
        case 0:
            cout<<"Its a draw. Better Smart next time.\n";
            break;
        case 1:
            cout<<"You lose.\n";
            break;
        case -1:
            cout<<"This will never Happen. But if it does(It never will), Congratulations, You have beaten the unbeatable\n";
            break;
    }
	return 0;
}
