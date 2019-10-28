def circle():
  pi=22/7
  r=float(input("enter r:"))
  area=pi*r*r
  return area
  
def triangle():
  a=float(input("enter side 1:"))
  b=float(input("enter side 2:"))
  c=float(input("enter side 3:"))
  s=(a+b+c)/2
  area=(s*(s-a)*(s-b)*(s-c))**0.5
  return area

def llgram():
  b=float(input("enter base:"))
  h=float(input("enter height:"))
  
def regular():
  n=int(input("enter sides:"))
  l=float(input("enter lenght of each side for a regular polygon:"))
  a=float(input("enter lenght of apothem:")
  area=n*l*a/2
  return area

print("AREA CALCULATOR")
print("1->circle")
print("2->triangle")
print("3->parallogram (square,rectancle,any other polygons")
print("4->regular polygons")
choice=int(input("enter choice:))
if choice==1:
  print(circle())
elif choice==2:
  print(triangle())
elif choice==3:
  print(llgram())
elif choice==4:
  print(regular())
else:
  print("invalid option")
