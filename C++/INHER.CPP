#include<iostream.h>
#include<conio.h>
//Base Class
class basicinfo
{
protected:
char name, gender;
int empid;
public:
void getinfo()
{
cout<<"Enter the name: "<<endl;
cin>>name;
cout<<"Enter Employee Id: "<<endl;
cin>>empid;
cout<<"Gender(M/F): "<<endl;
cin>>gender;
}
};

//Base Class
class workinfo
{
protected:
char dept;
int hrs;
public:
void wrkinfo()
{
cout<<"Enter the Respective Department"<<endl;
cin>>dept;
cout<<"Enter no. of hours of work: "<<endl;
cin>>hrs;
}
};

//Derived Class
class employee:public basicinfo, public workinfo
{
void empinfo()
{
cout<<"enter Employee Basic Information: "<<endl;
void basicinfo(); //calling the public member function of base class
cout<<"Enter Employee's Work Information: "<<endl;
void wrkinfo(); //calling the public member function of base class
}
void printinfo()
{
cout<<"Employee's Information is: "<<endl;
cout<<"Basic Information: "<<endl;
cout<<"Name: "<<name<<endl;
cout<<"Employee ID: "<<empid<<endl;
cout<<"Gemder: "<<gender<<endl;
cout<<"Work Information: "<<endl;
cout<<"Department Name: "<<dept<<endl;
cout<<"No. of Hours: "<<hrs<<endl;
}
};

 void main()
 {
 //Creating object of Derived class employee
 employee obj;
 obj.empinfo();
 obj.printinfo();
 }