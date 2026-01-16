#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    int rtag;   // 1 = thread, 0 = child

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
        rtag = 1;   // initially right is a thread
    }
};
Node* insert(Node* root, int key) {
    Node* parent = NULL;
    Node* curr = root;

    // Find position
    while (curr != NULL) {
        if (key == curr->data)
            return root;   // no duplicates

        parent = curr;

        if (key < curr->data)
            curr = curr->left;
        else {
            if (curr->rtag == 1)
                break;
            curr = curr->right;
        }
    }

    Node* newNode = new Node(key);

    // Empty tree
    if (parent == NULL) {
        root = newNode;
        newNode->right = NULL;
    }
    // Insert as left child
    else if (key < parent->data) {
        parent->left = newNode;
        newNode->right = parent;   // thread to inorder successor
    }
    // Insert as right child
    else {
        newNode->right = parent->right;
        parent->right = newNode;
        parent->rtag = 0;   // now right is real child
    }

    return root;
}



Node* leftMost(Node* node) {
    while (node != NULL && node->left != NULL)
        node = node->left;
    return node;
}
void inorder(Node* root) {
    Node* curr = leftMost(root);

    while (curr != NULL) {
        cout << curr->data << " ";

        // If thread, follow successor
        if (curr->rtag == 1)
            curr = curr->right;
        else
            curr = leftMost(curr->right);
    }
}
int main() {
    Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder Traversal of Right Threaded BST:\n";
    inorder(root);

    return 0;
}