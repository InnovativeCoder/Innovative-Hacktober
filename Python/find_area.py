import math
def get_area(shape):
    shape=shape.lower()
    if shape=="rectangle":
        rectangle_area()
    elif shape=="circle":
        circle_area()
    else:
            print("plz enter rectangle or area")
def rectangle_area():
    l=float(input("enter the length "))
    w=float(input("enter the width "))
    area=l*w
    print("the area of rectangle is ",area)
def circle_area():
    r=float(input("enter the radius"))
    area=math.pi*(math.pow(r,2))
    print("the area of circle is {:.2f}".format(area))

def main():
    shape_type=input("enter shape")
    get_area(shape_type)

main()

