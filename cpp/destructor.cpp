#include<iostream>
using namespace std;

class test{
   public:
   int a;
   test(int a){
      this->a=a;
      cout<<a<<endl;
   }

   ~test(){
      cout<<"Deleted A = "<<this-a<<"Destructor executed"<<endl;
   }
};

int main(){
   test t(20);
}