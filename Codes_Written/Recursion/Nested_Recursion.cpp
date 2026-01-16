#include <iostream>
using namespace std;

//Conversion of this loops into Recursion 
 /*for(int i=0 ; i<=3; i++){
    for(int j=0; j<=3 ; j+=){
       cout<<i<<" "<<j<<endl;
    }
 }

 */

void printJ(int j, int &i){
  if(j>3){return;}
  cout<<i<<" "<<j<<endl;
  printJ(++j,i);
}

void printI(int i){
    if(i>3){return;}
    printJ(1,i);
    printI(++i);
}

int main(){
    printI(1);

    return 0;
}