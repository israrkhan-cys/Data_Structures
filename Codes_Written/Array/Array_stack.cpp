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

int Pop(){
     if(top ==-1){
        cout<<"Empty! Nothing to Pop "; return -1;
    } 

  return arr[top--];
}

~Stack(){
    delete[] arr;
}

void  stack_mid(){
    Stack temp(size);

    int count=0;
    for(int i=0;i<size;i++){
        count++;
        temp.Push(Peek());
        Pop();          
    }
    int mid;
    if(count%2==0){
        mid=count/2+1;
    } else{
        mid=(count+1)/2;
    }
    
    for(int i=1;i<=size;i++){
       if(i==mid){
        int t =  temp.Pop();
        cout<<"Middle element is: "<<t<<endl;
        Push(t);
       } else{
        Push(temp.Pop());
       }
}
}

};

int main() {
    Stack s1(5);
    int choice;
    do{
        cout<<"\n1. Push\n2. Pop\n3. Peek\n4. Exit\n5. Find Middle\n";
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
             case 5:
                s1.stack_mid();
                break;     
            default:
                cout<<"Invalid choice! Please try again.\n";
        }
    }while(choice != 4);

    return 0;
}