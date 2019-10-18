# Python program to find the factorial of a number using recursion

"""Function to return the factorial
of a number using recursion"""
factorial = lambda n : n if n == 1 else n * factorial(n - 1)

#Take input from the user
num = int(input("Enter a number: "))

# check is the number is negative
if num < 0: print("Sorry, factorial does not exist for negative numbers")
elif num == 0: print("The factorial of 0 is 1")
else: print(f'The factorial of {num} is {factorial(num)}.')