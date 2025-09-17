#include <iostream>
using namespace std;

class Node {
public:
   int data;
   Node *prev , *next ;
   
  Node (int d=0) :data(d) ,prev(nullptr) , next(nullptr){} 
};

class DLL{
  Node *head;
  Node *tail;

public:
   DLL() : head(nullptr) , tail(nullptr) {}

void InsertAtStart(){
   int d;
   cout<<"Enter Value for Insertion : ";
   cin>>d;
   
   Node * newNode = new Node(d);
   
   if(head == nullptr) { head = tail = newNode; return;
   }else {
       newNode->next =head;
       head->prev = newNode;
       head = newNode;
   }
}

void IsertAtEnd(){
   int d;
   cout<<"Enter Value for Insertion : ";
   cin>>d;
   
   Node *newNode= new Node(d);
  
  if(head==nullptr) {
  head = tail = newNode;
  return;
  }else{
    tail->next=newNode;
    newNode->prev= tail;
    tail=newNode;
  }
}

void InsertAfterVal(){
int target;
cout<<"Enter After Val :";
cin>>target;

Node *tN =head;
bool isFound =false;
while(tN!=nullptr){
  if(tN->data==target){
     isFound=true;
      break;
}
 tN= tN->next;
}
if(!isFound){
   cout<<"Value not Found in the list. "; return;
}
   int d;
   cout<<"Enter Value for Insertion : ";
   cin>>d;
   Node *newNode= new Node(d);
if(tN==tail){
newNode->prev=tN;
newNode->next= nullptr;
tN->next = newNode;
tail=newNode;
}else{
newNode->next = tN->next;
newNode->next->prev =newNode;
tN->next =newNode;
newNode->prev=tN;
}
}


void DeleteByVal(){
   int t;
   cout<<"Enter Value for deletion :";
   cin>>t;
   
Node *tN= head;
bool found =false;
while(tN!=nullptr){
 if(tN->data ==t){
    found=true;
    break;
 }
 tN=tN->next;
}
if(!found){
  cout<<"Value Not Found!"; return;
}

if(tN==head && tN->next==nullptr){
      delete tN;
      head = tail =nullptr;
} else if(tN==head && tN->next!=nullptr){
         tN->next->prev = nullptr;
         head=tN->next;
         delete tN;
} else if(tN==tail){
   tN->prev->next=nullptr;
   tail = tN->prev;
   delete tN;
} else{
   tN->prev->next = tN->next;
   tN->next->prev = tN->prev;
   delete tN;
}
cout<<"\n Value Deleted Succesfully.";
}

void Reverse_list(){
    if(head==nullptr){
    cout<<"List is Empty !"; return;
    }
    Node *tN=head;
    Node *oldhead =head;
    while(tN!=nullptr){
      Node *temp =tN->next;
      tN->next = tN->prev;
      tN->prev= temp;
      tN= temp;
    }
    head =tail;
    tail =oldhead;
    
}

void CountNodes(){
int count=0;
Node *tN=head;

while(tN!=nullptr){
  count++;
  tN= tN->next;
}

cout<<"\nNumber of Nodes in the List is : "<<count;
}


void Display(){
  if(head==nullptr){
  cout<<"list is Empty:"; return;
}

Node *tN = head;
cout<<"\n List Values :";
while(tN !=nullptr){
cout<<tN->data<<" ";
tN= tN->next;
}
cout<<endl;
}
};

int main(){
  DLL s1; 
  
  while(true){
   cout<<"1.Insert Values at start :\n";
   cout<<"2.Insert Values at End :\n";
   cout<<"3.Insert After Value :\n"; 
   cout<<"4.Delete By Value :\n";
   cout<<"5.Count Nodes :\n";
   cout<<"6.Reverse Linked List : \n";
   cout<<"7.Display :\n";
   cout<<"8.Exit Program ";
   int ch;
   cout<<"\n Enter Your Choice :";
   cin>>ch;
   
    switch(ch){
   case 1:{
      s1.InsertAtStart(); break;
   }
   case 2:{
   s1.IsertAtEnd(); break;
   }
   case 3:{
      s1.InsertAfterVal(); break;
   }
   case 4:{
   s1.DeleteByVal(); break;
   }
   case 5:{
   s1.CountNodes(); break;
   }
   case 6:{
   s1.Reverse_list(); break;
   }
   case 7:{
   s1.Display(); break;
   }
   case 8:{
    cout<<"Exiting Program.............!!! ";   return 0; break;
   }
   default: {
     cout<<"Invalid Choice , try Agian"; break;

}
}
}


 return 0;
}


