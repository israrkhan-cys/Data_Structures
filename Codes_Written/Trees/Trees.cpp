#include <iostream>
using namespace std;

class Node{
public:
int data;
Node *left;
Node *right;

Node(int d=0){
    data =d;
    left=nullptr;
    right=nullptr;
}

};

class Tree{
  Node *root;

  
void Insertfirstrightthenleft(int val, int &R, int &L){  //R for right , L for left andthere val will be 0 and 1, 1 mean insertion at that side is done
   Node *newNode = new Node(val);
    if(root== nullptr){
       root->right=newNode;
         R=1;
         return;
    }

   Node *tN = root;
   while(tN!= nullptr){
       if(tN->right == nullptr && R==0){
          tN->right=newNode;
          R=1;
          return;
       } else if(tN->left == nullptr && L==0){
          tN->left=newNode;
          L=1;
          return;
       }
       tN=tN->right;
   }
}


Node * Insertion(Node *node, int val){
   if(node == nullptr){
      return new Node(val);
   }

   if(node->data>val){
      node->left = Insertion(node->left,val);
   } else if(node->data <val){
    node->right= Insertion(node->right,val);
   }
   return node;
}

void inOrder(Node *root){
  if(!root){
    return;
  }
   inOrder(root->left);
   cout<<root->data<<" ";
   inOrder(root->right);
}

void printPath(Node *root, int key){
     if(root== nullptr){return;}

     while (key!=root->data){
           if(key < root->data){
               cout<<root->data<<" ";
               root=root->left;
           } else{
               cout<<root->data<<" ";
               root=root->right;
           }
     }
     cout<<root->data<<" ";
}

void printAncestor(Node *root, int key){
     if(root== nullptr){return;}
     if(key < root->data){
     return printAncestor(root->left,key);
     } else{
      return  printAncestor(root->right,key);
     }
     cout<<root->data<<" ";
}

void print_Top(Node *root){
   if(root==nullptr){
      return;
   }
   Node *temp=root;
   while(temp!=nullptr){
     cout<<temp->data;
     temp=temp->left;
   }
   
   while (root->right !=nullptr){
       cout<<root->right->data;
       root=root->right;
   }
   
}

void PrintingRange(Node *root, int H, int L){
   if(root == nullptr) return;

   PrintingRange(root->left,H,L);
   if(root->data >= L && root->data <=H){
      cout<<root->data<<" ";
   }
   PrintingRange(root->right,H,L);
}

public:
Tree(): root(nullptr){}

void Insert(){
   int d;
   cout<<"Enter value:";
   cin>>d;
   root=Insertion(root,d);
}

void InOrder(){
  cout<<"Tree :";
  inOrder(root->right);
}

void print(){
   int t;
   cin>>t;
   printPath(root,t);
}

void PrintRange(){
   int H;
   cout<<"Enter H";
   cin>>H;
   int L;
   cout<<"Enter L";
   cin>>L;

   PrintingRange(root,H,L);
}

};

int main() {
    Tree t1;
    for(int i=0; i<8; i++){
            t1.Insert();
    }
    // t1.InOrder();
    //t1.print();
    t1.PrintRange();
    
    return 0;
}