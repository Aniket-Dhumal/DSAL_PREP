#include<iostream>
using namespace std;

class test{
   int a,b;
   public:
   void allocate(int a, int b){
      this->a=a;
      this->b=b;
   }
   void display(){
      cout<<"Value of A : "<<this->a<<"  Value of B : "<<this->b;
   }
};

int main(){
   test t,k;
   t.allocate(10,20);
   t.display();
   k.allocate(78,56);
   k.display();
   return 0;
}