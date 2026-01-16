#include <iostream>
using namespace std;

class Node{
public:
int data;
Node *next;

Node(int d): data(d), next(nullptr) {}
};

class SSL{
public:
 Node *head;
 Node *tail;

public:
    SSL(){
      head=nullptr; tail=nullptr;
    }
    
void InsertAtEnd(int data=0){
  
  Node *newNode=new Node(data);
  
  if(head==nullptr){
     head=tail=newNode;
     tail->next=head;
     return;
  }
  tail->next=newNode;
  tail=newNode;
  tail->next=head;
}

void Sort(){
  if(head==nullptr){
    cout<<"List is Empty..Nothing to sort";
    return;
  }
  
  Node *tN=head;
  do{
    Node *tN2=head;
    do{
     if(tN->data >tN2->data){
       int temp =tN->data;
       tN->data=tN2->data;
       tN2->data=temp;
     }
     tN2=tN2->next;
    }while(tN2!=head);
    tN=tN->next;
  }while(tN!=head);
}

void Remove_duplicates(){
    if(head==nullptr){
      return;
    }
    Node *tN =head;
    do{
       Node *tN2=tN->next;
       Node *prev=tN;
      do{
         if(tN->data == tN2->data){
           Node*temp =tN2;
           prev->next=tN2->next;
           delete tN2;
           tN=temp->next;

         }else{
          prev=tN2;
          tN2=tN2->next;
         }
      }while(tN2!=head);
       tN=tN->next;
    }while(tN!=head);
}

void Instersection(SSL s2){
    SSL s3;
    Node *tN=head;
    do
    {
      Node *tN2=s2.head;
      do
      {
        if(tN->data == tN2->data){
          bool flag=true;
          if(s3.head==nullptr){
              flag =true;
          }else{
          Node*tN3 =s3.head;
          do{
            if(tN2->data==tN3->data){
              flag=false;
              break;
            }
            tN3=tN3->next;
          } while (tN3!= s3.head);
        }
          if(flag){
            s3.InsertAtEnd(tN->data);
            break;
          }
        }
        tN2=tN2->next;
      }while(tN2 !=s2.head);
      tN=tN->next;
    } while (tN!=head);
s3.Traversal();

}

void Merge_Sort(SSL s2){
  SSL s3;
  Node *tN=head;

  do{
     s3.InsertAtEnd(tN->data);
    tN=tN->next;
  }while(tN!=head);
   
  Node *tN2=s2.head;
  do{
     s3.InsertAtEnd(tN2->data);
    tN2=tN2->next;
  }while(tN2!=s2.head);

  s3.Traversal();
}

void addTwoLists(SSL s2){
 SSL s3;
 int carry=0;
 reverseCSLL();
 s2.reverseCSLL();

 Node *tN=head;
 Node *tN2=s2.head;

 do
 {
  int d1 = tN ? tN->data:0;
  int d2 = tN2 ?tN2->data : 0;

  int sum = d1+d2+carry;
  carry= sum/10;
  s3.InsertAtEnd(sum%10);

  tN =(tN->next!=head)? tN->next: nullptr;
  tN2= (tN2->next!=s2.head) ? tN2->next :nullptr;
 } while (tN!=nullptr || tN2!=nullptr);

  if(carry!=0){
    s3.InsertAtEnd(carry);
  }
 reverseCSLL();
 s2.reverseCSLL();
 s3.reverseCSLL();

 s3.Traversal(); 
}

void reverseCSLL() {
    if (head == nullptr || head->next == head) return;

    Node *prev = nullptr, *curr = head, *next = nullptr;
    Node *last = head;

    // iterate till we come back to head
    do {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (curr != head);

    // fix circularity
    head->next = prev;
    head = prev;
}


void Traversal(){
if(head==nullptr){
  cout<<"List is Empty ";
  return;
}
Node *tN=head;

do{
 cout<<tN->data<<"->";
 tN=tN->next;
}while(tN!=head);
}

};

int main(){
SSL s1;

s1.InsertAtEnd(1);
s1.InsertAtEnd(2);
s1.InsertAtEnd(3);

SSL s2;
s2.InsertAtEnd(3);
s2.InsertAtEnd(2);
s2.InsertAtEnd(5);

//s1.Sort();
s1.Traversal();
cout<<endl;
s2.Traversal();
cout<<endl;

//s1.Remove_duplicates();
//s1.Instersection(s2);
s1.addTwoLists(s2);

//s1.Traversal();


}
