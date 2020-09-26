import page1
import page2
from webcrawl import *


while True:
	choice,querry = page1.fun()
	if(choice==2):
		while True:
			search = page2.fun1(querry)
			if search:
				pass
			else:
				exit()	
			querry = search
			if(querry):
				pass
			else:
				break
	elif(choice==1):
		webcrawl(querry)


	else:
		print('something went wrong')
