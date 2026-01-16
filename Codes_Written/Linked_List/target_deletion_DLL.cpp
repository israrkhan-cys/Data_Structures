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
      head=newNode;
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
DLL 



  return 0;
}  
