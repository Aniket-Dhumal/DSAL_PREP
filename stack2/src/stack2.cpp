//============================================================================
// Name        : stack2.cpp
// Author      : Aniket Dhumal
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define size 20

class Stack{
	int* arr;
	int top;
    public:

	Stack(){
		arr = new int[size];
		top = -1;

	}

	void push(int x){
		if(top == size - 1){
			cout<<"Stack is Full "<<endl;
		}else{
			top++;
			arr[top] = x;
			cout<<"Element Pushed Successfully "<<endl;
		}
	}

	void pop(){
		if(top == -1){
			cout<<"Stack is Empty No Element to pop"<<endl;

		}else{
			cout<<"Element Popped Successfully : "<<arr[top]<<"  :   "<<endl;
			top--;
		}
	}

	int Top(){
		if(top == -1 ){
			cout<<"List is Empty "<<endl;
			return -1;
		}else{
			return arr[top];
		}
	}

	bool empty(){
		if(top == -1 ){
			cout<<"Stack is Empty "<<endl;
			return true;
		}else{
			cout<<"stack has Elements "<<endl;
			return false;

		}
	}
};

int main() {
	int choice;
	Stack S;
	do{
		cout<<"Menu"<<endl;
		cout<<"1 Push"<<endl;
		cout<<"2 Pop"<<endl;
		cout<<"3 Empty"<<endl;
		cout<<"4 Top"<<endl;
		cout<<"5 Exit "<<endl;
		cout<<"Enter Your Choice : ";
		cin>>choice;

		switch(choice){
		case 1 : cout<<"Enter Element to Push : ";
		            int temp;
		            cin>>temp;
		            S.push(temp);
		            break;
		case 2 : S.pop();
		            break;
		case 3 : S.empty();
		            break;
		case 4:cout<< S.Top()<<endl;
		          break;
		case 5: cout<<"Exiting Program ........................"<<endl;
		          break;
		default : cout<<"Please Enter Valid Choice "<<endl;
		}

	}while(choice != 5 );
	return 0;
}
