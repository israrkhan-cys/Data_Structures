#include <iostream>
using namespace std;

class Heap{
    int cap; 
    int *arr;
    int size;

public:
   Heap(int c){
    cap=c;
    arr=new int[cap];
    size=-1;
   }

void Insert(int d){
    if(size == cap-1){
        return;
    }
   arr[++size] = d;
   heapifyUp(size);
}

void heapifyUp(int i){
      while(i>0){
       int parent = (i-1)/2;
        if(arr[parent] >= arr[i]){
          break;
        }
          int temp= arr[i];
            arr[i]= arr[parent];
            arr[parent] =temp;
        i=parent;
      }
}

int Delete(){
    if(size ==-1){
       return -1;
    }
    int temp =arr[0];
    arr[0]=arr[size];
    --size;
    heapifyDown(0);
    return temp;
}


void Extract(){
        if(size <=-1){

        return;
    }

    int temp =arr[0];
    arr[0]= arr[size];
    arr[size]= temp;
    --size;

    heapifyDown(0);
}

void heapifyDown(int i){

    while(i<=size){
     int left = 2*i+1;
     int right =2*i+2;
     int largest =i;
     if( left <= size  && arr[left] > arr[largest]){
          largest =left;
     } 
     if(right <=size &&  arr[right]> arr[largest]){
          largest=right;
     }
     if(largest == i){
        break;
     }

     swap(arr[i], arr[largest]);
     i=largest;
    }
}

void HeapSort(){
    int originalSize=size;
   while(size >0){
     Extract();
   }
     size =originalSize;
   for(int i=0; i<=  originalSize; i++){
        cout<<arr[i]<<" ";
    }

}


void KthLargest_element(int k){
    for(int i=0; i<k; i++){
        cout<<Delete()<< " ";
    }
}
};

int main() {
     Heap h1(7);

     h1.Insert(3);
     h1.Insert(3);
     h1.Insert(1);
     h1.Insert(2);
     h1.Insert(6);
     h1.Insert(4);  
    h1.KthLargest_element(2);
    //  h1.HeapSort();
    return 0;
}
