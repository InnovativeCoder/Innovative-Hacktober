import random

team1=input("Enter first team name:")
print(team1)

team2 = input("Enter name of opponent team:")
print(team2)

chance = random.randint(0, 1)

if chance==0:
    print(team1 + " has the chance to make a call for toss.")
    call=input("Make a call:")
    
else: 
    print(team2 + " has the chance to make a call for toss.")
    call=input("Make a call: ")
print(call + " is the call.")
    
toss = random.randint(0, 1)

if toss==0:
    toss_val = "Heads"
else:
    toss_val = "Tails"
    
if toss_val==call:
    print(call + "it is.")
    
else:
    print("It's not " + call)
    
if chance==0 and toss_val==call:
    print(team1 + " has won the toss.")
elif chance==0 and toss_val!=call:
    print(team1 + " has lost the toss.")
elif chance==1 and toss_val==call:
    print(team2 + " has won the toss.")
elif chance==1 and toss_val!=call:
    print(team2 + " has lost the toss.")
