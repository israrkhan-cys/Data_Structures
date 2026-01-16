#include <iostream>
using namespace std;

void Common_count(int *arr, int *arr1, int size1, int size2){
   int Common=0;
    
    int *end1=arr+size1;
    int *end2=arr1+size2;

    for(int *p1=arr; p1<end1; p1++){
        for(int *p2=arr1; p2<end2; p2++){
            if(*p1==*p2){
                Common++; break;
            }
        }
    }



   cout<<Common<<" ";
}

int main(){
    int size1=5;
    int size2=10;

    int arr[size1]={1,1,1,1,1};
    int arr1[size2]={1,1,1,1,1,1,7,8,9,10};

    Common_count(arr,arr1,5,10);

    return 0;
}