#include<iostream>
using namespace std;

class Sample;

class Sample_1{
   int a;
   public:
   void get_a(){
      cout<<"Get Value for A in Sample_1 : "<<endl;
      cin>>this->a;

   }
   friend void big(Sample, Sample_1);
   
};

class Sample{
   int a;
   public:
   void get_a(){
      cout<<"Get Value for A in Sample class"<<endl;
      cin>>this->a;
   }
   friend void big(Sample, Sample_1);

};
void big(Sample s, Sample_1 s1){
    if(s.a<s1.a){
      cout<<"sample_1 Class A is Big"<<endl;
    }else if(s.a>s1.a){
      cout<<"Sample Class A is Big "<<endl;
    }else cout<<"Both are same"<<endl;
}

int main(){
   Sample S;
   Sample_1 S1;
   S.get_a();
   S1.get_a();
   big(S,S1);
   return 0;
}