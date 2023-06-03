//============================================================================
// Name        : Stack.cpp
// Author      : Aniket Dhumal
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define size 20

class stack{
	int *arr;
	int top;

public:
	stack(){
		arr = new int[size];
		top = -1;

	}

	void push(int x){
		if (top == size-1){
			cout<<"Stack is Full "<<endl;
        }else{
			top++;
			arr[top] = x;
			cout<<"Element Pushed Successfully"<<endl;
		}

	}

void pop(){
	if(top == -1){
		cout<<"Stack is Empty No element to pop";
	}
	else{
		cout<<"Element Popped Successfully"<<endl;
		cout<<arr[top];
		top--;
	}
}

bool empty(){
	return top == -1;
}

int Top(){
	if(top == -1 ){
		cout<<"Stack is Empty "<<endl;
		return -1;
	}else{
	return arr[top];
	}
}
};

int main() {
	int choice;
	stack s;

	do{
		cout<<"-----------Menu------------- "<<endl;
		cout<< "    1. Push "<<endl;
		cout<<"     2. Pop  "<<endl;
		cout<< "    3. Top "<<endl;
		cout<<"     4. Empty  "<<endl;
		cout<<"     5. Exit      "<<endl;
		cout<<"Enter your choice : ";
		cin>>choice;

		switch(choice){
		case 1:
			int x;
			cout<<"Enter Element to Push : ";
			cin>>x;
			s.push(x);
					break;
		case 2: s.pop();
		break;
		case 3: cout<<"Top : "<<s.Top();
		break;
		case 4:
			if(s.empty()){
				cout<<"Empty"<<endl;
			}else{
				cout<<"Not Empty"<<endl;
			}
			break;
		case 5: cout<<"Exiting Program ........"<<endl;
		break;

		}

	}while(choice != 5);

	return 0;
}
