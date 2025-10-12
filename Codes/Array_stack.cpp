#include <iostream>
using namespace std;

class Stack{
  int *arr;
  int size;
  int top;

  public:
  Stack(int s){
   size=s;
   arr=new int[size];
   top=-1;
  }

void Push(int value){
    if(top== size-1){
        cout<<"The Stack is Full. "; return;
    }
    arr[++top]=value;
}

int Peek(){
    if(top ==-1){
        cout<<"The Stack is Empty. "; return -1;
    }
    return arr[top];
}

void Pop(){
     if(top ==-1){
        cout<<"Empty! Nothing to Pop "; return;
    } 
  --top;
}

~Stack(){
    delete[] arr;
}



};

int main() {
    Stack s1(5);
    int choice;
    do{
        cout<<"\n1. Push\n2. Pop\n3. Peek\n4. Exit\n";
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
                cout<<"Top element is: "<<s1.Peek()<<endl;
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