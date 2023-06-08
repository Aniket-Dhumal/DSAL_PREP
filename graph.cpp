#include <iostream>
#include<string.h>
using namespace std;
class Node
{
public:
	char data[10];
	Node *down;
	Node *next;
}*head;

class stack
{
public:
	char vertex[10];
	int in_stack(char node[]);
}stk[10];

int stack::in_stack(char node[])
{
	int i,present=0;
	for( i=0;i<10;i++)
	{
		if(strcmp(stk[i].vertex,node)==0)
			present=1;
	}
	return present;
}

class queue
{
public:
	char vertex[10];
	int in_queue(char node[]);
}que[10];

int queue::in_queue(char node[])
{
	int i,present=0;
	for( i=0;i<10;i++)
	{
		if(strcmp(que[i].vertex,node)==0)
			present=1;
	}
	return present;
}

class graph:public Node,public stack,public queue
{
	public:
		Node* create_graph(Node* head);
		void display_graph();
		void BFS();
		void DFS();
		void degree();
};
Node* graph::create_graph(Node* head)
{
	int i,j,ver,adj;
	Node *temp,*move,*newnode;
	cout<<"How many Vertices:";
	cin>>ver;
	for(i=0;i<ver;i++)
	{
		newnode=new Node;
		cout<<"Enter the Name of Vertex:";
		cin>>newnode->data;
		newnode->next=NULL;
		newnode->down=NULL;
		if(head==NULL)
		{
			head=newnode;
			move=temp=head;
		}
		else
		{
			move->down=newnode;
			move=move->down;
			temp=move;
		}
		
		cout<<"How many adjacent vertices:";
		cin>>adj;
		for(j=0;j<adj;j++)
		{
			newnode=new Node;
			cout<<"Enter the name of adjacent vertex:";
			cin>>newnode->data;
			newnode->next=NULL;
			newnode->down=NULL;
			temp->next=newnode;
			temp=newnode;
		}
	}
	return head;
}
void graph :: display_graph()
{
	Node *temp, *move;

	cout<<"\n\n Vertex :--> Adjacent Vertices....";
	move = head;
	while(move != NULL)
	{
		cout<<"\n"<<move->data<<" : ";
		temp = move->next;
		while(temp != NULL)
		{
			cout<<"-->"<<temp->data;
			temp = temp->next;
		}
		move = move->down;
	}
}

void graph :: DFS()
{
	Node *temp;
	int done, top = -1;

	temp = head;
	if(!(in_stack(temp->data)))
	{
		top++;
		strcpy(stk[top].vertex , temp->data);
		cout<<"DFS: "<<stk[top].vertex;

		while(top != -1)
		{
			temp = head;
			while(strcmp(stk[top].vertex , temp->data) != 0)
				temp = temp->down;

			temp = temp->next;
			done = 0;

			while(temp != NULL && done == 0)
			{

				if(!(in_stack(temp->data)))
				{
					top++;
					strcpy(stk[top].vertex , temp->data);

					cout<<", "<<stk[top].vertex;

					done = 1;
				}
				else
					temp = temp->next;
			}
			if(temp == NULL)
				top--;

		}
	}
	else
	{
		cout<<"\n\t Can not start DFS from Vertex: "<<temp->data;
	}


}


void graph :: BFS()
{
	Node *temp;
	int front, rear;
	front = rear = -1;

	temp = head;
	if(!(in_queue(temp->data)))
	{
		rear++;
		strcpy(que[rear].vertex , temp->data);

		cout<<"BFS: "<<que[rear].vertex;

		while(front != rear)
		{
			temp = head;
			front++;
			while(strcmp(que[front].vertex , temp->data) != 0)
					temp = temp->down;

			temp = temp->next;

			while(temp != NULL)
			{

				if(!(in_queue(temp->data)))
				{
					rear++;
					strcpy(que[rear].vertex , temp->data);

					cout<<", "<<que[rear].vertex;
				}
				else
					temp = temp->next;
			}
		}
	}
	else
	{
		cout<<"\n\t Can not start DFS from Vertex: "<<temp->data;
	}
}


void graph :: degree()
{
	Node *temp, *move;
	int cnt, flag = 0;

	cout<<"\n\n Vertex : Degree....";

	move = head;
	while(move != NULL)
	{
		cout<<"\n"<<move->data<<" : ";

		temp = move->next;
		cnt = 0;

		while(temp != NULL)
		{
			cnt++;
			temp = temp->next;
		}
		cout<<" "<<cnt;
		if(cnt == 0)
			flag = 1;
		move = move->down;
	}
	if(flag == 0)
		cout<<"\n\n As all Vertices has Degree > 0, the Graph is Connected.";
	else
		cout<<"\n\n As some Vertices has Degree = 0, the Graph is Disconnected.";
}


int main()
{
	graph g1;
	head=NULL;
	int ch;
	do
	{
		cout<<"\n**********MENU*********";
		cout<<"\n1.Create Graph";
		cout<<"\n2.Display Graph";
		cout<<"\n3.DFS Traversal";
		cout<<"\n4.BFS Traversal";
		cout<<"\n5.Degree";
		cout<<"\n6.Exit";
		cout<<"\nEnter your choice:";
		cin>>ch;
		switch(ch)
		{
		case 1:
			head=g1.create_graph(head);
			break;
		case 2:
			g1.display_graph();
			break;
		case 3:
			g1.BFS();
			break;
		case 4:
			g1.DFS();
			break;
		case 5:
			g1.degree();
		case 6 :
			cout<<"Thank you for using this program!";
			exit(0);
			break;
		default:
			cout<<"Enter correct choice"<<endl;
			break;
		}
	}while(ch!=7);
	return 0;
}

