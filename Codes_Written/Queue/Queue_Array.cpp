#include <iostream>
using namespace std;

class Queue{
private:

int *arr;
int size;
int front;
int rear;
int existing_element;

public:
 Queue(int s){
    size=s;
    arr= new int[size];
    front=-1;
    rear=-1;
    existing_element=0;
}


void Enqueue(){
    if(existing_element==size){
        cout<<"The Queue is Full. \n";
        return;
    }
    int data;
    cout<<"Enter data :";
    cin>>data;
    if(front==-1){
        front=rear=0;
        arr[rear]=data;
    }else{
        rear =(rear +1)% size;
        arr[rear]=data;
    }
   existing_element++;
}

void Dequeue(){
    if(existing_element == 0){
        cout<<"The Queue is Empty. \n";
        return;
    }
    if(front == rear){
        front =rear =-1;
    }else{
    front=(front+1)% size;
}

existing_element--;
}

void Peek(){
    if(existing_element==0){
        cout<<"The Queue is Empty"; return;
    }
    cout<<"The Front element is :"<<arr[front]<<endl;
}
void Display(){
    if(front== -1){
        cout<<"The Queue is Empty";
        return;
    }

    int i=front;
    while(true){
      cout<<arr[i]<<" ";
      if(i==rear){break;}
      i=(i+1)%size;
    }
    cout<<"\n";
}


};
int main(){
    Queue q1(5);
    
    do
    {
     cout<<"1.Enqueue.\n";
     cout<<"2.Dequeue.\n";
     cout<<"3.Peek.\n";
     cout<<"4.Display Queue.\n";
     cout<<"5.Exit.\n";
    int ch;
    cout<<"Enter Your choice :";
    cin>>ch;

    switch (ch){
    case 1:{
        q1.Enqueue();
        break;
    }
    case 2:{
        q1.Dequeue(); break;
    }
    case 3:{
        q1.Peek(); break;
    }
    case 4:{
         q1.Display(); break;
    }
    case 5:{
        cout<<"Exiting..";
        return 0; break; 
    }
    default:
    cout<<"Invalid choice, Try Again !";
        break;
    }
    } while (true);
      
    
    return 0;
}