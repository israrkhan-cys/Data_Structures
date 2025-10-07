#include <iostream>
using namespace std;

class Node{
public:
int data;
Node *next;

Node(int d=0): data(d) , next(nullptr){}
};

class Queue{
private:
  Node *front;
  Node *rear;

public:
Queue(){
    front =nullptr;
    rear =nullptr;
}

void Enqueue(){
    int data;
    cout<<"Enter Data :";
    cin>>data;
    
    Node *newNode=new Node(data);
    if(front ==nullptr){
        front=rear=newNode;
        return;
    }else{
        rear->next=newNode;
        rear =newNode;
    }
}

void Dequeue(){
    if(front == nullptr){
        cout<<"The Queue is Empty. \n"; return;
    }
    Node *temp= front ;
    front=front->next;
    delete temp;
}

void Peek(){
    if(front == nullptr){
        cout<<"The Queue is Empty. \n"; return;
    }
   cout<<"The front element is :"<<front->data<<endl;
}
void Queue_count(){
    int count=0;
    Node *tN=front;

    while(tN!=nullptr){
        count++;
        tN=tN->next;
    }
    cout<<"\nQueue has "<<count<<" elements.\n";
    
}

void Display(){
    if(front == nullptr){
        cout<<"The Queue is Empty. \n"; return;
    }
    Node *tN=front;

    while(tN!=nullptr){
        cout<<front->data<<" | ";
        tN=tN->next;
    }
    cout<<"\n";
}
};

int main() {
    Queue q1;

    int choice;
    do { 
        cout<<"\n1. Enqueue\n";
        cout<<"2. Dequeue\n";
        cout<<"3. Peek\n";
        cout<<"4. Count Queue Elements.\n";
        cout<<"5. Display\n";
        cout<<"6. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;    

        switch (choice)
        {
        case 1:
            q1.Enqueue();
            break;
        case 2:
            q1.Dequeue();
            break;
        case 3:
            q1.Peek();
            break;
        case 4:
            q1.Queue_count();
            break;
        case 5:
            q1.Display();
            break;
        case 6:
            cout<<"Exiting...\n";
            break;
        default:
            cout<<"Invalid choice. Please try again.\n";    
            break;
        }

    }while(choice != 6);
    
    
    
    return 0;
}