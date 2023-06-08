/*
Implement a class Complex which represents a complex number Data type.
Implement the Following Operations  Format (0+0i)
Immplelent default constructor to invoke num as (0+0i)
1) Overload : 
            " << "  To print Complex numbers on screen.
            " >> "  To Take complex number as input from user 
            "  + "  To Perform Addition Operation
            "  - "  To Perform Subtraction Operation 
*/
#include<iostream>
using namespace std;

class complex{
   //Vars to store real & imagenery part of complex number 
   float real,img;
   // Default constructor to invoke vars with 0.0 values
   public:
  /* complex(){
      real=0.0;
      img=0.0;
   }*/

   //overload << operator to print complex num on Screen (format 0+0i)
   friend ostream & operator << (ostream &os,complex num){
      os<<num.real<<" + "<<num.img<<"i"<<endl;
   }
   //overloading >> operator
   friend istream & operator >> (istream &in, complex &num){
      cout<<"Enter Value for Real part : "<<endl;
      in>>num.real;
      cout<<"Enter Value for Imagenery part : "<<endl;
      in>>num.img;
   }
   //overloading + operator 
   complex operator + (complex &num){
      complex temp;
      temp.real=this->real+num.real;
      temp.img=this->img+num.img;
      return temp;
   }
   //overloding * operator 
   complex operator * (complex &num){
     complex temp;
     temp.real=this->real*num.real;
     temp.img=this->img*num.img;
      return temp;
     
   }



};
int main(){
   complex C,C2;
   int choice;
   char ch;
   while (true)
   {
      cout<<"Choose options from below : "<<endl;
      cout<<" 1 Addtion "<<endl;
      cout<<" 2 Multiplication "<<endl;
      cout<<" Enter your Choice : "<<endl;
      cin>>choice;
      
      switch (choice)
      {
      case 1:
         cin>>C>>C2;
         cout<<C+C2<<endl;
         break;
      case 2:
         cin>>C>>C2;
         cout<<C*C2<<endl;
         break;
      
      default:cout<<"Enter valid choice "<<endl;
         break;
      }
      cout<<"Do you want to continue? Y/N"<<endl;
      cin>>ch;
      if(ch=='N' || ch=='n'){
         break;
      }
   }
   

   return 0;
}