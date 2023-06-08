#include<iostream>
using namespace std;
 class test{
   int a;
   public:
   void get(){
      cin>>a;
   }

   void operator ==(test t){
      if(this->a==t.a){
         cout<<"both are equal"<<endl;
      }else cout<<"Not Equal"<<endl;
   }
 };

 int main(){
   test t1,t2;
   cout<<"Enter Value for T1 object :"<<endl;
   t1.get();
   cout<<"Enter Value for T2 object :"<<endl;
   t2.get();
   t1==t2;

}