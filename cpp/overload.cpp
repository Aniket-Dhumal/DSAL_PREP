#include<iostream>
using namespace std;

class complex{
   public: 
   float real,img;

   //Default Constructor 
   complex(){
      real = 0.0;
      img = 0.0;
   }

   // Overload >> operator
   friend istream void operator >>(istrem is ,complex obj){
   cout<<"Enter Real Part of complex number : "<<endl;
   cin>>obj.real;
   cout<<"Enter Imagenery Part of complex number : "<<endl;
   cin>>obj.img;
   }

};