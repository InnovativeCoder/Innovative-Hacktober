import time
from playsound import playsound

totalBreaks = 3 #Total 3 breaks until assignment is finished
count = 0

print('Program started on '+ time.ctime())
playsound('alert.wav')
while count <= totalBreaks:
    print('Next break coming up in 30 minutes')
    time.sleep(1800)    #Wait for 30 minutes
    print('Break Time! Playing your favorite song ..')
    playsound('alert.wav')
    count += 1

if count == totalBreaks:
    print('Over!')
    print('Program ended on '+time.ctime())
