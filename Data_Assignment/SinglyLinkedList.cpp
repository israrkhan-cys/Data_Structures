#include <iostream>
using namespace std;

class Node{
public:
  int data;
  Node *next;
  
 Node(int val=0 ): data(val), next(nullptr){}
};

class SSL{
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
     if(tail ==nullptr){
          tail=newNode;
     }
}

void InsertionAtEnd(int d){
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

void DeleteByVal(int target){
  if(isEmpty()){
         cout<<"\nThe List is Empty nothing to delete.\n";
        return;
     }
     Node *tN = head;
     Node *prev= nullptr;
     while(tN !=nullptr && tN->data != target){
          prev = tN;
          tN = tN->next;
     }
     if(tN == nullptr){ cout <<"Value not found !"; return;}
     
     if(tN == head){  
       head = head->next;
       tail->next=head;
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

//Fxn for sorting the Linked list
void Sort(){
      if(isEmpty()){
         cout<<"List is Empty nothing to sort.";
         return;
      }
     Node *tN =head;
       while(tN != nullptr){
          Node *tN2 = tN->next;
          while(tN2 != nullptr){
             if(tN->data > tN2->data){
               int temp = tN->data;
               tN->data = tN2->data;
               tN2->data = temp;
               
             }
             tN2= tN2->next;
          }
          tN= tN->next;
       }
}
//Fxn for countign the number of Nodes in the Linked list 
int CountNodes(){
    Node *tN= head;
    int count =0;
    while(tN!=nullptr){
      tN= tN->next;
      count++;
    }  
   return count;
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
     current->next=prev; //real reversal 
      prev= current;
     current = nextNode;
  }
  head=prev;
  tail=oldhead;

}

//Fxn for finding the middle of the Linked list
Node * Middle_Node(){
     Node *slow = head;
       Node *fast = head;

       while(fast != nullptr && fast->next != nullptr){
          slow = slow->next;
          fast = fast->next->next;
       }
       cout<<"Middle Element of the Linked list :"<<slow->data<<endl;
         return slow;

}
 
//Fxn which delete nth Node from end of a linked list.
void Remove_nth_Node(int k) {
   int count = CountNodes();

   Node* tN = head;
   Node* prev = nullptr;

for (int i=0; i<count-k; i++){
        prev =tN;
        tN=tN->next;
   }

if (prev == nullptr) { 
        head = head->next;
        delete tN;
        if (head == nullptr) tail = nullptr;
    } else {
        prev->next = tN->next;
        if (tN->next == nullptr) tail = prev; 
        delete tN;
    }
}


//Fxn for detection of loop
bool detect_Loop() {
        if(head == nullptr){
            return false;
        }
        
        Node *slow =head;
        Node *fast =head;
        
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast ){
                return true;
            }
        }
        return false;
    }


    //Fxn for Adding two (Numbers)linked list 
void add2Lists(SSL &s2){
   SSL s3;
   int carry=0;

   Reverse_list(); s2.Reverse_list();
   
   Node *tN =head; Node *tN2=s2.head;

   do{
   int d1,d2,sum;
    d1= tN?tN->data:0;
    d2 = tN2?tN2->data:0;

      sum= d1+d2 + carry;
      carry= sum/10;
      
      s3.InsertionAtEnd(sum%10);

      if(tN){tN=tN->next;}
      if(tN2){tN2=tN2->next;}
      
   }while(tN !=nullptr || tN2 != nullptr);

   if(carry!=0){
      s3.InsertionAtEnd(carry);
   }
   cout<<"\n\nResult: ";
   Node *tN3=s3.head;
   while(tN3!=nullptr){
      cout<<tN3->data<<" ";
      tN3= tN3->next;
    }
    cout<<endl;

}
 
//Fxn to reorder linked list like 
void Reorder_list(){
   Node *mid= Middle_Node();

   Node *prev = nullptr;
   Node *current = mid;
   Node *nextNode =nullptr;

   while(current != nullptr){
     nextNode = current->next;
     current->next=prev;
      prev= current;
     current = nextNode;
   }
   Node *first = head;
   Node *second = prev; 
   while(second->next != nullptr){
      Node *temp1 = first->next;
      Node *temp2 = second->next;

      first->next= second;
      second->next= temp1;

      first = temp1;
      second = temp2;
   }

}

