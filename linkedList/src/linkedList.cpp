//============================================================================
// Name        : linkedList.cpp
// Author      : Aniket Dhumal
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class node{
	int data;
	node* next;
	node(int x){
		data = x;
		next = NULL;
	}
	friend class LL;
};

class LL{
	node* head;
    public:
	LL(){
		head = NULL;
	}

	//Insert at Tail
	void InsertAtTail(int x){
		node* n = new node(x);
		node* temp = head;
		if(head == NULL){
			head = n;
			return;
		}
		while(temp->next != NULL){
			temp=temp->next;
		}
		temp->next = n;
	}

	//insert at head
	void InsertAtHead(int x){
		node* n = new node(x);
		//node * temp = head;
		if(head == NULL){
			head = n;
			return;
		}
		n->next = head;
		head = n;
	}

	// Display
	void Display(){
		node* temp = head;
		while(temp->next != NULL){
			cout<<temp->data<<"-->";
			temp = temp->next;
		}
		cout<<temp->data<<"-->NULL"<<endl;
	}

	// Delete
	 void Delete(int key){
		 node* temp = head;
		 if(head == NULL){
			 cout<<"List is Empty"<<endl;
			 return;
		 }
		 while(temp->next->data != key){
			 if(temp->next == NULL){
				 cout<<"Key not Present"<<endl;
				 return;
			 }
			 temp = temp->next;
			 }
		 node* toDelete = temp->next;
		 temp->next = toDelete->next;
		 cout<<"Node Deleted "<<endl;
	 }

	  node* search(int key){
		  node* temp = head;
		  if(head == NULL){
			  cout<<"List is Empty "<<endl;
			  return NULL;
		  }
		  while(temp->data != key){
			  temp = temp->next;
			  if(temp->next == NULL){
				  cout<<"Key not Found "<<endl;
				  return NULL;
			  }
		  }
		  cout<<"Key found Node returned"<<endl;
		  return temp;
	  }

	  // Display

};

int main() {
      int x ,choice;
      LL list;

      do{
    	  cout<<"------------Menu----------------"<<endl;
    	  cout<<"     1. Insert At Head"<<endl;
    	  cout<<"     2. Insert At Tail"<<endl;
    	  cout<<"     3. Search"<<endl;
    	  cout<<"     4. Display"<<endl;
    	  cout<<"     5. Delete"<<endl;
    	  cout<<"     6. Exit"<<endl;
    	  cout<<"Enter Your Choice : ";cin>>choice;

    	  switch(choice){
    	  case 1: cout<<"Enter Element to Insert : ";cin>>x;list.InsertAtHead(x);
    		  break;
    	  case 2: cout<<"Enter Element to Insert : ";cin>>x;list.InsertAtTail(x);
    	      		  break;
    	  case 3: cout<<"Enter Element to search : ";cin>>x;list.search(x);
    	      		  break;
    	  case 4: list.Display();
    	      		  break;
    	  case 5: cout<<"Enter Element to delete  : ";cin>>x;list.Delete(x);
    	      		  break;
    	  case 6: cout<<"Exiting Program ..................."<<endl;
    	      		  break;
    	  default : cout<<"Enter Proper Choice"<<endl;
    	  }
      }while(choice != 6);


	return 0;
}
