#include <iostream>
using namespace std;

class Node {
public:
   int data;
   Node *prev , *next ;
   
  Node (int d=0) :data(d) ,prev(nullptr) , next(nullptr){} 
};

class DLL{

public:
  Node *head;
  Node *tail;

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

void InsertAtEnd(int d){
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
    if(head==nullptr){
        cout<<"List is Empty!"; return;
    }
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

//Fxn for sorting the list
void SortList(){
    if(head==nullptr){
    cout<<"List is Empty !"; return;
    }
    
   Node *tN=head;
      while(tN!=nullptr){
        Node *tN2 = tN->next;
        while(tN2!=nullptr){
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



//Fxn for counting  number of nodes
int CountNodes(){
int count=0;
Node *tN=head;

while(tN!=nullptr){
  count++;
  tN= tN->next;
}
 return count;
}


//Fxn for Insertion in a sorted list
void Insert_in_sorted_list(int d){
   Node *newNode= new Node(d);
   
   if(head==nullptr){
     head= tail= newNode; return;
   }
   
   if(d < head->data){
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
      return;
   }
   
   Node *tN = head;
   while(tN!=nullptr){
     if(d <= tN->data){
        newNode->next = tN;
        newNode->prev = tN->prev;
        tN->prev->next = newNode;
        tN->prev = newNode;
        return;
     }
     tN= tN->next;
   }
   
   
   tail->next = newNode;
   newNode->prev = tail;
   tail = newNode;
}      
  
//Fxn to delete all occurrences of a given key
void DeleteAllOccurrences(int key){
  if(head==nullptr){
  cout<<"list is Empty:"; return;
}

while(true){
  Node *tN= head;
bool found =false;
while(tN!=nullptr){
 if(tN->data ==key){
    found=true;
    break;
 }
 tN=tN->next;
}
if(!found){
  cout<<"\nAll Occurrences of "<<key<<" Deleted Successfully.\n"; return;
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
}

}

//Fxn for Find Pairs with the Given Sum in sorted list
void Pairs_Sum(int sum){
   if(head==nullptr ){
  cout<<"list is Empty."; return;
} 
if(head->next == nullptr){
   cout<<"Only one element in the list.\n";
}

Node *start =head;
Node *end =tail;
bool found =false;

cout<<"Pairs with sum are : ";
while(start !=nullptr && start != end->next){
   int s= start->data + end->data;
   if(s==sum){
      cout<<"("<<start->data<<","<<end->data<<") , ";
      found =true;
      start= start->next;
      end = end->prev;
   } else if(s < sum){
      start= start->next;
   } else{
      end = end->prev; 
    }
}
cout<<endl;
if(!found){
   cout<<"No such pairs found with the Given sum \n";
}
}  

//Fxn to rotate the linked list by N nodes
void Rotate_list(int n){
    if(head == nullptr || n >= CountNodes()){
      cout<<"list Empty OR not number of Nodes less than N \n"; return;
   }

   while(n>0){
      Node *temp=head;
      head=head->next;
      head->prev=nullptr;
      tail->next = temp;
      temp->prev = tail;
      temp->next = nullptr;
      tail=temp;
      n--;
   }

   Display();
}

//Fxn to Merge Two Sorted Doubly Linked Lists
void merge_lists(DLL &d2){
    if(head == nullptr){
        head = d2.head;
        tail = d2.tail;
        d2.head = d2.tail = nullptr;
        return;
    }

    if(d2.head == nullptr) return;

    Node *tN = head;
    Node *tN2 = d2.head;

    Node *MergedHead = (tN->data < tN2->data) ? tN : tN2;
    if(MergedHead == tN) tN = tN->next;
    else tN2 = tN2->next;

    Node *last = MergedHead;

    while(tN != nullptr && tN2 != nullptr){
        if(tN->data < tN2->data){
            last->next = tN;
            tN->prev = last;
            tN = tN->next;
        } else {
            last->next = tN2;
            tN2->prev = last;
            tN2 = tN2->next;
        }
        last = last->next;
    }

    while(tN != nullptr){
        last->next = tN;
        tN->prev = last;
        last = tN;
        tN = tN->next;
    }

    while(tN2 != nullptr){
        last->next = tN2;
        tN2->prev = last;
        last = tN2;
        tN2 = tN2->next;
    }

    head = MergedHead;
    tail = last;
   d2.head = d2.tail = nullptr;
}

//Fxn for Find Triplets with Given Sum in a Sorted Doubly Linked List
void Triplets_sum(int sum){
     if(head==nullptr){
      cout<<"List is Empty.\n"; return;   
     }
     if(head->next == nullptr || head->next->next == nullptr){
      cout<<"Less than 3 nodes in the list.\n";
      return;
   }
      Node *tN= head;
      Node *tN2= head->next;
      Node *tN3=tail;

      bool found =false;
      cout<<"\nTriplets with sum are : ";
      while(tN!=nullptr){
         tN2= tN->next;
         tN3= tail;
         while(tN2 != nullptr && tN2 != tN3 && tN3 != tN2->prev){
            int s = tN->data + tN2->data + tN3->data;
            if(s == sum){
               cout<<"("<<tN->data<<","<<tN2->data<<","<<tN3->data<<") , ";
               found =true;
               tN2= tN2->next;
               tN3= tN3->prev;
            } else if(s < sum){
               tN2= tN2->next;
            } else{
               tN3= tN3->prev;
           }
         }
          tN= tN->next;

      }
      if(!found){
         cout<<"No such triplets found with the Given sum \n";
      } else{
         cout<<endl;
      }
      return;
   }


//Fxn for merging K Sorted Doubly Linked Lists 
DLL merge_k_lists(DLL lists[], int start, int end) {
    if(start > end) return DLL();       
    if(start == end) return lists[start];

    int mid = start + (end - start) / 2; // find mid point

    DLL left = merge_k_lists(lists, start, mid); // merge left half first
    DLL right = merge_k_lists(lists, mid + 1, end);

    left.merge_lists(right);  

    return left;
}

//Fxn for Reverse Doubly Linked List in Groups of K 
Node* Reverse_in_groups(Node *head, int k){
    if(!head) return nullptr;

    Node *curr =head;
    Node *newHead= nullptr;
    Node *g_Tail= head;
    int count = 0;

    while(curr && count < k){
        Node *nxt = curr->next;
        curr->next = curr->prev;
        curr->prev = nxt;

        newHead = curr;
        curr = nxt;
        count++;
    }

    if(curr){
        Node *rest = Reverse_in_groups(curr, k);
        g_Tail->next = rest;
        if(rest != nullptr) {
         rest->prev = g_Tail;}
    }

    return newHead;
}


//Fxn for Splitting a circualr the list into two halves 
void Split_circular_list(){
   if(head==nullptr){
  cout<<"list is Empty:"; return;}
    tail->next =head;
      head->prev= tail; // making the list circular b/c the fully implemented is for not circular list
     
   Node *slow = head;
   Node *fast = head;
   while(fast->next !=head && fast->next->next != head){
      slow= slow->next;
      fast= fast->next->next;
   }
   
   DLL F_half;
   DLL S_half;
   
   F_half.head = head;
   F_half.tail = slow;

   S_half.head = slow->next;
   S_half.tail = tail;
  
   F_half.tail->next =nullptr;
   F_half.head->prev = nullptr;

   S_half.tail->next = nullptr;
   S_half.head->prev = nullptr;

   cout<<"\n First Half of Circular List : \n";
   F_half.Display();
   cout<<"\n Second Half of Circular List : \n";
   S_half.Display();
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

//Fxn to Convert Binary Tree to Doubly Linked List (in-order traversal)
void TreeConversion(DLL &d1 , Node *treeRoot){
    if(treeRoot == nullptr) return;

    TreeConversion(d1, treeRoot->prev); 
    d1.InsertAtEnd(treeRoot->data); 
    TreeConversion(d1, treeRoot->next);
}


int main(){
  DLL s1; 

//Small tree for testing the conversion into DLL  
Node* tree_root = new Node(10);
tree_root->prev = new Node(5);   //left child treated as prev  and next as right child
tree_root->next = new Node(20);
tree_root->prev->prev = new Node(3);
tree_root->prev->next = new Node(7);
tree_root->next->prev = new Node(15);
tree_root->next->next = new Node(25);
DLL temp; //for storing the converted tree


  cout<<"===== Doubly Linked List OPERATIONS MENU =====\n";  
  while(true){
   cout<<"1.Insert Values at start :\n";
   cout<<"2.Insert Values at End :\n";
   cout<<"3.Insert After Value :\n"; 
   cout<<"4.Delete By Value :\n";
   cout<<"5.Count Nodes :\n";
   cout<<"6.Reverse Linked List : \n";
   cout<<"7.Sort List : \n";
   cout<<"8.Display :\n";
   cout<<"9.Insert in Sorted List :\n";
   cout<<"10.Delete All Occurrences of a given key :\n";
   cout<<"11.Find Pairs with thes Given Sum :\n";
   cout<<"12.Rotate Linked list by N nodes.\n";
   cout<<"13.Merge Two Sorted Doubly Linked Lists.\n";
   cout<<"14.Convert Binary Tree to Doubly Linked List.\n";
   cout<<"15.Find Tiplets with Given Sum :\n";
   cout<<"16.Merge K Sorted Doubly Linked Lists.\n";
   cout<<"17.Reverse Doubly Linked List in Groups of K.\n";
   cout<<"18.Exit Program ";
   int ch;
   cout<<"\n Enter Your Choice :";
   cin>>ch;
   
    switch(ch){
   case 1:{
      s1.InsertAtStart(); break;
   }
   case 2:{
      int d; cout<<"Enter Value for Insertion : "; cin>>d;
   s1.InsertAtEnd(d); break;
   }
   case 3:{
      s1.InsertAfterVal(); break;
   }
   case 4:{
   s1.DeleteByVal(); break;
   }
   case 5:{
   cout<<"\nNumber of Nodes in the List is : "<<s1.CountNodes(); break;
   }
   case 6:{
   s1.Reverse_list(); break;
   }
   case 7:{
   s1.SortList(); break;
   }
   case 8:{
   s1.Display(); break;
   }
   case 9:{
    s1.SortList();
    int d ; cout<<"Enter Value to insert in sorted list :"; cin>>d;
   s1.Insert_in_sorted_list(d); break;
   }
   case 10:{
    int key; cout<<"Enter Key to delete all occurrences :"; cin>>key;
    s1.DeleteAllOccurrences(key); break;
   }
   case 11:{
      s1.SortList();
    int sum; cout<<"Enter Sum to find pairs :"; cin>>sum;
    s1.Pairs_Sum(sum); break;
   }
   case 12:{
     int n; cout<<"Enter n Value: "; cin>>n;
     s1.Rotate_list(n); break;
   }
   case 13:{
     DLL s2;
     cout<<"Enter Values for Second List : \n";
     while(true){
       int d; cout<<"Enter Value (or -1 to stop): ";
       cin>>d;
       if(d == -1) break;
       s2.InsertAtEnd(d);
     }
     s1.merge_lists(s2); 
       cout<<"After Merging Two Lists : \n";
     s1.Display();
       break;
   }
   case 14:{
     cout<<"Converting Binary Tree to Doubly Linked List...\n";
     TreeConversion(temp, tree_root);
     temp.Display();
     break;
   }
   case 15:{
    s1.SortList();
    int sum; cout<<"Enter the Target sum : "; cin>>sum;
    s1.Triplets_sum(sum); break;
   }
   case 16:{
     int k; cout<<"Enter number of lists to merge :"; cin>>k;
     DLL *lists = new DLL[k];
     for(int i=0; i<k; i++){
       cout<<"Enter Values for List "<<i+1<<" : \n";
       while(true){
         int d; cout<<"Enter Value (or -1 to stop): ";
         cin>>d;
         if(d == -1) break;
         lists[i].InsertAtEnd(d);
       }
     }
     s1.merge_k_lists(lists, 0, k-1).Display();
     delete[] lists; 
     break;
   }
   case 17:{
     int k; cout<<"Enter group size k :"; cin>>k;
     s1.Reverse_list();
     s1.Display();
     s1.Reverse_in_groups(s1.head, k);
     cout<<"After Reversing in groups of "<<k<<" : \n";
     s1.Display();
     break;
   }
   case 18:{
    cout<<"Exiting Program.............!!! ";   return 0; break;
   }
   default: {
     cout<<"Invalid Choice , try Agian"; break;

}
}
}


 return 0;
}


