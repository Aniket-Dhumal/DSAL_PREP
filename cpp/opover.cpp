#include<iostream>
using namespace std;
class test{
   public:
   int a;
   test(int a){
      this->a=a;
      
   }
   bool operator == (test t1){
      if (a==t1.a){
         return true;

      }else return false;

   }

};

int main(){
  test t1(10),t2(20);
   if(t1==t2){
      cout<<"Both are equal "<<endl;
   }
   else cout<<"Both are unequal "<<endl;
}