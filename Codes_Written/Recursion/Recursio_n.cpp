#include <iostream>
using namespace std;

//counting digits in a number
int Digit_count(int number, int count=0){
  if(number<10){
    return ++count;
  }

  number =number /10;
  return Digit_count(number,++count);
}

//Implementation of binary search using recursion
int Binary_Search(int arr[],int target, int L, int R){
    int mid = L +(R-L)/2;
    if(arr[mid]== target){
        return mid;
    }
    if(target >arr[mid]){
        return Binary_Search(arr,target,mid+1,R);
    }else if(target<arr[mid]){
        Binary_Search(arr,target,L,mid-1);
    }
    return -1;
}

//Finding Max element in an Array
int Find_max(int arr[],int size, int n=0, int max=0){
    if(n== size){
        return arr[max];
    }
    if(arr[n]>arr[max]){
        max=n;
    }
    return Find_max(arr,size,++n,max);
}

//Counting Occurrences of a Number in Array
int Count_Occurences(int arr[],int size, int n=0, int target,int count=0){ 
    if(n== size){
        return count;
    }
    if(arr[n] ==target){
        count++;
    }
    return Count_Occurences(arr,size,n+1,target,count);
}

int main() {
    //int number =1234567891;
    //cout<<Digit_count(number);
    
    int arr[5]={2,5,102,45,5};
     //cout<<Binary_Search(arr,5,0,4);
     //cout<<Find_max(arr,5);
    //cout<<Count_Occurences(arr,5,0,5,0);

    return 0;
}