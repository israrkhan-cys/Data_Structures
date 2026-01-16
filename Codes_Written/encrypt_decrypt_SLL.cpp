#include<iostream>
using namespace std;

class Node{
public:
    char data;
    Node* prev;
    Node* next;

    Node(char c){
        data = c;
        prev = NULL;
        next = NULL;
    }
};

class D_LinkedList{
private:
    Node* head;
    Node* tail;

public:
    D_LinkedList(){
        head = NULL;
        tail = NULL;
    }

void insert(){
        char c;
        cout<<"enter the character: ";
        cin>>c;
        Node* newNode = new Node(c);
        if(head==NULL){
            head = tail = newNode;
        } 
        else{
            tail->next = newNode;
            newNode->prev =tail;
            tail = newNode;
        }
    }

void encode(int k){
        Node* temp = head;
        int num;
        while(temp!=NULL){
            temp->data =temp->data + k;

            if(temp->data > 90 && temp->data < 97){
                num = temp->data - 90;
                temp->data = 65 + num -1;
            }

            else if(temp->data > 122){
                num = temp->data - 122;
                temp->data = 97 + num - 1;
            }

            temp = temp->next;
        }
    }

void decode(int k){
        Node* temp = head;
        int num;
        while(temp!=NULL){
            temp->data = temp->data -k;

            if(temp->data < 65 && (temp->data >= 65 - k)){
                num = 65 -temp->data;
                temp->data = 90 - num + 1;
            }

            else if(temp->data < 97 && (temp->data >= 97 - k)){
                num = 97 - temp->data;
                temp->data = 122 - num + 1;
            }
            temp = temp->next;
        }
    }
void display(){
        Node* temp =head;
        while(temp!=NULL){
            cout<<temp->data;
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){
    D_LinkedList word;
    int num;
    int k;

    cout<<"Enter the length of the word: ";
    cin>>num;
    
    for(int i=0; i<num; i++){
       word.insert();
    }
    
    cout<<endl<<"Original Word: ";
    word.display();

    cout<<"Enter number of places to shift: ";
    cin>>k;

    word.encode(k);
    cout<<endl<<"encoded word: ";
    word.display();

    word.decode(k);
    cout<<"Decoded word: ";
    word.display();

    return 0;
}

