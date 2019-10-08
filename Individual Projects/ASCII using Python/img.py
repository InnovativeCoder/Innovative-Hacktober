import numpy as np
import math
from PIL import Image
from scipy.misc import imread
# file name here
file="matrix2.png"
# file="small_nav33nb.png"
BRIGHTNESS_STRING = "`^\",:;Il!i~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$"
brightSize = len(BRIGHTNESS_STRING)

def printThis2D(matrix):
    temp = open('temp.txt','w')
    for x in matrix:
        for y in x:
            print(y+y,end="",file=temp)
        print("\n",file=temp)

# MAPPINGS
def toCharacter(num):
    num = (num/255)*(brightSize-1)
    num = math.floor(num)
    char = BRIGHTNESS_STRING[num]
    return char

def toAvgBright(matrix):
    #input is pixel values
    width,height,a = matrix.shape
    print(width,height,a)
    brightness = []
    temp = 0
    #taking average of brightness of every pixels values for a single value
    for row in range(len(matrix)):
        new = []
        for col in range(len(matrix[row])):
            for value in matrix[row][col]:
                temp = temp + value
            temp = temp/len(matrix[row][col])
            new.append(temp)
            temp = 0
        brightness.append(new)
    #return a similar matrix but with brightness as a single value
    return brightness

img = Image.open(file)
#img.rotate(90).show()

width,height = img.size
print("\nIMAGE SIZE BE")
print(width,"x",height)

pixels = np.array(imread(file))
print("\nMATRIX ROWS BE")
print(pixels.shape)

# arr = np.random.randint(255,size=(2,2,3))
# print(arr)

bright = toAvgBright(pixels)
# bright = toAvgBright(arr)

print("\nBRIGTHNESS MATRIX BE")
# print(bright)

print("\nBRIGHNESS_STRING SIZE BE")
print(brightSize)

print("CHARACTER MATRIX BE")
char = []
for x in bright:
    #maps single brightness value to a character in the BRIGHTNESS_STRING
    res = map(toCharacter,x)
    char.append(list(res))

char = np.array(char)
printThis2D(char)
# print(list(res))
#toCharacter(arr)
# print(toarr)
