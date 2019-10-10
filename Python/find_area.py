import math
def get_area(shape):
    shape=shape.lower()
    if shape=="rectangle":
        rectangle_area()
    elif shape=="circle":
        circle_area()
    elif shape=="triangle":
        triangle_area()
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
def triangle_area():
    print("There are two ways to find the area of a triangle.  Chose one:")
    print("1. Base and height")
    print("2. Length of all three sides")
    choice=input("Which way? ")
    if choice=="1":
        b=float(input("Enter the length of the base "))
        h=float(input("Enter the length of the height "))
        area=b*h/2
        print("The area of the triangle is {:.2f}".format(area))
    if choice=="2":
        a=float(input("Enter the length of side a "))
        b=float(input("Enter the length of side b "))
        c=float(input("Enter the length of side c "))
        p=(a+b+c)/2
        area = math.sqrt(p*(p-a)*(p-b)*(b-e))
        print("The area of the triangle is {:.2f}".format(area))

def main():
    shape_type=input("enter shape")
    get_area(shape_type)

main()

