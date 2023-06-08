#include<iostream>
using namespace std;

class Office{
   public:
   int n;
   int graph[10][10];
   string office[10];

   void input(){
      cout<<"Enter the Number of offices : "<<endl;
      cin>>n;
      for(int i =0;i<n;i++){
         cout<<"Enter Name for Office : "<<i<<" : "<<endl;
         cin>>office[i];
      }
      cout<<"Enter the Cost to Connect Offices : "<<endl;

      for(int i=0;i<n;i++){
         for(int j=i;j<n;j++){
            if(i==j){
               graph[i][j]=0;
               continue;
            }
            cout<<"Enter the cost to join office : "<<office[i]<<" : & : "<<office[j]<<endl;
            cin>>graph[i][j];
            graph[j][i]=graph[i][j];
            

         }
      }
   }

   void Display(){
      for(int i=0;i<n;i++){
         cout<<endl;
         for(int j=0;j<n;j++){
            cout<<graph[i][j]<<"\t ";
         }
      }
   }

   void prims(){
      int minIndex,minCost=0,cost=0,visit[n],count=1;
      for(int i=0;i<n;i++){
         visit[i]=0;
      }
      visit[0]=1;
      while(1){
         minCost = 100000;
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               if(visit[i]==1 && visit[j] == 0 && graph[i][j]!=0 && graph[i][j]<minCost){
                  minCost = graph[i][j];
                  minIndex = j;
               }
            }
         }
         visit[minIndex]=1;
         cost = cost + minCost;
         count ++;
         if(count == n){break;}
      }
      cout<<"Minimum Cost is : "<<cost<<endl;
   }

};

int main(){
   Office office;
   office.input();
   office.Display();
   office.prims();

   return 0;
}