#include<iostream>
using namespace std;
class test{
   int a;
   public:
   void set(){
      
      cout<<"Get Value for A : "<<endl;
      cin>>a;
   }
   friend class test1;
};

class test1{
   public:
void get(test t){
   cout<<"Printing form another class "<<endl;
cout<<t.a;

}
};

int main(){
   test t;
   test1 t1;
   t.set();
   t1.get(t);
   return 0;
}