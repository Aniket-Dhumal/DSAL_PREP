//============================================================================
// Name        : Binary_Tree.cpp
// Author      : Aniket Dhumal
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<queue>
using namespace std;


class node{
public:
	int data;
	node* left;
	node * right;

	node(int val){
		this->data = val;
		this->left = NULL;
		this->right = NULL;
	}
};

void buildTree(node* &root){
	cout<<"If Node Dosen't has child please Enter -1"<<endl;
	queue<node*> q;
	int Data;
	
    cout<<"Enter Value for Root : "<<endl;
    cin>>Data;
    root = new node(Data);
    q.push(root);

    while(!q.empty()){
    	node* temp = q.front();
    	q.pop();
         int LeftData;
         int RightData;
    	cout<<"Enter Data For Left Node of "<<temp->data;
    	cin>>LeftData;
    	if(LeftData != -1){
    		temp->left = new node(LeftData);
    		q.push(temp->left);
    	}

    	cout<<"Enter Data for Right Node of "<<temp->data;
    	cin>>RightData;
    	if(RightData != -1){
    		temp->right = new node(RightData);
    		q.push(temp->right);
    	}
    }

}

void Inorder(node* root){
	if(root == NULL){
		return;
	}
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}


void Preorder(node* root){
	if(root == NULL){
		return;
	}
	cout<<root->data<<" ";
	Preorder(root->left);
	Preorder(root->right);
}

void Postorder(node* root){
	if(root == NULL){
		return;
	}
	Postorder(root->left);
	Postorder(root->right);
	cout<<root->data<<" ";
}


void nodeCount(node* root, int &Lcount, int &Incount){
     if(root == NULL){
    	 return;
     }
	nodeCount(root->left,Lcount,Incount);
	if(root->left == NULL && root->right == NULL){
		Lcount++;
	}else{
		Incount++;
		}
	nodeCount(root->right,Lcount,Incount);



}


int main() {
	node* Root;
	buildTree(Root);
	cout<<"Inorder Traversal : ";
	Inorder(Root);
	cout<<endl;
	cout<<"Preorder Traversal  : ";
	Preorder(Root);
	cout<<endl;
	cout<<"Postorder Traversal : ";
	Postorder(Root);

	int Lcount = 0;
	int Incount = 0;

	nodeCount(Root,Lcount,Incount);
	cout<<Incount<<endl;
	cout<<Lcount<<endl;





	return 0;
}
