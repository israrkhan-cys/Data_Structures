#include <iostream>
#include <stack>
using namespace std;

//Implement a Queue using Array
//i make the a circualar to avoid wastage of space and improve efficiency
class Array_Queue{
private:
    int front;
    int rear;
    int capacity;
    int *arr;

public:
  Array_Queue(int size=5){
    capacity=size;
    front =-1;
    rear =-1;
    arr=new int[capacity];
  }

void Enqueue(int data){
    if(isFull()){
        cout<<"Queue Overflow. \n"; return;
    }
    if(front == -1) front=0;
    rear = (rear + 1) % capacity;
    arr[rear]=data;
}

int Dequeue(){
    if(isEmpty()){
        cout<<"Queue Underflow. \n"; return -1;
    }
    int data = arr[front];
    front = (front + 1) % capacity;
    return data;
}

void front_element(){
    if(isEmpty()){
        cout<<"Queue is Empty. \n"; return;
    }
    cout<<"Front Element is : "<<arr[front]<<endl;
}

bool isEmpty(){
    return (front == -1 || front > rear);
}

bool isFull(){
    return ((rear+1) % capacity == front);

};

class item{
    public:
    int data;
    int priority;

    item(int d=0, int p=0): data(d), priority(p){}
};

//implementing Priotity Queue using Array 
class Priority_Queue{
private:
    int capacity;
    int rear;
    item *arr;

public:
    Priority_Queue(int size=5){
        capacity=size;
        rear =-1;
        arr=new item[capacity];
    }

    void Enqueue(int d, int p){
        if(isFull()){
            cout<<"Priority Queue Overflow. \n"; return;
        }
        rear = (rear+1)% capacity;
        arr[rear]= item(d,p);
    }

int Dequeue(){
    if(isEmpty()){
            cout<<"Priority Queue Underflow. \n"; return -1;
    }
    int maxP=0;
        for(int i=1; i<=rear; i++){
            if(arr[i].priority > arr[maxP].priority){
                maxP=i;
            }
        }
        int data= arr[maxP].data;
        for(int i=maxP; i<rear; i++){
            arr[i]=arr[i+1];
        }
        rear = (rear - 1 + capacity) % capacity;
        return data;
    }

    bool isEmpty(){
        return (rear == -1);
    }

bool isFull(){
    return (rear == capacity -1);
}

};   



//Implement Queueu using Linked List
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

void Enqueue(int data){
    Node *newNode=new Node(data);
    if(front ==nullptr){
        front=rear=newNode;
        return;
    }else{
        rear->next=newNode;
        rear =newNode;
    }
}

int Dequeue(){
    if(front == nullptr){
        cout<<"The Queue is Empty. \n"; return -1;
    }
    Node *temp= front ;
    front=front->next;
    int data = temp->data;
    delete temp;
    return data;
}

void Peek(){
    if(front == nullptr){
        cout<<"The Queue is Empty. \n"; return;
    }
   cout<<"The front element is :"<<front->data<<endl;
}
int Queue_count(){
    int count=0;
    Node *tN=front;

    while(tN!=nullptr){
        count++;
        tN=tN->next;
    }
    return count;
    
}

//Fxn for Reversing First k elements 
void Reverse_ist_K(int k){
    if(front== nullptr || k > Queue_count()){
      cout<<"Queue is Empty or has less than K elements.\n";
    }
   for(int i=0; i<k; i++){
      int temp = Dequeue();
      Enqueue(temp);
   }

   cout<<"\nQueue elements after Reversing first K:";
   Display();
}



//Fxn for  checking if Queue is  palindrome  or not 
void Palindrome_check() {
    if (!front) {
        cout << "Queue is empty.\n";
        return;
    }

    stack<int> temp;
    int n = Queue_count();

    for (int i = 0; i < n; i++) {
        int x = Dequeue();
        temp.push(x);
        Enqueue(x);
    }

    bool isPalindrome = true;
    for (int i = 0; i < n; i++) {
        int a = Dequeue();
        int b = temp.top(); temp.pop();
        if (a != b) {
            isPalindrome = false;
        }
        Enqueue(a);
    }

    if (isPalindrome)
        cout << "\nPalindrome\n";
    else
        cout << "\nNot palindrome\n";

}

void Display(){
    if(front == nullptr){
        cout<<"The Queue is Empty. \n"; return;
    }
    Node *tN=front;

    while(tN!=nullptr){
        cout<<tN->data<<" | ";
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
        cout<<"6.Reverse First K elements.\n";
        cout<<"7.Palindrome Check.\n";
        cout<<"8. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;    

        switch (choice)
        {
        case 1:
            int d; cout<<"Enter data to Enqueue: "; cin>>d;
            q1.Enqueue(d);
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
        case 6:{
            int k; cout<<"Enter K value :"; cin>>k;
            q1.Reverse_ist_K(k);
            break;
        }  
        case 7:{
              q1.Palindrome_check();
              break;
        }
        case 8:
            cout<<"Exiting...\n";
            break;
        default:
            cout<<"Invalid choice. Please try again.\n";    
            break;
        }

    }while(choice != 8);
    
    
    
    return 0;
}