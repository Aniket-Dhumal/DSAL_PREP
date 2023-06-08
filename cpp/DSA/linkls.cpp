#include<iostream>
using namespace std;
//class node 
class node{
   public:
   int data;
   node* next;
   // Constructor
   node(int d){
      data = d;
      next = NULL;
   }
};

void Insert(node* &Head, int val){
   node* n = new node(val);

if(Head == NULL ){
   Head->next = n;
}
else{
   node* temp = Head;
   while(temp->next != NULL){
      temp=temp->next;
   }
   temp->next = n;
}
}

   void Display(node* HEAD){
      node* temp = HEAD;
      while(temp->next != NULL){
         cout<<temp->data<<endl;
         temp=temp->next;
      }
   }


int main(){
   node* head = NULL;
    
   Insert(head,10);
   
   //Display(head);


   
   return 0;
}