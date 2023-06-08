#include<iostream>
using namespace std;

class test{
   static float a;
   public:

   test(){
      a++;
      cout<<"Object Created"<<endl;
      cout<<a<<endl;


   }

   ~test(){
      cout<<"Object deleted"<<endl;
   }
};

float test::a;
int main(){
   
   test a,b,c,k,l;
   //cout<<a.a;
}