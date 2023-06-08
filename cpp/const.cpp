#include<iostream>
using namespace std;

class test{
   public:
   static int a;
   static void print(){
      cout<<"Static Function"<<endl;
   }
   void send(){
      cout<<"Value of A is : "<<a<<endl;
   }
};
int test::a=20;

int main(){
   test k,b,c;
   k.send();
   b.send();
   c.send();
   k.print();
}
