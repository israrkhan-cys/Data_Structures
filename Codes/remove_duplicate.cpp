#include <iostream>
using namespace std;

void remove_dupllicate(int *arr , int &size){
    int unique_count=0;
      
    for(int i=0; i<size; i++){
        bool isDuplicate= false;
         for(int j=0; j<unique_count;j++){
             if(arr[i]==arr[j]){
                isDuplicate=true;
                break;
             }
         }
         if(!isDuplicate){
            arr[unique_count]=arr[i];
            unique_count++;
         }
    }

    size=unique_count;
}



int main(){

     int temp[10]={1,2,3,3,2,4,5,4,6,2};
     int size=10;
      
     remove_dupllicate(temp,size);


     for (int i = 0; i < size; i++)
     {
        cout<<temp[i]<<" ";
     }
     




    return 0;
}
