#include <iostream>
#include <stack>
using namespace std;


class Queue{
        stack <int> s1,s2;
public:

void Enqueue(int val){
       if(s1.empty()){
            s1.push(val);
            return;
       }

       while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
       }
       s2.push(val);
       while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
       }
}

void Dequeue(){
       if(!s1.empty()){
        return;
       }
       s1.pop();
}
void Display(){
     if(s1.empty()){
        return;
     }

     while(!s1.empty()){
        int temp = s1.top();
          cout<<temp<<" ";
          s1.pop();
          s2.push(temp);
     }
}


};

int main() {

      Queue q1;
     
    q1.Enqueue(1000);
    q1.Enqueue(1000);
    q1.Enqueue(1000);
    q1.Enqueue(1000);
    q1.Enqueue(1000);
    q1.Enqueue(1000);

    q1.Display();

    
    return 0;
}