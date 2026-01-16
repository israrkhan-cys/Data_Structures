#include <iostream>
using namespace std;

class Queue{
  int capacity;
  int front; 
  int rear;
  int *arr;

  public:
  Queue(int cap){
    capacity=cap;
    front= -1;
    rear=-1;
    arr= new int[capacity];
  }
bool isEmpty(){
    return (front == -1); 
}  
bool isFull(){
    return (front == (rear+1)%capacity);
}

void Enqueue(int d){
     
}


};

int main() {
    
    
    return 0;
}