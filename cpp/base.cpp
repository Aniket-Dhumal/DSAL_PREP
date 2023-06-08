#include<iostream>
using namespace std;

class base2{
   public:
   void base2_print(){
      cout<<"Base 2 Class"<<endl;
   }

};
class base{
public:
void base_print(){
   cout<<"Base class"<<endl;
}
};

class child: public base,public base2{
   public:
   void print_child(){
      cout<<"Child Class"<<endl;
   }
};

int main(){
   child c;
   c.base_print();
   c.print_child();
   c.base2_print();
   return 0;
}