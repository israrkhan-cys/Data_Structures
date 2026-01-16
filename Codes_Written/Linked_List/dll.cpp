#include <iostream>
using namespace std;

class Node{
public:
  int data;
  Node *next;
  Node *prev;
Node(int d=0): next(nullptr), prev(nullptr), data(d){}
};

class DLL{
Node *head;
public: 
  DLL(): head(nullptr){}

void InsertAtStart(int d){
   Node *newNode =new Node(d);
   
   if(head==nullptr){
      head=newNode;
   } else{
      newNode->next=head;
      head->prev = newNode;
      head=newNode;
   }
}

//if even delete all nodes with target value else delete only specific Node 
void Target_deletion(int target){
   int count=0;
    Node *tN=head;
    while(tN!=nullptr){
      count++;
      if(tN->data== target ){break;}
      tN=tN->next;
  }
  bool deleteAll = (count %2 == 0); 
  
  Node *tN2=head;
  while(tN2!=nullptr){
    if(tN2->data==target ){
        Node *temp =tN2;
        tN2=tN2->next;
        
        if(temp == head && head->next == nullptr){
            head =nullptr; delete temp;
        } else if(temp==head && temp->next !=nullptr){
             head =head->next;
            head->prev=nullptr;
            delete temp;
        } else {
           temp->prev->next =temp->next;
           temp->next->prev=temp->prev;
           delete temp;
        }
        if(!deleteAll){ break;} 
    } else {
  tN2=tN2->next;
}
}
}
void Display(){
if(head == nullptr){
    cout<<"Empty"; return;
}
Node *tN=head;
while(tN!=nullptr){
   cout<<tN->data<<" ";
   tN=tN->next;
}

}
};


int main(){
  DLL d1;
  d1.InsertAtStart(1);
  d1.InsertAtStart(2);
d1.InsertAtStart(3);
d1.InsertAtStart(2);
d1.InsertAtStart(3);
d1.InsertAtStart(2);
d1.InsertAtStart(3);
  d1.Display(); cout<<endl;
   d1.Target_deletion(3);
  
  d1.Display();



  return 0;
}  
