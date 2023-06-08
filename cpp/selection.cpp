#include<iostream>
using namespace std;

class sr{
   public:
template <class T>
   void sort(T arr[],int n){
      int i,j;
   for(i=0;i<n-1;i++){
      for(j=i+1;j<n;j++){
         if(arr[j]<arr[i]){
            T temp;
            temp = arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
         }
      }
   }
   }
};

int main(){
   
   int i;
   sr s;
   int arr[5]={10,7,6,8,12};
   s.sort(arr,5);
   for(i=0;i<5;i++){
      cout<<arr[i];
   }

   
}
