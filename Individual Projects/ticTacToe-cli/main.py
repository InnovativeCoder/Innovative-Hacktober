import boardClass
import sys

def startgame():
    game = boardClass.ticTacToe()
    game.start()

def main():
    print("""
    ===TIC-TAC-TOE===
    1. [S]tart
    2. E[X]it
    """)
    choice = input('> ').upper()
    
    if(choice == 'S'):
        again = True
        while(again == True):
            startgame()
            again = input('Enter a no. to play again: ').isnumeric()
    elif(choice == 'X'):
        sys.exit()
    else:
        print('What??? Goodbye')

if __name__ == '__main__':
	main()
