#include <iostream>
#include <queue>  //only used for the level order traversal Question 
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

    if(root == nullptr){
        return -1;
    }

    return root->hieght;
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

Node *RightRotation(Node *UNB){
    Node *elevateNode = UNB->left;
    Node *rightSubTree = elevateNode->right;

    elevateNode->right= UNB;
    UNB->left =rightSubTree;

    Update_hieght(UNB);
    Update_hieght(elevateNode);

    return elevateNode;
}


Node *LeftRotation(Node *UNB){
     Node *elevateNode= UNB->right;
     Node *lst= elevateNode->left;

      elevateNode->left=UNB;
      UNB->right= lst;

      Update_hieght(UNB);
      Update_hieght(elevateNode);

      return elevateNode;
}

Node *Insert(Node *root, int value, bool &duplicate){
    if(!root){
        Node *newNode = new Node(value);
        return newNode;
    }
    if(value < root->data){
        root->left= Insert(root->left, value, duplicate);
    }else if(value > root->data){
        root->right= Insert(root->right, value, duplicate);
    }else{
        duplicate = true;
        return root;
    }
    
    root= BalanceTree(root);
    return root;
}

   
Node * BalanceTree(Node *UNB){

    Update_hieght(UNB);
    int BF = getbalance(UNB);

    if(BF <= 1 || BF >= -1){
        return UNB;
    }

    //case  LL
    if(BF > 1 && getbalance(UNB->left) >= 0 ){
        return RightRotation(UNB);
    }

    //case LR
    if(BF > 1 && getbalance(UNB->left) <0){
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


//Fxn for Find Balance Factor of Every Node
void BalanceFactor(Node *root){
    if(!root) return;
    BalanceFactor(root->left);
    cout<<"Balance Factor of "<<root->data<<" is : "<<getbalance(root)<<endl;
    BalanceFactor(root->right);
}




//Fxn for Check if a Given Tree is AVL Balanced or not
void check_balance(Node *root){
    if(!root) return;
   check_balance(root->left);
    int bf = getbalance(root);
    if(bf >1 || bf <-1){
        cout<<"Tree is unbalanced at Node : "<<root->data<<endl;
        return;
    }
    check_balance(root->right);
}

//Fxn to Convert Sorted Array to Balanced AVL Tree
Node * AVLtoTree(int arr[],int size){
   if(size <=0) return nullptr;
    int mid = size/2;
    Node *node = new Node(arr[mid]);
    node->left = AVLtoTree(arr, mid);
    node->right = AVLtoTree(arr + mid +1, size - mid -1);
    Update_hieght(node);
    return node;
}

//fxn for Level Order Traversal
void level_order_traversal(Node *root){
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *curr = q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left) q.push(curr->left);
        if(curr->right)q.push(curr->right);
    }
    cout<<endl;
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

void Delete(){
    int k; cout<<"Enter value to delete : "; cin>>k;
    bool found = false;
    root = deleteNode(root, k, found);
    found ? cout<<"Value Deleted \n" : cout<<"Value not found \n";
}

void BalanceFactor(){
    BalanceFactor(root);
}

void check_balance(){
    check_balance(root);
}

void SortedArrayToAVL(int arr[], int size){
    root = AVLtoTree(arr, size);
    cout<<"AVL Tree Constructed from Sorted Array \n";

}
};




int main() {
    AVL a1;

    cout<<"================= AVL Tree OPERATIONS MENU ================\n";
    while (true){
        cout<<"1.Insert a value .\n";
        cout<<"2.Delete a Value .\n";
        cout<<"3.Find Balance Factor of every Node .\n";
        cout<<"4.Check if the Tree is AVL Balanced or not .\n";
        cout<<"5.Construct an AVL Tree from a Given Sorted Array .\n";
        cout<<"6.Level Order Traversal of the AVL Tree .\n";
        cout<<"7.Exit\n";
        cout<<"Enter your choice : ";
        int choice; cin>>choice;
        switch(choice){
            case 1:
                a1.Insert();
                break;
            case 2:
                a1.Delete();
                break;
            case 3:
                a1.BalanceFactor();
                break;
            case 4:
                a1.check_balance();
                break;
            case 5:{
                int n; cout<<"Enter array size: "; cin>>n;
                int *arr = new int[n];
                cout<<"Enter "<<n<<" elements in Sorted order : \n";
                for(int i=0;i<n;i++)
                    cin>>arr[i];
                 AVL temp;   
                temp.SortedArrayToAVL(arr, n);
                delete []arr;
                break;
            }    
            case 6:
                cout<<"Exiting ..\n";
                return 0;
            default:
                cout<<"Invalid Choice .. Try Again \n";
        }
    }
    
    
    return 0;
}