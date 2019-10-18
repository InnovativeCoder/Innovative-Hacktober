# this program takes
# survey of the people and
# analyze the data

import statistics # IMPORT THE STATISTICS MODULE TO FIND AVERAGE EASILY THROUGH A FUNCTION WITHOUT MANUAL INTERFACE
import matplotlib.pyplot as plt

#unicode printing
print('''
This is a program made by Deepansh Goel to take demographic
data of people such as gender, age, income, etc. and analyze
it later on.
''')

data ={'ages': [] , 'famNum': [], 'genF': 0, 'genM': 0, 'avgInc': []} #variables defined
age1_9 = age10_18 = age19_28 = age29_45 = age45a = 0


def inputUserData():
    global data  #makes data a global variable to change and assign value for secret feature
    age = input('What is your age?:' )
    if age == 'secret':
        data = {'ages': [12, 34, 56] , 'famNum': [5, 6, 9], 'genF': 2, 'genM': 1, 'avgInc': [23321, 64734, 3523245]}
        return data
    while True:    #forver loop for input validation
        try:
            age = int(age)NN
            data['ages'].append(age)            #runs the following code in block if age is integer
                                                #else if there is an error coming out then tells
                                                #user to enter a number. This all happens in
                                                #TRY and EXPECT BLOCKS
            break
        except ValueError:
            print('Please enter a number ')
            age = input(' ')

    famNum1 = input('How many members ar there in your family ' )
    while True:
        try:
            famNum1 = int(famNum1)
            data['famNum'].append(famNum1)
            break
        except ValueError:
            print('Please enter a number')
            famNum1 = input(' ')

    gen = input("What is your Gender? M or F: ")
    while True:
        if gen == 'M':
            data['genM'] += 1
            break                                           #ALL INPUT VALIDATION
        elif gen == 'F':                                    #AND ASSIGNING VARIABLES FOR LATER USE.
            data['genF'] += 1
            break
        else:
            print("enter M or F")
            gen = input("What is your Gender? M or F: ")

    avgInc = input("What is your average income?: ")
    while True:
        try:
            
            avgInc = int(avgInc)
            
            data['avgInc'].append(avgInc)
            break
        except ValueError:
            print('Please enter a number ')
            avgInc = input(' ')

    print(data)                                            #PRINTS DATA FOR CHECK AND DEBUGGING
                                                           #WILL BE REMOVED BEFORE FINAL TESTING AND CALLING


inputUserData() #calls the function


while True:         #ASK PLAYER TO PLAY AGAIN
    ans = input('''
Add another person? 
Y/N

    ''')
    if ans == 'Y':
        inputUserData()

    elif ans == 'N':
        break

    else:
        input('Enter Y or N')


def age_analysis(age1_9, age10_18, age19_28, age29_45, age45a):
    age_key = data['ages']
    for i in age_key:
        if 1 < i < 9:
            age1_9 += 1
        elif 10 < i < 18:
            age10_18 += 1               #PRINTS THE AGE BRACKET
        elif 19 < i < 28:
            age19_28 += 1
        elif 29 < i < 45:
            age29_45 += 1
        elif i > 45:
            age45a += 1



    return age1_9, age10_18, age19_28, age29_45, age45a

def famNum_analysis(data):
    avg_fam = int(statistics.mean(data['famNum']))

    return avg_fam
                                                                    #ALL THIS PRINTS ANALYSIS OF THE DATA
def gender_analysis(data):
    F = (data['genF'])
    M = (data['genM'])
    print(f'''
Average no. of females : {F}
Average no. of Males : {M}

''')
    return M, F


def income_analysis(data):
    avg_inc = int(statistics.mean(data['avgInc']))
    print(f'''
Average income of a person is {avg_inc}
''')
    return avg_inc


age_analysis(age1_9, age10_18, age19_28, age29_45, age45a)
print(f'''
Age  1-9:          {age1_9} 
Age  10-19:        {age10_18}
Age  20-28:        {age19_28}
Age  28-45:        {age29_45}
Age  45 and above: {age45a}
''')



age1_9, age10_18, age19_28, age29_45, age45a = age_analysis(age1_9, age10_18, age19_28, age29_45, age45a)
avg_fam = famNum_analysis(data)
M, F = gender_analysis(data)
print(f'''
Average no. of females : {F}
Average no. of Males : {M}

''')

print(f'''
Age  1-9:          {age1_9} 
Age  10-19:        {age10_18}
Age  20-28:        {age19_28}
Age  28-45:        {age29_45}
Age  45 and above: {age45a}
''')

print(f'''
Average number of family members in a single family = {avg_fam}
           ''')
avg_inc = income_analysis(data)
#CALLS ALL THE REST OF THE FUNCTIONS

with open('data.txt', 'w') as f:
    f.write(f'''
Age  1-9:          {age1_9} 
Age  10-19:        {age10_18}
Age  20-28:        {age19_28}
Age  28-45:        {age29_45}
Age  45 and above: {age45a}
   
Average number of family members in a single family = {avg_fam}

Average no. of females : {F}
Average no. of Males : {M}


Average number of family members in a single family = {avg_fam}            
   ''')



import matplotlib.pyplot as plt; plt.rcdefaults()
import numpy as np
import matplotlib.pyplot as plt

print(age1_9, age10_18, age19_28, age29_45, age45a)

objects = ('1-9', '10-19', '20-28', '29-45', 'above 45')
y_pos = np.arange(len(objects))
performance = [age1_9, age10_18, age19_28, age29_45, age45a]

plt.bar(y_pos, performance, align='center', alpha=0.5)
plt.xticks(y_pos, objects)
plt.ylabel('No. of People')
plt.xlabel('Age brackets')
plt.title('Age brackets of people')

plt.show()
