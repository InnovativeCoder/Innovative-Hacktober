import random

number = random.randint(1,99)

guess = int(input('Enter an integer from 1 to 99:'))

while number != 'guess':
    if guess < number:
        print('guess is low')
        guess = int(input('Enter an integer from 1 to 99:'))
    elif guess > number:
        print('guess is high')
        guess = int(input('Enter an integer from 1 to 99:'))
    elif guess < 0:
        print("guess isn't a negative number")
        guess = int(input('Enter an integer from 1 to 99:'))
    else:
        print('congratulations,you guessed it. the secret number is {}'.format(number))
        break