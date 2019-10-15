import random
number = random.randint(1,99)
chance = 0
correct = False
while not correct:
    guess = int(input('Enter an integer from 1 to 99: '))
    chance += 1
    if guess < 0:
        print('guess isn't a negative number\n')
    elif guess < number:
        print('guess is low\n')
    elif guess > number:
        print('guess is high\n')
    elif guess == number:
        correct=True
print('congratulations,you guessed it. the secret number is {}!'.format(number))
print('And it took you {} guesses!'.format(chance))
