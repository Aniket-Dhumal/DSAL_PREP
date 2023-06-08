#include<iostream>
#include<string>
using namespace std;

class Student{
   int id;
   string Name;
   float Fees;
   public:
   bool flag = true;
   public:
   void setData(){
      cout<<"Enter Name : "<<endl;
      cin>>Name;
      cout<<"Enter Id"<<endl;
      cin>>id;
      cout<<"Fees paid"<<endl;
      cin>>Fees;

   }
   void Display();
   void Menu(int case_value){
   switch (case_value)
   {
   case 1:
      setData();
      break;
   case 2:
      Display();
      break;
   case 3:
      flag = false;
      break;
   default:
      cout<<"Please Enter Valid Choice"<<endl;
      break;
   }
}

};
void Student::Display(){
   cout<<"Name of Student: "<<Name<<endl;
   cout<<"Id: "<<id<<endl;
   cout<<"Fees Paid"<<Fees<<endl;
}



int main(){
   Student s;
   
   int choice_value;
   while(s.flag){
   cout<<"Choose Operation"<<endl;
   cout<<" 1 : Set Values For Student"<<endl;
   cout<<" 2 : Display Student Values"<<endl;
   cout<<" 3 : Terminate Program"<<endl;
   cin>>choice_value;
   s.Menu(choice_value);
   }
   return 0;
}