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
   float real,img;
   public:
   //default constructor 
   complex(){
      real=0.0;
      img=0.0;
   }
// overloading << operator 
   friend ostream & operator << (ostream &os, complex num){
      os<<num.real<<"+"<<num.img<<"i"<<endl;

   }
// Overloading >> Operator 
friend istream & operator >> (istream &in , complex &num){
   cout<<"Enter Real part of Number "<<endl;
   in>>num.real;
   cout<<"Enter Iamgenery part of Number "<<endl;
   in>>num.img;
}

// Overloading + Operator 
complex operator + (complex c){
   complex temp;
   temp.real=this->real+c.real;
   temp.img=this->img+c.img;
   return temp; 
}
//overloading * Operator 
complex operator * (complex c){
   complex temp;
   temp.real=this->real*c.real;
   temp.img=this->img*c.img;
   return temp; 
}

};

int main(){
   complex c,c1;
   int choice;

//Menu 
cout<< "  Choose option from Below : "<<endl;
cout<< "  1 Addition "<<endl;
cout << " 2 Multiplication "<<endl;
cout<< "  Enter Your choice " <<endl; 
cin>>choice;

// Actions for Menues 
switch (choice)
{
case 1:
   cin>>c;
   cin>>c1;
   cout<<c+c1;
   break;
case 2:
   cin>>c;
   cin>>c1;
   cout<<c*c1;
   break;

default: cout<<"Enter Valid Choice "<<endl;
   break;
}




   return 0;
}
