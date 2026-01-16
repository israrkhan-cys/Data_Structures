#include <iostream>
using namespace std;

class Node {
    public:
   int data;
   Node *next;

   Node (int d=0){
      data =d;
      next=nullptr;
   }
};


class SLL{
    Node *head;
    Node *tail;
public:
   
  SLL(){
     head = nullptr; tail =nullptr;
  }

  void InsertAtStart(int d){
      Node *newNode= new Node(d);

      if(head==nullptr){
        tail=head= newNode;
        tail->next=head;
      }else{
        newNode->next= head;
        head = newNode;
        tail->next= head;
      } 
  }

  void InsertionAtEnd(int d){
    Node *newNode = new Node(d);

    if(head==nullptr){
        tail=head=newNode;
        tail->next=head;
    } else{
        tail->next =newNode;
        tail=newNode;
        tail->next=head;
    }
  }

void Delete(Node *key){
     if(head== nullptr){
        return;
     }

     Node *tN = head;
     Node *prev =tail;

 do{
    if(tN==key){
            break;   
        }

        prev =tN;
        tN=tN->next;     
    }while(tN!=head);


 
    if(key==head){
        Node *temp =key;
        head = head->next;
        tail->next= head;
        delete temp;
    } else if(tail == key){
        Node *temp =key;
        tail= prev;
         tail->next = head;
         delete temp;
     }else{
        Node *temp =key;
        prev->next = key->next;
        delete  temp;
    }
}

void Alternatives(){
   if(head == nullptr && head->next== nullptr){
    return;
   }

     Node *curr =head;
    do{
        Delete(curr->next);
        curr=curr->next;
    }while(curr->next!=head);
}

  void Display(){
      if(head == nullptr) {cout<<"Empty...!!!!!!\n"; return;}

     Node *tN= head;

     do{
      cout<<tN->data<<" | ";
      tN=tN->next;
     }while(tN!=head);

  }
};

int main() {
    SLL s1;
    
     s1.InsertionAtEnd(2);
     s1.InsertionAtEnd(5);
     s1.InsertionAtEnd(1);
     s1.InsertionAtEnd(4);

    cout<<"\nData :";
   s1.Display();
     s1.Alternatives();
   cout<<"\n Now Data : ";
   s1.Display();

    return 0;
}