#include<iostream>
using namespace std;

class test1{
   int a,b;
   public:
   getAb(){
      cout<<"Enter Value for A : "<<endl;
      cin>>a;
      cout<<"Enter Value for B :"<<endl;
      cin>>b;
   }
   friend class test2;
};

class test2{
   public:
   void putAb(test1 t1){
      cout<<"Value of A : "<<t1.a<<endl;
      cout<<"Value of B : "<<t1.b<<endl;
   }
};

int main(){
   test1 t1;
   test2 t2;
   t1.getAb();
   t2.putAb(t1);
   return 0;
}
