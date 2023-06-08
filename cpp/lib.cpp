#include<iostream>
#include<string>
using namespace std;

class student{
   public:
   string Name;
   int id;
   void setData(){
      cout<<"Enetr Name of Student :"<<endl;
      cin>>Name;
      cout<<"Enter Id"<<endl;
      cin>>id;
   }
   void getData(){
      cout<<"Name : "<<Name<<"\n Id: "<<id<<endl;
   }
};

class book{
   public: 
   string Name;
   string ISBN;
   float price;
   void setData(){
      cout<<"Enter Book Name"<<endl;
      cin>>Name;
      cout<<"Enter ISBN"<<endl;
      cin>>ISBN;
      cout<<"Enter Price"<<endl;
      cin>>price;
   }

};

int main(){
   
   bool flag = true;
   int choice;
   student s;
   book b;
   while(flag){
      Display_menu();
      menu(choice);
   }

void Display_menu(){
   cout<<" 1 : Enter Data for Student"<<endl;
   cout<<" 2 : Print Data of Student"<<endl;
   cout<<" 3 : Enter Data for Book "<<endl;
   cout<<" 4 : Print Data of Book"<<endl;
   cout<<" 5 : Terminate Program"<<endl;
   cin>>choice;
}

   void menu(int choice){
   switch (choice)
   {
   case 1:
      s.setData();
      break;
   case 2:
      s.getData();
      break;
   case 3: 
      b.setData();
      break;
   case 4:
      b.getData();
      break;
   case 5 :
        flag = false;
      break;
   
   default: cout<<"Enter Valid choice between 1 to 5"<<endl;
      break;
   }
}
}
