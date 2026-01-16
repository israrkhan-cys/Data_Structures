#include <iostream>
using namespace std;

class List{
private:
  int *data, capacity, size ;

bool isFull(){
    return (size == capacity -1);
}  

bool isEmpty(){
    return (size == -1 );
}

int Insertion(int value , int index){
    if (index>=0 || index <=size){
        for (int i = size; i >=index ; i--){
           data[i+1] = data[i];
        }

    }
    
   if (data[index] == 0){
      if (data[index-1] == 0){
         index = size+1;
      }
   }
   data[index]=value;
   size++;
   return index;
}


void deletion(int index){
   data[index]=0;

   for (int i = index; i < size; i++){
     data[i] = data[i+1];
   }
    size--;  
      
}

void Searching(int value){
    int ind;
    bool flag =false;
    for (int i = 0; i < size; i++){
        if(data[i]== value){
           ind =i;
           flag=true;
           break;
        }
    }

    if(flag){
       cout<<"The Value is at Index: "<<ind<<endl;
    } else { 
        cout<<"Value index not Found!.";
        return;
         
    }
}

void increaseCap(int cap){
    int *newData = new int[cap]();
    for (int i = 0; i <= size; i++){
        newData[i]= data[i];
    }
    data = newData;
    capacity= cap;
}

void Sort(int ch){
   if(ch == 1){
    for (int i = 0; i <= size; i++){
        for (int i = 0; i <= size; i++){
            if(data[i]<data[i+1]){
                int temp =data[i];
                data[i]= data[i+1];
                data[i+1]=temp;
            }
        }   
    }
    cout<<"Data sorted in Descending Order.";
   } else{
    for (int i = 0; i <= size; i++){
        for (int i = 0; i <= size; i++){
            if(data[i]>data[i+1]){
                int temp =data[i];
                data[i]= data[i+1];
                data[i+1]=temp;
            }
        }   
    }
    cout<<"Data ordered in Ascending Order.";
   }

}

public : 
List( int cap ):  capacity(cap), size(-1){
    data = new int[capacity];
    for (int i = 0; i < capacity; i++){
        data[i]= 0;
    }
}


void insertion(){
   if(isFull()){
    cout<<"The lsit is already Full ";
    return;
   }
    int value =0, index=-1; 
    cout<<"Enter value and Index : ";
    cin>>value>>index;
    while (index<0 && index >=capacity){
        cout<<"Enter a Valid Index : ";
        cin>>index;
    }
   index=Insertion(value,index);
   cout<<"\n"<<value<<" inserted at index "<<index<<endl;
}


void Deletion(){
   if(isEmpty()){
    cout<<"List is already Empty .";
    return;
   }
    int index=-1;
   cout<<"Enter index whose value you want  to delete: ";
   cin>>index;
   while (index<0 || index >capacity){
    cout<<"Invalid index.. Enter Agian :";
    cin>>index;
   }
    deletion(index);
}

void Search(){
    if(isEmpty()){
        cout<<"\nList is Empty.\n";
    }
    int value;
    cout<<"Enter value :";
    cin>>value;
    
    Searching(value);
    

}


void increaseCap(){
     int newCAP;
     cout<<"Enter New Capacity :";
     cin>>newCAP;
     while (newCAP<capacity){
        cout<<"Wrong! Enter new Capacity Again .";
        cin>>newCAP;
     }

     increaseCap(newCAP);
}


void Sort(){
    if(isEmpty()){
        cout<<"Array is Empty .Nothing to Sort!.";
        return;
    }
    int ch;
    cout<<"Enter Your Choice for sort (0 =Asc , 1=dsc ) . ";
    cin>>ch;
    Sort(ch);

}

void Display(){
cout<<"\nList : \n";
  for(int i=0; i<capacity; i++){
    cout<<data[i]<<",";
  }
}

};


int main(){
    int num;
    cout<<"Enter The size of the List : ";
    cin>>num;
    List l1(num);
    cout<<"\n";

   
    while(true){
    int ch;
    cout<<"\nOperation to Peform\n";
    cout<<"1.Insert value.\n";
    cout<<"2.delete Value.\n";
    cout<<"3.Search by Value.\n";
    cout<<"4.Display Values.\n";
    cout<<"5.Increase Capacity ."<<endl;
    cout<<"6.Sort."<<endl;
    cout<<"7.Exit Program...";
    cout<<endl;
     cout<<"Enter Your choice :";
     cin>>ch;
    switch (ch){
    case 1:
        l1.insertion(); break;
    case 2:     
        l1.Deletion(); break;
    case 3:
        l1.Search(); break;
    case 4:
       l1.Display(); break;
    case 5:
        l1.increaseCap() ; break;
    case 6:
          l1.Sort(); break;
    case 7:
       cout<<"\nExiting Program.........\n";return 0;      
    default:
      cout<<"Not Valid."; break;
    }

    }



    return 0;
}