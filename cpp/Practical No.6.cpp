//**************DFS AND BFS TRAVERSAL*************
#include<iostream>
#include<string>
#define MAX_SIZE 100
using namespace std;
 int top;
 int st[10];
 class Queue
 {
public:
	 int front,rear;
	 int myqueue[MAX_SIZE];
	 Queue()
	 {
		 front=-1;
		 rear=-1;
	 }
	 void enQueue(int v)
	 {
		 if(isFull())
		 {
			 cout<<"Queu is full";
		 }
		 else
		 {
			 if(front==-1)
			 {
				 front=0;
			 }
			 rear++;
			myqueue[rear]=v;
		 }
	 }
	 bool isFull()
	 {
		 if(front==0 && rear==MAX_SIZE-1)
		 {
			 return true;
		 }
		 else
		 {
			 return false;
		 }
	 }
	 bool isEmpty()
	 {
		 if(front==-1)
		 {
			 return true;
		 }
		 else
		 {
			 return false;
		 }
	 }
	 int delQueue()
	 {
		 int value;
		 if(isEmpty())
		 {
			 cout<<"Queue is empty";
			 return -1;
		 }
		 else
		 {
			 value=myqueue[front];
			 if(front>=rear)
			 {
				 front=-1;
				 rear=-1;
			 }
			 else
			 {
				 front++;
			 }
		 }
		 return value;
	 }
 };

 class Node
 {
	 int des;
	 Node *next;
	 friend class Graph;
 public:
	 Node(int d=0)
 	 {
		 des=d;
		 next=NULL;
 	 }
 };

 class Graph
 {
	 int v;
	 int e;
	 Node **header;
	 bool *visit;
	 string *name;
 public:
	 Graph(int vert=0,int edge=0)
 	 {
		 v=vert;
		 e=edge;
		 header=new Node*[v];
		 visit=new bool[v];
		 name=new string[v];
		 for(int i=0;i<v;i++)
		 {
			 header[i]=NULL;
			 visit[i]=0;
			 name[i]="";
		 }
 	 }
	 void reset_visit()
	 {
		 for(int i=0;i<v;i++)
		 {
			 visit[i]=0;
		 }
	 }
	 int search(string key)
	 {
		 for(int i=0;i<v;i++)
		 {
			 if(name[i]==key)
			 {
				 return i;
			 }
		 }
	 }
	 void accept()
	 {
		 cout<<"Enter the name of all loacations:";
		 for(int i=0;i<e;i++)
		 {
			 cout<<"Location:"<<i+1<<" : ";
			 cin>>name[i];
		 }
		 for(int i=0;i<v;i++)
		 {
			 int src,dest;
			 string pos1,pos2;
			 cout<<"Enter Location 1:";
			 cin>>pos1;
			 cout<<"Enter Location 2:";
			 cin>>pos2;
			 src=search(pos1);
			 dest=search(pos2);
			 cout<<pos1<<" "<<src;
			 cout<<pos2<<" "<<dest;
			 Node *p=new Node(dest);
			 Node *q=new Node(src);
			 if(header[src]==NULL)
			 {
				 header[src]=p;
			 }
			 else
			 {
				 Node *temp=header[src];
				 while(temp->next!=NULL)
				 {
					 temp=temp->next;
				 }
				 temp->next=p;
			 }
			 if(header[dest]==NULL)
			 {
				 header[dest]=q;
			 }
			 else
			 {
				 Node *temp=header[dest];
				 while(temp->next!=NULL)
				 {
					 temp=temp->next;
				 }
				 temp->next=q;
			 }
		 }
	 }
	 void push(int v)
	 {
		 top++;
		 st[top]=v;
	 }
	 int pop()
	 {
		 int i;
		 i=st[top];
		 top--;
		 return i;
	 }
	 void DFS1(int v)
	 {
		 Node *temp;
		 push(v);
		 while(top!=-1)
		 {
			 v=pop();
			 if(visit[v]==false)
			 {
				 cout<<name[v]<<" ";
				 visit[v]=true;
			 }
			 temp=header[v];
			 while(temp!=NULL)
			 {
				 if(visit[temp->des]==false)
				 {
					 push(temp->des);
				 }
				 temp=temp->next;
			 }
		 }
	 }
	 void DFS(int v)
	 {
		 cout<<name[v]<<" ";
		 visit[v]=1;
		 Node *temp=header[v];
		 while(temp!=NULL)
		 {
			 int t=temp->des;
			 if(visit[t]==false)
			 {
				 DFS(t);
			 }
			 temp=temp->next;
		 }
	 }
	 void BFS(int v)
	 {
		 Queue q;
		 visit[v]=1;
		 q.enQueue(v);
		 cout<<name[v]<<" ";
		 while(!q.isEmpty())
		 {
			 Node *temp=header[v];
			 if(visit[v]==false)
			 {
				 cout<<name[v]<<" ";
				 visit[v]=1;
			 }
			 while(temp!=NULL)
			 {
				 if(visit[temp->des]==false)
				 {
					 q.enQueue(temp->des);
					 visit[temp->des]=1;
					 cout<<name[temp->des]<<" ";
				 }
				 temp=temp->next;
			 }
			 q.delQueue();
			 v++;
		 }
	 }
 };

int main()
{
    int a, b,s;
    cout << "Enter number of vertices: ";
    cin >> a;
    cout << "Enter number of edges: ";
    cin >> b;
    Graph g1(a, b);
    g1.accept();
    cout<<"DFS : ";
    cout<<"Enter start index:";
    cin>>s;
    g1.DFS1(s);
    g1.reset_visit();
    cout <<"\nBFS : ";
    cout<<"\nEnter start index:";
    cin>>s;
    g1.BFS(s);
    return 0;
}

