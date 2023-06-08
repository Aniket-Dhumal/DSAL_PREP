#include<iostream>
using namespace std;

class Sample{
   int a,b;
   public:
   Sample(int a,int b){
      this->a=a;
      this->b=b;
   }
   Sample(Sample &old){
      a=old.a;
      b=old.b;

   }
   void print(){
      cout<<"Data in A : "<<this->a<<endl;
      cout<<"Data in B : "<<this->b<<endl;
   }
};
int main(){
   Sample obj1(10,20);
   obj1.print();
   Sample obj2(obj1);
   obj2.print();
   
   
  
}