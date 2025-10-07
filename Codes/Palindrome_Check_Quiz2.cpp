#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class ssl{
public:
    Node* head;

    ssl(){
        head = nullptr;
    }


void insertAtStart(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
}

void Palindrome_check() {
        ssl temp;
        Node* tN = head;
        while (tN != nullptr) {
            temp.insertAtStart(tN->data);
            tN = tN->next;
        }

        bool isPalindrome = true;
        Node* tN2 = head;
        Node* tN3 = temp.head;

        while (tN2 != nullptr && tN3 != nullptr) {
            if (tN2->data != tN3->data) {
                isPalindrome = false;
                break;
            }
            tN2 = tN2->next;
            tN3 = tN3->next;
        }

        if (isPalindrome) {
            cout << "It is Palindrome" << endl;
        } else {
            cout << "It is not Palindrome" << endl;
        }
    }
};

int main() {
    ssl list;
    list.insertAtStart(1);
    list.insertAtStart(2);
    list.insertAtStart(3);
    list.insertAtStart(2);


    list.Palindrome_check();

}