//Fxn to remove duplicates from sorted linked list
void Remove_duplicates(){
    if(isEmpty()){
        cout<<"List is Empty nothing to remove duplicates.";
        return;
    }
    Node *tN = head;
    while(tN != nullptr && tN->next != nullptr){
        if(tN->data == tN->next->data){
            Node *dup = tN->next;
            tN->next = tN->next->next;
            delete dup;
        } else {
            tN = tN->next;
        }
    }
}


//Fxn to Reverse group of k nodes
Node  *Reverse_Kgroup(Node *head,int k) {
   if(head == nullptr) return nullptr;

     Node *prev =nullptr;
     Node *curr = head;
     Node *nextN=nullptr;

   int count=0;
   Node *tN =head;
   while(tN!=nullptr){
      count++;
      tN=tN->next;
   }

   if(count<k){ return head;}

   prev =nullptr;
   curr =head;
   int i=0;
   while(i<k){
      nextN=curr->next;
      curr->next=prev;
      prev=curr;
      curr=curr->next;
      i++;
   }

   head->next= Reverse_Kgroup(head,k);
   return prev;
}

 

//Fxn for Display
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


//fxn for merging two sorted Linked lists 
void Merging_two_lists(SSL &s1, SSL &s2){
     s1.tail->next=s2.head;
     s1.tail =s2.tail;
     s2.head=nullptr;
     cout<<"\nMerged two Linked List into One \n";
}



int main(){
   SSL s1;
   SSL s2;

   cout<<"\n=====SINGLY  LINKED LIST OPERATIONS MENU ====\n";
  while(true ){
   system("clear");
   cout<<"1.Insert Values at start :\n";
   cout<<"2.Insert Values at End :\n";
   cout<<"3.Insert After Value :\n"; 
   cout<<"4.Search By value :\n";
   cout<<"5.Delete By Value :\n";
   cout<<"6.Count Nodes :\n";
   cout<<"7.Reverse Linked List : \n";
   cout<<"8.Display :\n";
   cout<<"9.Merge Soted List.\n";
   cout<<"10.Middle of the Linked List.\n";
   cout<<"11.Remove Nth-node from End.\n";
   cout<<"12.Cycle Detection.\n";
   cout<<"13.Add Two linked Lists.\n";
   cout<<"14.Reorder List.\n";
   cout<<"15.Remove Duplicates from Sorted List.\n";
   cout<<"16.Reverse Nodes in k-Group \n";
   cout<<"17.Exit Program ";
   int ch;
   cout<<"\n Enter Your Choice :";
   cin>>ch;
   
   switch(ch){
   case 1:{ 
    int d;
    cout<<"\nEnter value for Insertion :";  cin>>d;
      s1.insertionAtStart(d); break;
   }
   case 2:{
    int d;
    cout<<"\nEnter value for Insertion :";  cin>>d;
   s1.InsertionAtEnd(d); break;
   }
   case 3:{
      s1.InsertAfterVal(); break;
   }
   case 4:{
     s1.SearchByValue(); break;
   }
   case 5:{
      int target;
      cout<<"Enter Target Value for deletion :"; cin>>target;
      s1.DeleteByVal(target); break;
   }
   case 6:{
      cout<<"\nNUmber of Nodes in the Linked List is : "<<s1.CountNodes()<<endl; break;
   }
   case 7:{
   s1.Reverse_list(); break;
   }
   case 8:{
   s1.Display(); break;
   }
   case 9:{
      SSL s2;   s2.insertionAtStart(4); s2.insertionAtStart(5); s2.insertionAtStart(6);
      Merging_two_lists(s1,s2);
      break;
   }
   case 10:{
         s1.Middle_Node(); break;
   }
   case 11:{
      int k;
      cout<<"Enter K value :" ; cin>>k;
      s1.Remove_nth_Node(k); break;
   }
   case 12:{
       if(s1.detect_Loop()){
         cout<<"\nTrue.\n ";
       }else {
         cout<<"\nFalse.\n";    
       }
       break;
   }
   case 13:{
      SSL s2;   s2.insertionAtStart(1); s2.insertionAtStart(1); s2.insertionAtStart(1);
      s1.add2Lists(s2);break;
   }
   case 14:{
      s1.Reorder_list(); break;
   }
   case 15:{
      s1.Sort();
      s1.Remove_duplicates(); break;
   }
   case 16:{
      int k; cout<<"Enter K value : "; cin>>k;
      s1.Reverse_Kgroup(s1.head,k);
     
   }
   case 17:{
    cout<<"Exiting Program.............!!! ";   return 0;
   }
   default: {
     cout<<"Invalid Choice , try Agian"; break;
   }
   }
  }
  return 0;
  }
