#include <iostream>
using namespace std;

bool isPrime(int n){
    if(n<= 1) return false;

    for(int i=2; i<n ; i++){
        if(n % i == 0){
            return false;
        }
    }
   return true;
}

bool isPerfect(int n){
  for(int i=1; i<n ;i++){
        if(i*i == n){
            return true;
        }
    }

   return false;
}


void Count_prime_perfect(int arr[], int N){
     int prime_count=0;
     int perfect_count=0;
     int *p=arr;

   for(int i=0; i<N; i++){
        if(isPrime(*(p+i))){
            prime_count++;
        }
        if(isPerfect(*(p+i))){
            perfect_count++;
        }
     }


     cout<<" Count of prime numbers is : "<<prime_count<<endl;
     cout<<"Count of Perfect Squares : "<<perfect_count<<endl;
}

int main() {
   
    int arr[]={1,2,3,4,5,6,7,8,9,49,17};
    int size = sizeof(arr)/sizeof(arr[0]);

    Count_prime_perfect(arr,size);
    
    return 0;
}