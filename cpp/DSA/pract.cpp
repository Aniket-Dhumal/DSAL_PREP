#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Node
{
private:
	Node *lchild,*rchild;
	string key,meaning;
public:
	friend class Dictionary;
	Node()
	{
		key="";
		meaning="";
		lchild=NULL;
		rchild=NULL;
	}
	Node(string key,string meaning)
	{
		this->key=key;
		this->meaning=meaning;
		lchild=NULL;
		rchild=NULL;
	}
};

class Dictionary
{
private:
	Node *root;
public:
	Dictionary()
	{
		root=NULL;
	}
	Node *getRoot();
	void insertnode(string key,string meaning);
	int search(string key,Node *&curr,Node *&parent);
	void deletenode(string key);
	void update(string key);
	void ascending_rec(Node *rnode);
	void descending_rec(Node *lnode);
	void min(Node *left);
	void max(Node *right);
};

Node* Dictionary::getRoot()
{
	return root;
}

int Dictionary::search(string key,Node *&curr, Node *&parent)
{
	int cnt=0;
	while(curr!=NULL)
	{ // cout<<"Entered into Search While loop"<<endl;
		cnt++;
		if(curr->key==key)
			return cnt;
		else if(curr->key<key)
		{
			parent=curr;
			curr=curr->rchild;
		}
		else
		{
			parent=curr;
			curr=curr->lchild;
		}
	}
	return cnt;
}

void Dictionary::insertnode(string key,string meaning)
{
	Node *curr=root;
	Node *parent=NULL;
	int c;
	Node *newnode=new Node(key,meaning);

	if(root==NULL)
		root=newnode;

	else
	{
		c=search(key,curr,parent);
		if(curr==NULL)
		{
			if(parent->key<key)
				parent->rchild=newnode;
			else
				parent->lchild=newnode;
		}
		else
			cout<<"Key having value "<<key<<" is already Present."<<endl;
	}
}

void Dictionary::ascending_rec(Node *rnode)
{
	if(rnode)
	{
		ascending_rec(rnode->lchild);
		cout<<"Key: "<<rnode->key<<endl<<"Meaning: "<<rnode->meaning<<endl;
		ascending_rec(rnode->rchild);
	}
}

void Dictionary::descending_rec(Node *lnode)
{
	if(lnode)
	{
		descending_rec(lnode->rchild);
		cout<<"Key: "<<lnode->key<<endl<<"Meaning: "<<lnode->meaning<<endl;
		descending_rec(lnode->lchild);
	}
}

void Dictionary::min(Node *left)
{
	while(left!=NULL)
	{
		left=left->lchild;
	}
	cout<<"Minimum Value Keyword is: "<<left->key;
}

void Dictionary::max(Node *right)
{
	while(right!=NULL)
		right=right->rchild;
	cout<<"Maximum Value Keyword is: "<<right->key;
}

void Dictionary::deletenode(string key)
{
	Node *curr=root;
	Node *parent=NULL;
	Node *child;
	int flag=0;

	if(root==NULL)
		cout<<"No Data is Inserted !"<<endl;

		flag=search(key,curr,parent);

		//key has both right and left child
		if(curr->rchild!=NULL && curr->lchild!=NULL)
		{
			Node *cs=curr->rchild;
			parent=curr;
			while(cs->lchild!=NULL)
			{
				parent=cs;
				cs=cs->lchild;
			}
			curr->key=cs->key;
			curr->meaning=cs->meaning;
			curr=cs;
		}

		//No Child i.e. key is a leaf node
		else if(curr->lchild==NULL && curr->rchild==NULL)
			child=NULL;

		//Key has right child
		else if(curr->rchild!=NULL && curr->lchild==NULL)
			child=curr->rchild;

		//key has left child
		else if(curr->rchild==NULL && curr->lchild!=NULL)
			child=curr->lchild;

		if(parent!= NULL)
		{
			if(curr == parent->lchild)
			{
				parent->lchild = child;
			}
			else
			{
				parent->rchild = child;
			}
		}
		else
		{
			root = child;
		}
		cout<<"Element deleted : "<<key;
		cout<<"\nRoot is : "<<root->key;
		free(curr);
}

void Dictionary::update(string key)
{
	Node *curr=root;
	Node *parent=NULL;
	string newkey,newmean;
	int flag;

	flag=search(key,curr,parent);
	if(curr==NULL)
		cout<<"Key is not Present !"<<endl;
	else
	{
		cout<<"Enter new Key: ";
		cin>>newkey;
		cout<<"Enter meaning: ";
		cin>>newmean;
		insertnode(newkey,newmean);
		deletenode(key);
	}
}

int main()
{
	char ans;
	string key,delkey,mean,srch,val;
	int ch1,ch2,cnt;

	Dictionary d;
	Node *rt=d.getRoot();
	Node *par=NULL;
	do
	{
		cout<<"****MENU******"<<endl;
		cout<<"1.Creation \n2.Deletion \n3.Updation \n4.Search a Keyword \n5.Traversal \n6.Minimum's Keyword Value \n7.Maximum Keyword's Value \n8.Exit"<<endl;
		cout<<"Enter Your Choice's Number: ";
		cin>>ch1;

		switch(ch1)
		{
		case 1: cout<<"Enter Keyword's Value: ";
				cin>>key;
				cout<<"Enter Meaning: ";
				cin>>mean;
				d.insertnode(key, mean);
				break;

		case 2: cout<<"Enter Value of Keyword to be Deleted: ";
				cin>>delkey;
				d.deletenode(delkey);
				break;

		case 3: cout<<"Enter Value of Keyword to be Updated: ";
				cin>>val;
				d.update(val);
				break;

		case 4: cout<<"Enter Key value to be searched: ";
				cin>>srch;
				cnt=d.search(srch,rt,par);
				if(cnt==0)
					cout<<"Key is not present."<<endl;
				else
					cout<<"Key is Found after "<<cnt<<" number of comparisons."<<endl;
				break;

		case 5: cout<<"1.Ascending Order"<<endl<<"2.Descending Order"<<endl<<"Enter Choice: ";
				cin>>ch2;
				if(ch2==1)
					d.ascending_rec(d.getRoot());
				else
					d.descending_rec(d.getRoot());
				break;
		}

		cout<<"Do you want to continue ? Y/N";
		cin>>ans;
	}while(ans=='y' || ans=='Y');

	return 0;
}