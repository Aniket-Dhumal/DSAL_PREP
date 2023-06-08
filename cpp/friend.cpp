#include<iostream>
using namespace std;
class test0;
class test{
   public:
   int a;
   void get_a(){
      cout<<"Enter Value for A "<<endl;
      cin>>a;

   }
   friend void big(test, test0);
};

class test0{
   public:
   int b;
   void get_b(){
      cout<<"Enter Value for B "<<endl;
      cin>>b;
   }
   friend void big(test, test0);
};

void big(test t,test0 t0){
   t.get_a();
   t0.get_b();
   if(t.a<t0.b)
      cout<<"B is big"<<endl;
   else if(t.a>t0.b)
      cout<<"A is Big"<<endl;
   else cout<<"Both are Equal";
}

int main(){
   test t;
   test0 t0;
   big(t,t0);
   
}