#include <iostream>
using namespace std;

//IMmplentinf stack using arrray
class Array_stack{
    int *arr;
    int top;
    int capacity;
    int size;
public:
    Array_stack(int cap=10){
        capacity =cap;
        arr = new int[capacity];
        top = -1;
        size = 0;
  }

void Push(int value){
    if(size == capacity){
        cout<<"Stack Overflow! Cannot push "<<value<<endl;
        return;
    }
    arr[++top]=value;
    size++;
}    

int  Pop(){
    if(top == -1){
        cout<<"Stack Underflow! Cannot pop from empty stack.\n";
        return -1;
    }
     size--;
    return arr[top--];
   
  } 

void Peek(){
    if(top == -1){
        cout<<"Stack is Empty! Nothing to Peek.\n";
        return;
    }
    cout<<arr[top]<<endl;
  }

bool isEmpty(){
    return top == -1;
}  

};



//Implementing stack using linked list
class Node{
public:
  int data;
  Node *next;

Node(int d=0){
    data=d;
    next=nullptr;
}
};

class Stack{
  Node *top;
  int size;

public:
  Stack(){
    top=nullptr;
    size = 0;
  }

void Push(int value){
     Node *newNode =new Node(value);
     
    if(!top){
        top=newNode;
    }else{
    newNode->next=top;
    top=newNode;
    }

    size++;
}

void Peek(){
    if(top == nullptr){
      cout<<"Empty! Nothing to Peek.\n"; return;
    }
    cout<<top->data<<endl;
}
//Pop Fxn
int Pop(){
    if(top == nullptr){
      cout<<"Stack Underflow! Cannot pop from empty stack.\n"; return -1;
    }
    Node *temp = top;
    int poppedValue = top->data;
    top = top->next;
    delete temp;
    size--;
    return poppedValue;
}

//Fxn for    Reversing stack using recursion
void Reverse_stack(){
    if(top == nullptr){
      return;
    }
    int temp = Pop();
    Reverse_stack();
    insertAtBottom(temp);
}
 void insertAtBottom(int value) {
        if (top == nullptr) {
            Push(value);
            return;
        }
        int temp = Pop();
        insertAtBottom(value);
        Push(temp);
  }

//Fxn for sorting stack using recursion
void sort_stack(){
    if(top == nullptr){
      return;
    }
    int temp = Pop();
    sort_stack();
    sorted_insert(temp);
}
void sorted_insert(int value){
    if(top == nullptr || top->data < value){
        Push(value);
        return;
    }
    int temp = Pop();
    sorted_insert(value);
    Push(temp);
}

//Fxn for deleting middle element of stack
void Delete_Middle(int count, int size){
    if(top == nullptr || count == size/2){
        Pop();
        return;
    }
    int temp = top->data;
    Pop();
    Delete_Middle(count + 1, size);
    Push(temp);
}




//Fxn to check for  balanced parenthesis
void parenthesis_check(){
  Stack temp;
  if(top == nullptr){
    cout<<"Stack is Empty.\n"; return ;
  }
   
  while(top!=nullptr){
    char ch = top->data;
    if(ch == '(' || ch == '{' || ch == '['){
        temp.Push(ch);
    }else{
        if(temp.top == nullptr){
            cout<<"Unbalanced Parenthesis.\n"; return;
        }
        char topChar = temp.top->data;
        if((ch == ')' && topChar == '(') ||
           (ch == '}' && topChar == '{') || 
           (ch == ']' && topChar == '[')){
            temp.Pop();
        }else{
            cout<<"Unbalanced Parenthesis.\n"; return;
        }
    }
    Pop();
  }

  if(temp.top != nullptr){
    cout<<"Unbalanced Parenthesis.\n"; return;
  }
  cout<<"Balanced Parenthesis.\n";
}

void Next_greater_element(){
    if(top == nullptr){
      cout<<"Stack is Empty.\n"; return;
    }
    Stack tempStack;
    Node *current = top;

    while(current != nullptr){
        while(tempStack.top != nullptr && tempStack.top->data <= current->data){
            tempStack.Pop();
        }

        if(tempStack.top == nullptr){
            cout<<current->data<<" -> "<<"-1"<<endl;
        }else{
            cout<<current->data<<" -> "<<tempStack.top->data<<endl;
        }

        tempStack.Push(current->data);
        current = current->next;
    }
}

//Fxn for  Palindrome check
void Palindrome_check(){
    if(top ==nullptr){
      cout<<"Stack is Empty.\n"; return;
    }
    Stack temp;
    Node *current = top;

    while(current != nullptr){
        temp.Push(current->data);
        current = current->next;
    }

    current = top;
    while(current != nullptr){
        if(current->data != temp.top->data){
            cout<<"Not a Palindrome.\n"; return;
        }
        current = current->next;
        temp.Pop();
    }
    cout<<"Is a Palindrome.\n";
}

void Display(){
     if(!top){
      cout<<"Stack underflow\n";
      return ;
     }
    cout<<"Stack elements: ";
     while(top != nullptr){
         cout<<Pop();
     }

     cout<<"\n";
}


~Stack(){
    while(top){
      Pop();
    }
  }
};




int main(){
  Stack s1;
  int choice;
  cout<<"\n===== STACK OPERATIONS MENU =====\n";
  do{
    cout<<"1. Push to Stack \n";
    cout<<"2. Pop from Stack\n";
    cout<<"3. Peek Stack \n";
    cout<<"4. Display\n";
    cout<<"5. Reverse Stack \n";
    cout<<"6. Sort Stack \n";
    cout<<"7. Delete Middle Element \n";
    cout<<"8. Check Balanced Parenthesis \n";
    cout<<"9. Palindrome Check \n";
    cout<<"10. Exit\n";
    cout<<"Enter your choice: ";
    cin>>choice;

    switch(choice){
      case 1:{
        int value;
        cout<<"Enter value to push: ";
        cin>>value;
        s1.Push(value);
        break;
      }
      case 2:{
        s1.Pop();
        break;
      }
      case 3:{
        s1.Peek();
        break;
      }
      case 4:{
        s1.Display();
        break;
      }
      case 5:{
        s1.Reverse_stack();
        cout<<"Stack Reversed.\n";
        break;
      }
      case 6:{
        s1.sort_stack();
        cout<<"Stack Sorted (recursive routine invoked).\n";
        break;
      }
      case 7:{
        int currentSize;
        cout<<"Enter current stack size (number of elements): ";
        cin>>currentSize;
        s1.Delete_Middle(0, currentSize);
        cout<<"Middle element deleted (if any).\n";
        break;
      }
      case 8:{
        s1.parenthesis_check();
        break;
      }
      case 9:{
        s1.Palindrome_check();
        break;
      }
      case 10:{
        cout<<"Exiting...\n";
        break;
      }
      default:{
        cout<<"Invalid choice! Please try again.\n";
        break;
      }
    }
  }while(choice != 9);

  return 0;
}



