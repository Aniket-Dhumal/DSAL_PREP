#include<iostream>
using namespace std;

class test{
   static int a;
   public:
   test(){
      cout<<"Class Created "<<endl;
      a++;
      cout<<a<<endl;
   }
   ~test(){
      cout<<"Class Deleted "<<endl;
   }

};

int test::a;

int main(){
   test t,k,l,j;

}