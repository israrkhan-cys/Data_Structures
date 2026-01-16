#include <iostream>
#include <vector>
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
    public:
    Node *head;
    Node *tail;

   
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

void Delete(){
     if(head== nullptr){
        return;
     }

     Node *tN = head;
     Node *prev =tail;

     Node *maxprev=nullptr;
     Node *minprev=nullptr;
     
     Node *max =head;
     Node *min=head;

    do{
        
        if(max->data < tN->data){
            maxprev=prev;
             max=tN;
        }
        if(min->data > tN->data){
            minprev=prev;
            min=tN;
        }
        prev =tN;
        tN=tN->next;
       
    }while(tN!=head);


 if(min != max){
    if(max==head){
        Node *temp =max;
        head = head->next;
        tail->next= head;
        delete temp;
    } else if(tail == max){
        Node *temp =max;
        tail= maxprev;
         tail->next = head;
         delete temp;
     }else{
        Node *temp =max;
        maxprev->next = max->next;
        delete  temp;
    }
}

 if (minprev == max) minprev = maxprev;

    if(min==head){
        Node *temp =min;
        head = head->next;
        tail->next= head;
        delete temp;
    } else if(tail == min){
        Node *temp =min;
        tail= minprev;
         tail->next = head;
         delete temp;
     }else{
        Node *temp =min;
        minprev->next = min->next;
        delete  temp;
    }
}

void Remove_duplicates(){
if(head == nullptr) return;
Node *tn=head;
Node *prev=tail;
   while(!tn){
         if(tn->data == tn->next->data){
            if(tn==head){
                head=tn->next; tail->next=head;
            }else if(tn==tail){
                tail=prev;
                tail->next=head;
            } else {
                prev->next = tn->next;
            }
             Node *temp=tn;
             delete temp;
    }
            
    tn=tn->next;
            
}
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
     s1.InsertionAtEnd(1);
     s1.InsertionAtEnd(1);
     s1.InsertionAtEnd(2);
     s1.InsertionAtEnd(2);
     s1.InsertionAtEnd(3);
     s1.InsertionAtEnd(4);
     s1.InsertionAtEnd(4);


     s1.Remove_duplicates();
     s1.Display();

   

    return 0;
}