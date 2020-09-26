#include<iostream>
#include<conio.h>
 class HotelManagement
 {
 int age[3], room[1], phone[10];
 char name[30], address[40];

public:
  void main_welcome();
  void hotel_info();
  void service_portal();
  void get_avail();
  void features();
  void room_allocation();
  void display();
  void cancellation();
  void Room_Deallocation();
};

 void HotelManagement::main_welcome()
 {
   cout << "HOTEL MANAGEMENT SOFTWARE SOLUTIONS" << '\n';
   cout << "A perfect solution for Hotel Management services." << '\n';
   cout << "powered by Abhiarts" << '\n';
   cout << "License under GNU 2017-18" << '\n';
 }

 void HotelManagement::hotel_info()
 {

 }

void HotelManagement::service_portal()
{
  int choice;

  cout << "                                  SERVICE PORTAL                               " << '\n';
  cout << "===============================================================================" << '\n';
  cout << "+=+=+=+=+=+=+=+=+=+=+=+   Please select the options below   +=+=+=+=+=+=+=+=+=+" << '\n';
  while (choice!=9) {
  cout << "\n 1. Check Availability" << '\n';
  cout << "2. Features of Room" << '\n';
  cout << "3. Room Allocation" << '\n';
  cout << "4. Dispay Coustomer Details" << '\n';
  cout << "5. Room Deallocation" << '\n';
  cout << "6. Cancellation" << '\n';
  cout << "7. Exit" << '\n';
  cout << "Enter your desired Choice: " << '\n';
  cin >> choice;

  switch (choice) {
    }
  }
}

void HotelManagement::features()
{
  int option[5]={1,2,3,4,5};
  std::cout << "Type of Room" << '\n';
  std::cout << "1. Special Deluxe" << '\n';
  std::cout << "2. Deluxe" << '\n';
  std::cout << "3. General" << '\n';
  std::cout << "4. Couple" << '\n';
  std::cout << "5. Couple Deluxe" << '\n';
  std::cin >> option;
}

void HotelManagement::room_allocation()
{
  int yy,dd,mm,mem,nod,roomsno;

  cout << "Enter the no. of the choice of room:" << '\n';
  cin >> roomsno;
  cout << "Enter the name: " << '\n';
  cin >> name;
  cout << "Enter the age:" << '\n';
  cin >> age;
  cout << "Enter the phone no." << '\n';
  cin >> phone;
  cout <<"Nationality" << '\n';
  cin >> nation;
  cout << "Enter the no. of days you want to stay in a room" << '\n';
  cin >> nod;
  cout << "Enter the no. of member along with you" << '\n';
  cin >> mem;
  cout << "Enter  the date of arrival" << '\n';
  cout << "Year(yyyy): " << '\n';
  cin >> yy;
  cout << "Month(mm): " << '\n';
  cin >> mm;
  cout << "Day(dd): " << '\n';
  cin >> dd;
}

void HotelManagement::Display_coustomer_details()
{
  cout <<"Name: " <<name<< '\n';
  cout << "Age: " <<age<< '\n';
  cout << "Address: " <<address<<'\n';
  cout << "Nationality: " <<nation<< '\n';
  cout << "No. of days in hotel: " <<nod<< '\n';
  cout << "No. of members: " <<mem<<'\n';
  cout << "Date of Arrival" <<dd<<"/"mm<<"/"yy<< '\n';
}

void HotelManagement::Room_Deallocation()
 {
   int rno;
   char cname;
   std::cout << "Enter the room no.: " << '\n';
   std::cin >> rno;
   std::cout << "Enter the Customer name: " << '\n';
   std::cin >> cname;
   std::cout << "Room allocation in progress......." << '\n';
   std::cout << "Your total Bill Amount is:" << '\n';
}

void HotelManagement::cancellation()
{
  char bot;
  std::cout << "Enter the Room no. for Cancellation: " << '\n';
  std::cin >> rno;
  std::cout << "Do want to cancel (Y/N)" << '\n';
  std::cin >> bot;
}

void HotelManagement::rooms()
{


}

void HotelManagement::get_avail()
{

}
void main()
(
  clrscr();
  HotelManagement a;
  HotelManagement::service_portal().a;
  getch();

)
