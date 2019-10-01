class ticTacToe:
	def __init__(self):
		self.player = '0'
		self.players = {
		'0': 'X',
		'X': '0',
		}
		self.board = {
			1: '',
			2: '',
			3: '',
			4: '',
			5: '',
			6: '',
			7: '',
			8: '',
			9: '',
		}

	def showBoard(self):
		print(f"""
		Player 1: 0
		Player 2: X
			{self.board[1] or '1'}|{self.board[2] or '2'}|{self.board[3] or '3'}
			-----
			{self.board[4] or '4'}|{self.board[5] or '5'}|{self.board[6] or '6'}
			-----
			{self.board[7] or '7'}|{self.board[8] or '8'}|{self.board[9] or '9'}
			""")

	def move(self):
		self.choice = int(input(f"What's your move [{self.player}]? "))
		if(not self.board[self.choice]):
			self.board[self.choice] = self.player
		else:
			print("It's been used. Try again!!")
			self.move()

	def changePlayer(self):
		self.player = self.players[self.player]

	def winner(self):
		if(
			(self.board[1] == self.board[2] and self.board[1] == self.board[3] and self.board[1] != '') or
			(self.board[4] == self.board[5] and self.board[4] == self.board[6] and self.board[4] != '') or
			(self.board[7] == self.board[8] and self.board[7] == self.board[9] and self.board[7] != '') or
			(self.board[1] == self.board[4] and self.board[1] == self.board[7] and self.board[1] != '') or
			(self.board[2] == self.board[5] and self.board[2] == self.board[8] and self.board[2] != '') or
			(self.board[3] == self.board[6] and self.board[3] == self.board[9] and self.board[3] != '') or
			(self.board[1] == self.board[5] and self.board[1] == self.board[9] and self.board[1] != '') or
			(self.board[3] == self.board[5] and self.board[3] == self.board[7] and self.board[3] != '')
		):
			return True
		else:
			return False

	def checkWinner(self):
		if('' not in self.board.values() and not self.winner()):
			print("No one wins !! ¯\\_(ツ)_/¯ \n")
			return True
		elif(self.winner()):
			print(f"{self.players[self.player]} won ＼(＾O＾)／ \n")
			return True
		else:
			return False

	def start(self):
		print('\n\tUse 1-9 to give the position with top-left being 1')
		self.showBoard()
		while(not self.checkWinner()):
			self.move()
			self.changePlayer()
			self.showBoard()
