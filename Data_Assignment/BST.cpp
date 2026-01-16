#include <iostream>
#include <queue>  // used only for level order traverasal 
using namespace std;


class Node{
public:
  int data;
   Node *left;
   Node *right;

 Node(int d=0)  {
    data =d;
    left=nullptr;
    right =nullptr;
 }

};


class BST{
  Node *root;

 //Fxn for Insertion 
Node *Insert(Node *root,int d){
    if(!root){
        return new Node(d);
    }
    if(d<root->data){
        root->left = Insert(root->left,d);
    }else if(d >root->data){
        root->right = Insert(root->right,d);
    }

    return root;
}
int CountNodes(Node *root){
     if(!root) return 0;
     return 1+ CountNodes(root->left) + CountNodes(root->right);
}
//small helper fxn for finding min
Node * Findmin(Node *root){
     while (root && root->left){
          root=root->left;
     }
     return root;
}


//Fxn for Deletion a value from Tree
Node * Delete(Node * root,int k){
     if(!root){
        return root;
    }
    if(k<root->data){
        root->left = Delete(root->left,k);
    }else if(k >root->data){
        root->right = Delete(root->right,k);
    }else {
       if(!root->left){
            Node *temp= root->right;
            delete root;
            return temp;
       } else if(!root->right){
          Node *temp =root->left;
          delete root;
          return temp;
       }else {
    Node *replace = Findmin(root->right);
    root->data= replace->data;
    root->right=Delete(root->right,replace->data);
}
}
   return root;
}

//Inorder traversal for Displaying the BST
void Inorder(Node *root){
    if(root){
        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }
}

bool isMinheap(Node *root){
    if(!root) return true;

    if(!root->left && !root->right) return true;
     
    if(!root->right){
        
        return (root->data <= root->left->data) && isMinheap(root->left);

    }else{
        return (root->data <= root->left->data) && (root->data <=
                root->right->data) &&
                isMinheap(root->left) && isMinheap(root->right);
                
    }


}

void Deepest_Common_Ancestor(Node *root, int n1, int n2){
    if(!root) return;

     int arr[100];
        int pathlen=0;
        Node *curr=root;
    while( curr!=nullptr && curr->data != n1){
        arr[pathlen++]=curr->data;
        if(n1 < curr->data){
            curr= curr->left;
        }else{
            curr= curr->right;
        }
    }

    if(curr == nullptr)  cout<<"value not found"<<endl;

    arr[pathlen++]=curr->data;
    curr=root;
    int arr2[100];
    int i=0;

    while(curr != nullptr && curr->data != n2){
        arr2[i++]=curr->data;
        if(n2 < curr->data){
            curr= curr->left;
        }else{
            curr= curr->right;
        }
    }
    if(curr == nullptr)  cout<<"value not found"<<endl;
    arr2[i++]=curr->data;
    int j=0;
    cout<<"Deepest Common Ancestor is :";
    while(j<pathlen && j<i){
        if(arr[j] != arr2[j]){
            cout<<arr[j-1]<<endl;
            return;
        }
        j++;
    }
}


void AllPaths_leafs(Node *root, int path[], int pathlen){
    if(!root) return;

    if(!root->left && !root->right){
        
        cout<<"Path to leaf node :";
        for(int i=0;i<pathlen;i++){
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }else{

        path[pathlen]= root->data;
        pathlen++;

        AllPaths_leafs(root->left,path,pathlen);
        AllPaths_leafs(root->right,path,pathlen);
       pathlen--;
}
}


//Fxn for finding hieght of a tree
int Hieght(Node *root){
    if(!root) return 0;
    return 1+ max(Hieght(root->left), Hieght(root->right));
}

//fxn for counting leaf and non-leaf nodes 
void Count_leaf_nonLeaf(Node *root, int &leafs, int &non_leafs){
     if(root){
        Count_leaf_nonLeaf(root->left,leafs,non_leafs);
        if(!root->left && !root->right){
            leafs++;
        }else{
            non_leafs++;
        }
        Count_leaf_nonLeaf(root->right,leafs,non_leafs);
    }
}

//fxn for Diameter of a Binary tree
int Find_Diameter(Node *root, int &diameter){
    if(!root) return 0;

    int left_height = Find_Diameter(root->left,diameter);
    int right_height = Find_Diameter(root->right,diameter);

    diameter = max(diameter, left_height + right_height);

    return 1 + max(left_height, right_height);
}

//Fxn for checking if tree is BST or not 
void  BST_check(Node *root,bool &isBST){
    static Node *prev = nullptr;
    if(root != nullptr && isBST){
        BST_check(root->left,isBST);
        if(prev != nullptr && root->data <= prev->data){
            isBST = false;
            return;
        }
        prev = root;
        BST_check(root->right,isBST);
    }
}
//Fxn for Printing path from Rooot to the Given Node
Node * PrintPath(Node *root, int k){
    if(!root) return root;

    if(k < root->data){
        cout<<root->data<<" ";
        root->left = PrintPath(root->left,k);
    }else if(k>root->data){
        cout<<root->data<<" ";
        root->right = PrintPath(root->right,k);
    }
    cout<<endl;
    return root;
}

//Fxn for Sum of all left leaves 
void left_leaves_sum(Node *root, int &sum){
   if(root==nullptr) return;
   left_leaves_sum(root->left, sum);
   if(root->left && !root->left->left && !root->left->right){
      sum +=root->left->data;
   }
   left_leaves_sum(root->right,sum);
}

//Fxn to print ansestor of the Given node 
bool printAncestors(Node* root, int k) {
    if (!root) return false;
    if (root->data == k) return true;
    if (k<root->data) {
        if (printAncestors(root->left, k)) {
            cout << root->data << " ";
            return true;
        }
    }
    else if (k > root->data) {
        if (printAncestors(root->right, k)) {
            cout << root->data << " ";
            return true;
        }
    }
    return false;
}

//Fxn that Find Kth Smallest Element in a BST
Node *Find_kth_small(Node *root, int k,int &i){
   if(!root) return nullptr;
  
    Node *temp =Find_kth_small(root->left,k,i);
    if(temp) return temp;
    ++i;
     if(i==k){
      return root;
   }
    return Find_kth_small(root->right,k,i);   
}


public:
   BST(){
    root= nullptr;
   }
 
void create(){
    int d;
    cout<<"Enter Data :"; cin>>d;
    root =Insert(root,d);
}

void Delete(){
    int k;
    cout<<"Enter element to delete from Tree: ";
    cin>>k;
    root = Delete(root,k);
}

void Height(){
    int h=Hieght(root);
    cout<<"Hieght of the tree is :"<<h<<endl;
}

void Count_leaf_nonLeaf(){
    int leafs=0;
    int non_leafs=0;
    Count_leaf_nonLeaf(root,leafs,non_leafs);

    cout<<"\nNumber of leafs are :"<<leafs<<endl;
    cout<<"\nNumber of non-leafs  are:"<<non_leafs<<endl;
}

void Diameter(){
    int diameter=0;
    Find_Diameter(root,diameter);
    cout<<"Diameter of the tree is :"<<diameter<<endl;
}

//Fxn for Level order Traversal
void  Level_order_traversal(){
    if(!root) return;
    queue<Node*> q;

    q.push(root);

    while(!q.empty()){
        Node *curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
    cout << endl;
}

void BST_validity(){
    bool isBST = true;
    BST_check(root,isBST);
    if(isBST){
        cout<<"\nThe tree is a valid BST.\n";
    }else{
        cout<<"\nThe tree is NOT a valid BST.\n";
    }
}

void Print(){
     int k;
     cout<<"Enter the  Node value :"; cin>>k;
    PrintPath(root,k);
}

void left_leaves_sum(){
     int sum=0;
     left_leaves_sum(root,sum);
     cout<<"The sum of all left leaves are :"<<sum<<endl;
}

void Print_Ancestor(){
     int k;
     cout<<"Enter the  Node value :"; cin>>k;
     printAncestors(root,k);
}

void Find_kth_smallest(){
    int k; cout<<"Enter K value :"; cin>>k; int i=0;
    Node *kth_small= Find_kth_small(root,k,i);
    cout<<"Kth Smallest element is : "<< kth_small->data<<endl;

}

void Display(){
    cout<<"BST data ";
    Inorder(root);
    cout << endl;
}
};

int main(){
    BST b1;
     
    cout<<"\n========= BST OPERATIPONS MENU =========\n";
    while (true){
        cout<<"1.Insert Value in Tree.\n";
        cout<<"2.Delete an element from Tree.\n";
        cout<<"3.Display the Tree.\n";
        cout<<"4.Find hieght of the tree :\n";
        cout<<"5.Count Number of leafs and Non leafs nodes :\n";
        cout<<"6.Level order Traversal\n";
        cout<<"7.Find Diameter of the tree :\n";
        cout<<"8.Check if tree is BST or not :\n";
        cout<<"9.Print path to the Given Node from root :\n";
        cout<<"10.Sum of all left leaves.\n";
        cout<<"11.Print Ancestors of the given Nodes.\n";
        cout<<"12.Find Kth smallest Element in BST.\n";
        cout<<"13.Exit\n";
        int choice;
        cout<<"Enter choice : ";
        cin>>choice;
        switch(choice){
            case 1:
                b1.create();
                break;
            case 2:
                b1.Delete();
                break;
            case 3:
                b1.Display();
                break;
            case 4:
                 b1.Height();
                 break;
            case 5:
              b1.Count_leaf_nonLeaf() ;
              break;
            case 6:
              b1.Level_order_traversal();
              break;
            case 7:{
                b1.Diameter();
                break;
            }
            case 8:
                b1.BST_validity();
                break; 
            case 9:
               b1.Print()    ;
               break;
            case 10:
              b1.left_leaves_sum();
              break;
            case 11:
               b1.Print_Ancestor() ;
               break;
            case 12:
                b1.Find_kth_smallest();
                break;
             break;
            case 13:
                 cout<<"Exiting...\n";
                 return 0;
            default:
                cout<<"Invalid choice. Please try again.\n";
        }
    
    }
    return 0;
};