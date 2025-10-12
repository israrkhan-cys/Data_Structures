#include <iostream>
using namespace std;

class Node{
public:
  int data;
  Node *next;

Node(int d=0)  {
    data=d;
    next=nullptr;
}
};

class Stack{

  Node *top;
public:
  Stack(){
    top=nullptr;
  }

void Push(int value){
     Node *newNode =new Node(value);
     
    if(!top){
        top=newNode;
    }else{
    newNode->next=top;
    top=newNode;
    }
}

void Peek(){
    if(top == nullptr){
      cout<<"Empty! Nothing to Peek.\n"; return;
    }
    cout<<top->data<<endl;
}
void Pop(){
     if(top == nullptr){
      cout<<"Empty! Nothing to Pop.\n"; return;
    }
    Node *temp=top;
    top = top->next;
    delete temp;
}


~Stack(){
    while(top){
      Pop();
    }


};
int main(){
  Stack s1;
   int choice;

  do{
    cout<<"1. Push\n2. Pop\n3. Peek\n4. Exit\n";
    cout<<"Enter your choice: ";
    cin>>choice;

    switch(choice){
      case 1:
        int value;
        cout<<"Enter value to push: ";
        cin>>value;
        s1.Push(value);
        break;
      case 2:
        s1.Pop();
        break;
      case 3:
        s1.Peek();
        break;
      case 4:
        cout<<"Exiting...\n";
        break;
      default:
        cout<<"Invalid choice! Please try again.\n";
    }
  }while(choice != 4);

   return 0;
}

