#include <iostream>
#include <queue>
using namespace std;


class Node{
    public:
    string vechile;
    Node *next;
   
    Node(string name){
        vechile =name;
        next =nullptr;
    }
};

class Parking{

    queue<Node*> q;
    int Cap;
    Node* head;
    int count;

    public:
Parking(int cap){
    Cap=cap;
    count=0;
    head = nullptr;
}

void Add(string v){
    Node *newNode =new Node(v);
    if(count == Cap){
        q.push(newNode);
        return;
    }

    if(head == nullptr){
        head=newNode;
    } else {
        newNode->next = head;
        head =newNode;
    }
     count++;
}


void Remove(string n){
    if(count ==0){
        
    }
    Node *temp= head;
    head=head->next;
    delete temp;
}
};

int main() {
    
    
    return 0;
}