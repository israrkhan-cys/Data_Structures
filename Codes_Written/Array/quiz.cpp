#include <iostream>
using namespace std;

void RunningSum(int *arr, int size){
      for (int i=1; i<size; i++){
           arr[i]+= arr[i-1];
      }

    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
   int size =6;
   int arr[size]={1,2,3,4,5,6};

   for(int i=0; i<size; i++){
    cout<<arr[i]<< " ";
   }
    cout<<endl;
   RunningSum(arr,size);
 


    return 0;
}