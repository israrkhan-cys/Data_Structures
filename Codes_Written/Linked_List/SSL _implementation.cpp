#include <iostream>
using namespace std;

class Node{
public:
  int data;
  Node *next;
  
 Node(int val=0 ): data(val), next(nullptr){}
};

class SSL{




void Insertfirstrightthenleft(int val, int R, int i){
      Node *newNode = new Node(val);
      if(isEmpty()){
            tail=head=newNode;
            return;
      }
      
      if(R==1){
          newNode->next=head;
          head=newNode;
      }else{
          tail->next=newNode;
          tail=newNode;
      }
}

public:
   Node *head ,*tail;
   
SSL(){  
 head=nullptr;
 tail=nullptr;
}

bool isEmpty(){
   return(head==nullptr && tail==nullptr);
}

void insertionAtStart(int d){ 

     Node * newNode = new Node(d);
      newNode->next=head;
     head=newNode;
     if(tail == nullptr){
          tail=newNode;
     }
}

void InsertionAtEnd(){
     int d;
     cout<<"Enter Value for Insertion :";
     cin>>d;
     Node *newNode = new Node(d);
     if(isEmpty()){
           tail=head=newNode;
           return;
     }
     tail->next=newNode;
     tail=newNode;
}

void InsertAfterVal(){
     int target;
     cout<<"Enter the After Value:";
     cin>>target;
     
     Node *tN=head;
     while(tN !=nullptr && tN->data != target){
           tN=tN->next;
     }
     if(tN == nullptr){
          cout<<"Value not found !";
          return;
     }
     
     int d;
     cout<<"Enter Value for Insertion :";
     cin>>d; 
     Node *newNode = new Node(d);
      newNode->next = tN->next;
      tN->next=newNode;
      
      if(newNode->next==nullptr){
          tail = newNode;
      }
}

void SearchByValue(){
     if(isEmpty()){
         cout<<"The List is Empty nothing to search";
        return;
     }
     int target;
     cout<<"Enter the Search Value:";
     cin>>target;
     
     Node *tN = head;
     while(tN!=nullptr && tN->data!=target){
        tN=tN->next;
     }
     if(tN == nullptr){
      cout <<"Value not found !";
     }else{
     cout<<"The Value is present in the Linked list \n";
     }
}

void DeleteByVal(){
  if(isEmpty()){
         cout<<"The List is Empty nothing to delete";
        return;
     }
     int target;
     cout<<"Enter Value for deletion :";
     cin>>target;
     Node *tN = head;
     Node *prev= nullptr;
     while(tN !=nullptr && tN->data != target){
          prev = tN;
          tN = tN->next;
     }
     if(tN == nullptr){ cout <<"Value not found !"; return;}
     
     if(tN == head){
       
       head = head->next;
       delete tN;
       
       if(head == nullptr){
         tail = nullptr;
       }
       return;
     }
     
     
      prev->next = tN->next;
      delete tN;
      
      
      
     if(tN->next == nullptr){
        tail = prev;
     }
}

int Reapeat_count(){
  if(head == nullptr) return 0;

  SSL repeat;

  int repeat_count =0;
  Node *tN = head;
  do{
    Node *inner =head; int count =0;
    do{
        if(tN->data == inner->data){
            count++;
        }
        if(count >1){
          if(repeat.isEmpty()){
            repeat.insertionAtStart(inner->data);
            repeat_count++;
          }else{
            Node *rN = repeat.head;
            bool found = false;
            while(rN != nullptr){
                if(rN->data == inner->data){
                    found = true;
                    break;
                }
                rN = rN->next;
            }
            if(!found){
                repeat.insertionAtStart(inner->data);
                repeat_count++;
            }
          }
          break;
        }
    }
    

}


void CountNodes(){
 if(isEmpty()){ cout<<"List is Empty."; return; }
    Node *tN= head;
    int count =0;
    while(tN!=nullptr){
      tN= tN->next;
      count++;
    }  

  cout<<"Number of Nodes in the Linked List is : " <<count; 
}

void Reverse_list(){
  if(isEmpty()){
   cout<<"The list is Empty."; return; 
  }
  Node * oldhead=head;
  Node *prev =nullptr;
  Node *current = head;
  Node *nextNode =nullptr;
  
  while(current != nullptr){
     nextNode = current->next;
     current->next=prev;
      prev= current;
     current = nextNode;
  }
  head=prev;
  tail=oldhead;
}




void Display(){ 
    Node *tN= head;
    cout<<"\nLinked List Data :\n";
    while(tN!=nullptr){
      cout<<tN->data<<" ";
      tN= tN->next;
    }
    cout<<endl;
}

~SSL() {
    Node* current = head;
    while(current){
        Node* next = current->next;
        delete current;
        current = next;
    }
}

   
   
};

int main(){
   SSL s1;
   cout<<"Fully Implementation of Singly linked List \n";
  while(1){
   cout<<"1.Insert Values at start :\n";
   cout<<"2.Insert Values at End :\n";
   cout<<"3.Insert After Value :\n"; 
   cout<<"4.Search By value :\n";
   cout<<"5.Delete By Value :\n";
   cout<<"6.Count Nodes :\n";
   cout<<"7.Reverse Linked List : \n";
   cout<<"8.Display :\n";
   cout<<"9.Exit Program ";
   int ch;
   cout<<"\n Enter Your Choice :";
   cin>>ch;
   
   switch(ch){
   case 1:{
      s1.insertionAtStart(); break;
   }
   case 2:{
   s1.InsertionAtEnd(); break;
   }
   case 3:{
      s1.InsertAfterVal(); break;
   }
   case 4:{
     s1.SearchByValue(); break;
   }
   case 5:{
   s1.DeleteByVal(); break;
   }
   case 6:{
   s1.CountNodes(); break;
   }
   case 7:{
   s1.Reverse_list(); break;
   }
   case 8:{
   s1.Display(); break;
   }
   case 9:{
    cout<<"Exiting Program.............!!! ";  break; return;
   }
   default: {
     cout<<"Invalid Choice , try Agian"; break;
   }
   }
   
   
   
  }

  
  return 0;
  }
