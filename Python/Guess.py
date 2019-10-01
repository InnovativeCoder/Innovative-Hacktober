from random import randint
name = input("Hey, Whats your name?\n")
print('Hello '+ name + ', I\'m guessing a number between 1 and 20.')
print('You have 6 chances!')
secretnumber = randint(1,20)

for i in range(7):
    print('Take a guess:')
    number = input()
    if int(number)>secretnumber :
        print('That\'s too high boii!')
    elif int(number)<secretnumber :
        print('That\'s too low boiii!')
    else:
        break
    
if int(number) == secretnumber:
    print('congooo boiiii!! \nYou did it.')
else:
    print('You loose!!! \n '+ 'The number i guessed was : ' + str(secretnumber))

