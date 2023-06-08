#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;

class Student{
   string Name,Course;
   float Fees;
   public:
   Student(string Name, string Course){
      this->Name=Name;
      this->Course=Course;
   }
   Student(string Name, string Course, float Fees){
     // Student::(Name,Course);
      this->Name=Name;
      this->Course=Course;
      this->Fees=Fees;
      
   }
   void Display(){
      cout<<"Name : "<<this->Name<<endl;
      cout<<"Course : "<<this->Course<<endl;
      cout<<"Fees : "<<this->Fees<<endl;

   }
};

int main(){
   Student s("Aniket Dhumal", "Computer Engg",20000);
   s.Display();
   Student s2("Sakshi Vaidya","Computer Engg");
   s2.Display();
   return 0;
}