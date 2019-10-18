import random

def game(low, high):
    assert (low < high and min(low, high) >= 1), 'Range specified must be low to high and positive only.'
    n = 0; num = random.randint(low, high + 1)
    print(num)
    while True:
        guess = int(input(f'Enter an integer from {low} to {high}: '))
        n += 1
        if guess != num: print('Incorrect : ' + ('It isn\'t a negative number' if guess < 0 else 'Too low!' if guess < num else 'Too high' if guess > num else 'Error'))
        else: break
    print(f'Congratulations, you guessed the secret number, {num}.')
    print('It took you {} guess{}.'.format(n, 'es' if n > 1 else ''))

game(1, 99)