#include<iostream>
using namespace std;
int main(){
   int n,r,c;
   cout<<"Enter Rows "<<endl;
   cin>>r;
   cout<<"Enter Columns "<<endl;
   cin>>c;
   int arr[r][c];
   for(int i =0;i<r;i++){
      for(int j=0;j<c;j++){
         cout<<"Enter Value for Row "<<i<<" Column "<<j<<endl;
         cin>>arr[i][j];
      }
   }

   for(int i=0;i<r;i++){
      for(int j=0;j<c;j++){
         cout<<"Value at Row "<<i<<" Column "<<j<<"is"<<arr[i][j]<<endl; 
      }
   }

   

}