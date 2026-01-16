#include <iostream>
using namespace std;

class Stack{
    int capacity;
    int *arr;
    int top;

 public:
   Stack(int cap){
       capacity =cap;
       arr= new int[capacity];
       top=-1;
   }

bool isEmpty(){
    return (top == -1);
}

bool isFull(){
    return (top== capacity-1);
}

void Push(int val){
    if(isFull()){
        return;
    }
    arr[++top] = val;
}

int Pop(){
    if(isEmpty()){
        return -1;
    }
    int temp = arr[top];
    --top;
    return temp;
}

int Top(){
    if(isEmpty()){
        return -1;
    }
    return arr[top];
}

void PutReverse(Stack & s){
     if(s.isEmpty()) {
      return;
     }
     int tt= s.Pop();
     PutReverse(s);
     Push(tt);
}


void ReverseStack(){
     if(isEmpty()){
        return;
    }
    Stack temp(capacity);
    while(!isEmpty()){
         int t =Pop();
         temp.Push(t);
    }

    PutReverse(temp);
}


void SortStack(){
    if(isEmpty()){
        return;
    }
    Stack temp(capacity);
    while(!isEmpty()){
        int t = Pop();

      while(!temp.isEmpty() && temp.Top()<t){
        Push(temp.Pop()); 
      }
      temp.Push(t);
    }
    while(!temp.isEmpty()){
         Push(temp.Pop());
    }
    Display();
}

void Display(){
    if(isEmpty()){
        return;
    }
     int temp= Pop();
     cout<<temp<<endl;
     Display();
     Push(temp);
}

};

int main() {
    Stack s1(5);

    s1.Push(1);
    s1.Push(9);
    s1.Push(7);
    s1.Push(4);
    s1.Push(5);

    s1.SortStack();
    // s1.ReverseStack();
    // cout<<"Newnwwwwwwwwwwwwwwwwww \n";
    // s1.Display();
    
    
    return 0;
}