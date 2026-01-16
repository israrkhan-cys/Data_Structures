#include <iostream>
using namespace std;

class Node{
public:
  int data;
  Node *left ,*right; 
  int hieght;

  Node(int d){
    data =d;
    left=nullptr;
    right=nullptr;
    hieght=0;
  }
};


class AVL{
Node *root;

//for hieght of a Node
int hieght(Node *root){
     return root ? root->hieght : -1;
}


void Update_hieght(Node *node){
    int LH = hieght(node->left);
    int RH = hieght(node->right);
    node->hieght = 1+ (LH>RH ? LH:RH);

}

int getbalance(Node *root){
      int lst = hieght(root->left);
      int rst = hieght(root->right);
      return lst-rst;
}

Node* findMin(Node* node){
    while ( node && node->left)
        node = node->left;
    return node;
}

// left rotation
Node *RightRotation(Node *UNB){
    Node *elevateNode = UNB->left;
    Node *rightSubTree = elevateNode->right;

    elevateNode->right= UNB;
    UNB->left =rightSubTree;

    Update_hieght(UNB);
    Update_hieght(elevateNode);

    return elevateNode;
}

//Right Rotation
Node *LeftRotation(Node *UNB){
     Node *elevateNode= UNB->right;
     Node *lst= elevateNode->left;

      elevateNode->left=UNB;
      UNB->right= lst;

      Update_hieght(UNB);
      Update_hieght(elevateNode);

      return elevateNode;
}
   
Node * BalanceTree(Node *UNB){
    Update_hieght(UNB);
    int BF = getbalance(UNB);
    if(BF >1 || BF <-1){
        return UNB;
    }

    //case  LL
    if(BF > 1 && getbalance(UNB->left) >= 0 ){
        return RightRotation(UNB);
    }
    //case LR
    if(BF >1 && getbalance(UNB->left) <0){
          UNB->left= LeftRotation(UNB->left);
          return RightRotation(UNB);
    }
    // case RR
    if(BF <1 && getbalance(UNB->right) <=0 ){
         return LeftRotation(UNB);
    }
    //Case RL
    if(BF <1 && getbalance(UNB->right) > 0){
        UNB->right = RightRotation(UNB->right);
        return LeftRotation(UNB);
    }
    return UNB;
}

Node* deleteNode(Node* node, int key ,bool &found){
    if (!node) return  node;
    if (key < node->data)
        node->left = deleteNode(node->left,key,found);
    else if (key > node->data)
            node->right = deleteNode(node->right,key,found);
        else{
            found = true;
            if (node->left == nullptr){
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr){
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right,temp->data,found);
        }
        node = BalanceTree(node);
    return node;
}




public:
AVL(){
    root=nullptr;
}

void Insert(){
    int val; cout<<"Enter value for insertion : "; cin>>val;
    bool duplicate =false;
    root= Insert(root, val,duplicate);
    duplicate ? cout<<"value is duplicate Not inserted ..\n" : cout<<"Value Inserted ";
}
};




int main() {
    
    
    return 0;
}