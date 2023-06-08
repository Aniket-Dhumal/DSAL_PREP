#include<iostream>
using namespace std;

class test{
   public:
   int a,b;

   test(int a,int b){
        this->a=a;
        this->b=b;
   }

   test(test *old){
      a=old->a;
      b=old->a;

   }

   void print(){
      cout<<a<<endl<<b;
   }
};

int main(){
   test t(10,20);
   test t1(&t);
   t.print();
   t1.print();
}