#include<iostream>
using namespace std;

class Access{
   private:
   int a =10;
   void show(){
      cout<<"Value : "<<this->a<<endl;
   }

   public:
   void call(){
      show();
      printf("Show Executed");
   }

};

int main(){
   Access a;
   a.call();
   return 0;

}