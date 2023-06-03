//============================================================================
// Name        : queue.cpp
// Author      : Aniket Dhumal
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define size 10

class queue{
	int front,back;
	int* arr;

    public:
	queue(){
		arr = new int[size];
		front = back = -1;
	}

	void enqueue(int x){
		if(front == -1 ){
			front ++;
		}
		back++;
		arr[back] = x;
	}

	void dequeue(){
		if(front>back || front == -1 || back == -1){
			cout<<"No Element to pop Queue is  Empty. "<<endl;
		}else{
			front++;
		}
	}

	void peek(){
		cout<<"Element at peek is  :  "<<arr[front]<<endl;
	}

	bool empty(){
		if(front == -1 || back == -1 || front > back ){
			cout<<"Empty Queue"<<endl;
			return true;
		}else{
			cout<<"Not Empty "<<endl;
			return false;
		}
	}

};

int main() {
	int choice,x;
	queue q;

	do{
		cout<<"-------------------- MENU -----------------"<<endl;
		cout<<"   1.   Enqueue      "<<endl;
		cout<<"   2.   Dequeue      "<<endl;
		cout<<"   3.   Peek            "<<endl;
		cout<<"   4.   Empty         "<<endl;
		cout<<"   5.   Exit             :" <<endl;
		cout<<"Enter your choice  :  ";
		cin>>choice;
		cout<<endl;

		//Switch case
		switch(choice){
		case 1: cout<<"Enter Element to Insert : ";
		            cin>>x;
		            q.enqueue(x);
		            break;
		case 2: q.dequeue();
		            break;
		case 3: q.peek();
		           break;
		case 4: q.empty();
		            break;
		case 5:  cout<<"Exiting Program .............."<<endl;
		             break;
		default : cout<<"Enter valid choice "<<endl;

		}




	}while(choice != 5 );



	return 0;
}
