#include <iostream>
using namespace std;

int binary_search(int *arr,int size){
    int low =0;
    int high=size;
   
     int target;
     cout<<"Enter target :";
     cin>>target;
 
     while(low<=high){
       int mid = low+(high-low)/2;  
    if(arr[mid]==target){
        return mid;
    }
    if(target>arr[mid]){
       low =mid+1;
    }    
    if(target<arr[mid]){
        high= mid-1;
    }
}

    return-1;

}

int main() {
      int arr[10] = {1,2,3,4,5,6,7,8,9,10};
     
      int index = binary_search(arr,10);
      cout<<"The value if at index "<<index;



    
    return 0;
}