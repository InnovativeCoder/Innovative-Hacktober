#Solution to the Gradingstudents Problem in Hackerrank-Problem Solving-Algorithms
#!/bin/python3

import math
import os
import random
import re
import sys

def gradingStudents(grades):
    # Write your code here
    fgrade=[]
    for i in grades:
        if i<38:
            fgrade.append(i)
        else:
            a=((i//5)+1)*5
            if a-i<3:
                fgrade.append(a)
            else:
                fgrade.append(i)
    return fgrade

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    grades_count = int(input().strip())

    grades = []

    for _ in range(grades_count):
        grades_item = int(input().strip())
        grades.append(grades_item)

    result = gradingStudents(grades)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
