#include <iostream>
#include <queue>
using namespace std;

class Node {
    public:

    int val;
    Node *left;
    Node *right;
    Node *parent;

    Node(int d=0){
     val=d;
     left = nullptr;
     right=nullptr;
     parent=nullptr;
    }


};

class Maxheap{
     Node *root;
public:
Maxheap(){
    root=nullptr;
}

void Insert(int val){
    Node *newNode = new Node(val);
    if(root==nullptr){ root= newNode; return;}
   
    queue<Node *> q;
    q.push(root);

    while(!q.empty()){
          Node *temp = q.front();
          q.pop();

          if(temp->left == nullptr){
             temp->left = newNode;
             newNode->parent = temp;
             heapifyUp(newNode);
             return;
          } else if(temp->right == nullptr){
             temp->right=newNode;
             newNode->parent=temp;
             heapifyUp(newNode);
             return;
          }else {
            q.push(temp->left);
            q.push(temp->right);
          }
    }
}

void heapifyUp(Node *node){   
    while(node ->parent && node->parent->val > node->val){
            int temp = node->parent->val;
            node->parent->val= node->val;
            node ->val= temp;
    
    node=node->parent;
}
    
} 

void Level_order(){
    if(root == nullptr){
        return;
    }
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node * temp = q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left != nullptr){
              q.push(temp->left);
        }
        if(temp->right != nullptr){
            q.push(temp->right);
        }
    }
}

};

int main() {
    Maxheap m1;

    m1.Insert(1);
    m1.Insert(4);
    m1.Insert(3);
    m1.Insert(2);
    m1.Insert(7);
    m1.Insert(8);
    m1.Insert(9);
    m1.Insert(10);

    m1.Level_order();

    
    return 0;
}