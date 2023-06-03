//============================================================================
// Name        : Linked_List.cpp
// Author      : Aniket Dhumal
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
//Node Class
class node{
         //public:
	     int data;
	     node* next;

	     node(int x){
	    	 data = x;
	    	 next = NULL;
	     }
	friend class LL;
};

class LL{
public:
	node* head = NULL;

	//Insert at Tail
	void InsertAtTail(int val){
		node* n = new node(val);
		node* temp = head;
		if(head == NULL){
			head = n;
			return;
			}
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = n;
     }

	//Insert at Head
	void InsertAtHead(int val){
		node* n = new node(val);
		if(head == NULL){
			head = n;
			return;
		}
		n->next =head;
		head = n;
		}

	// Display
	void display(){
		node* temp =  head;
		if(head == NULL){
			cout<<"List is Empty "<<endl;
			return;
		}
		while(temp->next != NULL){
			cout<<temp->data<<"--->";
			temp = temp->next;
		}
		cout<<temp->data;

	}

	//Search
	node* search(int key){
		node* temp = head;
		while(temp->next != NULL){
			if(temp->data == key){
				cout<<"Key is Found Node Returned"<<endl;
				return temp;
				}
			temp = temp->next;
			}
		cout<<"Key is Not Available"<<endl;
		return NULL;
	}

	// Delete
	void Delete(int key){
		node* temp = head;
		if(head == NULL){
			cout<<"List is Empty "<<endl;
		}
		while(temp->next->data != key){
			temp= temp->next;
			if(temp == NULL){
				cout<<" Key not present "<<endl;
				return;
				}
			}
		node * todelete = temp->next;
		temp->next = todelete->next;
		delete todelete;

	}

};

int main() {\
	LL list;
	int choice,x;
    do{
    	cout<<"    Menu"<<endl;
    	cout<<"    1. Insert At Head "<<endl;
    	cout<< "   2. Insert At Tail "<<endl;
    	cout<<"    3. Delete Node"<<endl;
    	cout<<"    4. Search "<<endl;
    	cout<<"    5. Display "<<endl;
    	cout<<"    6. Exit Program"<<endl;
    	cout<<"Enter your Choice : ";
    	cin>>choice;

    	switch(choice){
    	case 1: cout<<"Enter Value to Insert : "; cin>>x; list.InsertAtHead(x);
    		break;
    	case 2: cout<<"Enter Value to Insert : "; cin>>x; list.InsertAtTail(x);
    	   break;
    	case 3: cout<<"Enter Key to Delete : ";cin>>x;list.Delete(x);
    	   break;
    	case 4: cout<<"Enter Key to Search : "; cin>>x; list.search(x);
    	  break;
    	case 5: list.display();
    	  break;
    	case 6: cout<<"Exiting......Program........"<<endl;
    	  break;
    	default : cout<<"Enter Valid Choice "<<endl;

    	}

    }while(choice != 6);
	return 0;
}
