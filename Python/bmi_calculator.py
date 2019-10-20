name = input("Enter your name: ")
weight = float(input('Enter your weight in KG:'))
height = float(input('Enter your height in meters:'))
bmi=weight/(height**2)
if bmi>25:
    print(name +' you are overweight')
    print("\n")
    print("Suggestion(s): " + """1. Do exercise regularly(particularly cardio).
                2. Follow healthy and balanced diet.
                3. Consult a dietician.
                4. Make note of daily calorie intake and decrease it.""")
elif bmi<25 and bmi>20:
    print(name +' you are neither overweight nor underweight')
    print("\n")
    print("Suggestion(s): " + "Continue following healthy diet and lifestyle to stay fit.")
elif bmi<20:
    print(name + " you are underweight")
    print("\n")
    print("Suggestion(s): " + """1. Do exercise on alternate days(ignore cardio).
               2. Consult a dietician.
               3. Make note of your daily calorie intake and increase it.""")
