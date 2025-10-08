#include <iostream>
using namespace std;

class Node{
public:
int data;
int priority;
Node *next;

Node(int d , int p): data(d), priority(p){}
};

class Priority_Queue{

Node *front;

public:
Priority_Queue(): front(nullptr){}

void Priority_Enqueue(int d, int priority){
   Node *newNode =new Node(d,priority);

   if(front==nullptr || front->priority >= priority){
       newNode->next=front;
       front =newNode;
       return;
   }
   Node *tN=front;
   while(tN->next !=nullptr && tN->next->priority <= priority){
      tN=tN->next;
   }
   newNode->next=tN->next;
   tN->next=newNode;
}

void Dequeue(){
    if(front == nullptr){
        cout<<"The Queue is Empty.\n"; return;
    }
    Node *temp=front;
    front=front->next;
    delete temp;
}

void Peek(){
    if(front == nullptr){
        cout<<"The Queue is Empty.\n"; return;
    }
    cout<<"The front Element is "<<front->data<<" with Priority "<<front->priority<<endl;
}

void Display(){
    Node *tN=front;

    cout<<"data"<<" "<<"Priority\n";
    while(tN != nullptr){
        cout<<tN->data<<"  "<<tN->priority<<endl;
        tN=tN->next;
    }

}

};



int main() {
    Priority_Queue pq1;
    cout<< "Priority Queue using Linked List!\n";
    int ch;
    do{
        cout<<"1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
        cout<<"Enter your choice: ";
        cin>>ch;

        switch(ch){
            case 1: {
                int data, priority;
                cout<<"Enter data and priority: ";
                cin>>data>>priority;
                pq1.Priority_Enqueue(data, priority);
                break;
            }
            case 2:
               
                pq1.Dequeue();
                break;
            case 3:
                pq1.Peek();
                break;
            case 4:
                pq1.Display();
                break;
            case 5:
                cout<<"Exiting...\n";
                break;
            default:
                cout<<"Invalid choice! Please try again.\n";
        }
    }while(ch != 5);

    
    return 0;
}