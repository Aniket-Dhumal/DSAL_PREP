#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
typedef map<string,int> MapType;
MapType Population;
MapType::iterator iter;

Population.insert(pair<string,int>("Maharashtra",102212656));
Population.insert(pair<string,int>("Haryana",102212656));
Population.insert(pair<string,int>("Assam",102212656));
Population.insert(pair<string,int>("Odisa",102212656));
Population.insert(pair<string,int>("Tamilnadu",102212656));
Population.insert(pair<string,int>("Andhrapradesh",102212656));
Population.insert(pair<string,int>("Telangana",102212656));
string state;
cout<<"Enter the name of state"<<endl;
cin>>state;
iter=Population.find(state);
if(iter != Population.end()){
   cout<<"Population of state "<<iter->second<<endl;

}else{ cout<<"Not Available"<<endl;}
}