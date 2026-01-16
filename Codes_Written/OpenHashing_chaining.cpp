#include <iostream>
using namespace std;


class Node{
    public:
    int key;
    Node *next;

    Node(int d=0){
      key =d;
      next =nullptr;
    }
};


class OpenHashing{
      Node ** table;
      int size;

 public:
    OpenHashing(int si){
        size=si;
        table = new Node*[size];
        for(int i=0; i<size; i++){
             table[i]= nullptr;
        }
    }

int HashFxn(int key){
    return key % size;
}

void Insert(int key){
    int index = HashFxn(key);
     Node *newNode =new Node(key);

     newNode->next= table[index];
     table[index]= newNode;
}

bool Search(int key){
   int index = HashFxn(key);
    Node *tN= table[index];
 
    while(tN != nullptr){
        if(tN->key == key){
            return true;
        }
        tN=tN->next;
    }
return false;    
}

void Delete(int key){
  int index = HashFxn(key);
   Node *tN = table[index];
   Node *prev= nullptr;
   
   while(tN!=nullptr){
       if(tN->key == key){
        if(tN ==table[index]){
             table[index] = tN->next;
        }else{
          prev->next =tN->next;
        }
        delete tN;
        return;
       }
       prev =tN;
       tN=tN->next;
   }
}

void Display(){
    
    Node *tN = table[0];
     int i=0;
    while(i<size){
        cout<<i<<" : ";
        while(tN != nullptr){
              cout<<tN->key<<" -> ";
              tN=tN->next;
        }
        cout<<endl;
        i++;
        tN=table[i];
    }
}


};

int main() {
    OpenHashing h1(10);

    h1.Insert(2);
    h1.Insert(5);
    h1.Insert(4);
    h1.Insert(23);
    h1.Insert(21);
    h1.Insert(216);
    h1.Insert(22);
    h1.Insert(2);
    h1.Insert(2);
    h1.Insert(2);

    

   h1.Display();
   if(h1.Search(216)){
    cout<<"\nFound";
   }
    
    
    return 0;
}