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
int Pop(){
     if(top == nullptr){
      cout<<"Empty! Nothing to Pop.\n"; return -1 ;
    }
   
    Node *temp=top;
    int poppedValue=top->data;
    top=top->next;
    delete temp;
    return poppedValue;   
}


void stack_mid(){
  Stack temp;
  Node *tN=top;

  int count=0; 
  while(tN){
    count++;
    tN=tN->next;
  }

  int mid=count/2;
  tN=top;

  for(int i=0;i<mid;i++){
    temp.Push(tN->data);
    tN=tN->next;
  }
  if(count%2!=0){
    temp.Push(tN->data);      
  }
  while(temp.top!=nullptr){
    Push(temp.Pop());
  } 
}

void Reverse_stack(){
  Stack temp;
  while(top!=nullptr){
    temp.Push(Pop());
  }
  top=temp.top;
}


~Stack(){
    while(top){
      Pop();
    }
  }

};

void Palindrome_check(string text){
  Stack s;

  for(int i=0; text[i]!='\0'; i++){
       s.Push(text[i]);
  }
   bool palind=true;
  for(int i=0; text[i]!='\0'; i++){
     if(s.Pop()!=text[i]){
      palind = false;
      break;
     }
  }
  if(palind){
    cout<<"Yes";
  }else{
    cout<<"Not";
  }
}

string Reverse_string(string text){
  Stack s;
  for(int i=0; text[i]!='\0'; i++){
       s.Push(text[i]);
  }
  
   for(int i=0; text[i]!='\0'; i++){
     text[i] = s.Pop();
  }

  return text;

}

void delete_mid(){

}


int main(){
  Stack s1;
   int choice;

  do{
    cout<<"1. Push\n2. Pop\n3. Peek\n4. Exit\n5. Reverse Stack\n";
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
      case 5:
        s1.Reverse_stack();
        break;
      default:
        cout<<"Invalid choice! Please try again.\n";
    }
  }while(choice != 4);

   return 0;
}


