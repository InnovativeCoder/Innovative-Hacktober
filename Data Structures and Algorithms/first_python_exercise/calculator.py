# Basic Calculator Program 
# Name: __

'''
Instructions:
1. Complete Each of the todos.
2. Completely display the results.
    The output should look similar to below:

        Please input the numbers you would like to compute on: 
        12
        3

        addition: 12 + 3 = 15
        subtraction: 12 - 3 = 9
        multiplication: 12 * 3 = 36
        division: 12 / 3 = 4

Note:
    - Keep in mind what happens when you have 3/12, 3 - 12, etc.
    - Assume the order in which you get input is the order you operate.  EX: if you get input 3 then 2, then 3 - 2 = 1, 
    but if you got inputs 4 then 8, then your answer would be -4
    - Make sure you are using python 2.7.  The user input method changes btwn python 2 and 3.

    - Feel free to change variable and/or function names.  Just leave main().  It is a standard in all programs.

'''


def addition(x, y):
    sum = x + y
    return sum

### TODO: create separate functions for subtraction, multiplication, and division

def main():

    ### TODO: Instead of hard coding the values of x and y here, request user input of two separate numbers
    x = 4
    y = 7

    print "Please input the numbers you would like to compute on: "
    # get input here


    # Call each function and return a value
    answer = addition(x,y) 
    answer = x + y 


    # Display the results
    print answer

main()
