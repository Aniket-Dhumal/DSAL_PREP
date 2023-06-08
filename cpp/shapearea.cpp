#include<iostream>
using namespace std;

class area{
   public:
   int r,w,h;
   public:
   area(){ //Default Constructor
      r=5;
      cout<<"Default Executed"<<endl;
   }
   area(int r){ // Parameterized Constructor
      this->r=r;
      cout<<"Area circle = "<<3.14*(r*r)<<endl;
   }
   area(int h,int w){ // Overloded Parameterized Constructor
      this->h=h;
      this->w=w;
      cout<<"Area Rectangle = "<<w*h<<endl;
   }
};

int main(){
   area Test;
   area Circle(7);
   area Rect(10,20);
   cout<<Test.r<<endl;
   cout<<Circle.r<<endl;
   cout<<"L and B = "<<Rect.w<<" & "<<Rect.h<<endl;
}