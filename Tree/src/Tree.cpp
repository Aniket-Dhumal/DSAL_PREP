//============================================================================
// Name        : Tree.cpp
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
	node* right;
	node(int a){
		data = a;
		left = NULL;
		right = NULL;
	}
};

void Build(node* &root){
	queue<node*>q;
	int val,ldata,rdata;
	cout<<"Enter Data for Root :  ";
	cin>>val;
	root = new node(val);
	q.push(root);

	while(!q.empty()){
      node* temp = q.front();
      q.pop();

      cout<<"Enter Value for left Child of  "<<temp->data;
      cin>>ldata;
      if(ldata != -1){
    	  temp->left = new node(ldata);
    	  q.push(temp->left);
      }

      cout<<"Enter Value for right child of : "<<temp->data;
      cin>>rdata;
      if(rdata != -1){
    	  temp->right = new node (rdata);
    	  q.push(temp->right);
      }

	}

}

void Inorder(node* root){
	if(root == NULL){
	return;
	}
	Inorder(root->left);
	cout<<root->data<<" " ;
	Inorder(root->right);
}

void nodeCount(node* root ,int &lcount, int &incount){
	if(root == NULL){
		return;
	}
	nodeCount(root->left,lcount,incount);
	if(root->left == NULL && root->right == NULL){
		lcount++;
	   }else{
		   incount++;
	   }
	nodeCount(root->right,lcount,incount);
}


int main() {
	int Leaf_Nodes  = 0; //var to store count of leaf nodes
	int Internal_Node = 0; // var to store count of Internal nodes
	node* Root;
	Build(Root);
    Inorder(Root);

	nodeCount(Root,Leaf_Nodes,Internal_Node);
    cout<<endl;
    cout<<"Count of Internal Nodes : "<<Internal_Node<<endl;
    cout<<"Count of Leaf Nodes : "<<Leaf_Nodes<<endl;
	return 0;
}
