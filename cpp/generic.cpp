#include<iostream>
using namespace std;

template <typename T> T Sum(T a,T b){
   return a+b;
}
int main(){
   cout<< "Int Sum"<< Sum<int>(10,20) <<endl;
   cout<< " Flaot sum "<< Sum<float>(2.5,3.1) <<endl;
   return 0;
}