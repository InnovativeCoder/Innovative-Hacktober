def sieve_of_eratothenes(number): # Number upto which you want to print the prime number

    lis = [True for i in range(number+1)] # making a list which has True value at every posn from 0 to number
    n = 2                        #starting with 2 as it is our first prime no.
    while n**2 <= number:        #square of n should be smaller than or equal to number,you will get why we do so
        if n:                    #n should be true, means it should be prime
            for j in range(n**2,n+1,n):   #we mark the no. which are divisible by n False
                lis[j] = False            #btw n**2 to n(i.e why n**2 should be <= number)
        n+=1                              # increment n by 1 to repeat the step further with others no.

    for k in range(2,n+1):     # to print the positional value between 2 to n which has True value( means which are prime positional value)
        if lis[k]:
            print(k)

# Time complexity is o(n*log(log(n)))
