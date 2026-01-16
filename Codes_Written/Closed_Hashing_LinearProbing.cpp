#include <iostream>
using namespace std;

class Hashing{
   int *arr;
   int size;

public:  
   Hashing(int s){
    size =s;
      arr= new int[size];
      for(int i=0;i < size; i++){
         arr[i]=-1; //means empty
      }
   }

int HashFxn(int k){
      return k%size;
   }

void Insert(int key){
     int index = HashFxn(key);
     int i=0;

     while(i<size){
        int newindex = (index+i) % size;
        if(arr[newindex] == -1){
            arr[newindex]= key;
            return;
        }

        i++;
     }
}

void Delete(int key){
     int index =HashFxn(key);
     int i=0;

     while(i<size){
        int newindex = (index +i) % size;
         if(arr[newindex]== key){
            arr[newindex] = -2;
            return;
        }
        
        if(arr[newindex]== -1) {
            return;
        }
        i++;
     }

}

bool Seearch(int key){
    int index= HashFxn(key);

    int i=0;

    while (i<size){
        int newindex = (index +i) %size;

       if(arr[newindex] == key){
        return true;
       }

       if(arr[newindex] == -1){
        return false;
       }

       i++;
    }
    
    return false;
}

void Display(){
    for(int i=0; i<size ; i++){
        cout<<i<<" : "<<arr[i]<<endl;
    }
}


};

int main() {
    int size =10;

    Hashing h1(size);
    
    h1.Insert(1);
    h1.Insert(2);
    h1.Insert(2);
    h1.Insert(3);
    h1.Insert(5);
    h1.Insert(6);
    h1.Insert(9);
    h1.Insert(13);
    h1.Insert(4);
    h1.Insert(7);
    
    h1.Display();
    return 0;
}