#include <iostream>
using namespace std;

void RotateByOne( int *arr, int size ){
    int last = arr[size-1];

    for(int i=size-1; i >=0; i--){
        arr[i]=arr[i-1];
    }

    arr[0]=last;
}
int main() {
   int size =5;
   int arr[size]={1,2,3,4,5};

   RotateByOne(arr,size);

   for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
   }
    
    return 0;
}