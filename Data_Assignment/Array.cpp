#include <iostream>
#include <climits>
using namespace std;


class Array{
public:
    int *arr;
    int size;
    Array(int s){
        size = s;
        arr = new int[size];
    }
 
    //implementing various array operations : Insertion, deletion, display, anad zero will remain exmpty locations
 void Insert(int i, int value){
    if(i<0 || i >=size){
        cout<<"Invalid Index for Insertion.\n";
        return;
    }
    arr[i] = value;
    cout<<"Inserted "<<value<<" at index "<<i<<".\n";
 }

 void Delete(int index){
    if(index < 0 || index >= size){
        cout<<"Invalid Index for Deletion.\n";
        return;
    }
    cout<<"Deleted element "<<arr[index]<<" from index "<<index<<".\n";
    arr[index] = 0; 
 }

    void Display(){
        cout<<"Array elements are: ";
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};

//Fxn to remove duplicates from sorted array
void Remove_duplicates(int arr[], int &size) {
    if (size == 0 || size == 1)
        return;

    int j = 0; 

    for (int i = 0; i < size - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            arr[j++] = arr[i];
        }
    }
    arr[j++] = arr[size - 1]; 

    size = j; 
    cout<<"Array after removing duplicates:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//Fxn to Find length Longest Cnonsecutive Sequence in an unsorted array
void Longest_consecutive_sequence(int arr[], int size){

     for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]>arr[j]){
                int temp =arr[i];
                arr[i]=arr[j];
                arr[j]= temp;
            }
        }
    }
    int seq_count =0;
    int count=0;
    for(int i=0;i<size-1;i++){
        if(arr[i]+1 == arr[i+1]){
            count++;
        }
        else{
            if(count>seq_count){
                seq_count=count;
            }
            count=0;
        }
    }
    
    if(count>seq_count){
        seq_count=count;
    }
    cout<<"\nLength of Longest Consecutive Sequence is: "<<seq_count+1<<endl;

}

//Fxn for 3Sum (Find Triplets that Sum to Zero)
void Sum_zero(int arr[], int size){
     cout<<"\nTriplets with sum zero are:\n";
    for(int i=0;i<size-2;i++){
        for(int j=i+1;j<size-1;j++){
            for(int k=j+1; k<size ;k++){
                int sum = arr[i] + arr[j] + arr[k];
                if(sum == 0){
                 cout<<"("<<arr[i]<<","<<arr[j]<<","<<arr[k]<<") , ";
                }
            }
        }
    }

    cout<<"\n"; 
}

//Fxn to move zeroes to the end of the array 
void Move_zeroes(int arr[], int size){
    int count =0; 
    for(int i=0;i<size;i++){
        if(arr[i]!=0){
            arr[count++]= arr[i];
        }
    }
    while(count<size){
        arr[count++] = 0;
    }
}

//Fxn for Find the element that appears more than n/2 times in the array (it always exists).
void More_than_n_by_2(int arr[], int size){
    int count =1;
    int element = arr[0];
    for(int i=1;i<size;i++){
        if(arr[i]==element){
            count++;
        }
        else{
            count--;
            if(count == 0){
                element = arr[i];
                count = 1;
            }
        }
    }
    cout<<"Element that appears more than n/2 times is: "<<element<<endl;
}

//Fxn for coutn of Subarray Sum Equals K
void Subarray_sum_k(int arr[], int size, int k){
    int count =0;
    for(int i=0;i<size;i++){
        int sum =0;
        for(int j=i;j<size;j++){
            sum += arr[j];
            if(sum == k){
                count++;
            }   
        }
    }
    cout<<"Total number of continuous subarrays whose sum equals "<<k<<" is: "<<count<<endl;
}

//Fxn for Find the length of the longest subarray whose sum is less than or equal to K.
void Longest_subarray_sum_k(int arr[], int size, int k){
    int max_length =0;
    for(int i=0;i<size;i++){
        int sum =0;
        for(int j=i;j<size;j++){
            sum += arr[j];
            if(sum <= k){
                int length = j - i + 1;
                if(length > max_length){
                    max_length = length;
                }
            }
        }
    }
    cout<<"Length of the longest subarray whose sum is less than or equal to "<<k<<" is: "<<max_length<<endl;
}



int main() {
    int size;
    cout<<"Enter size of Array: ";
    cin>>size;
    int *arr = new int[size];
    cout<<"Enter "<<size<<" elements for the Array:\n";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
     
    cout<<"=================ARRAY OPERATIONS MENU===============";
    while (true){
        cout<<"1.Display Array :\n";
        cout<<"2.Remove Duplicates from Array :\n";
        cout<<"3.Find Length of Longest Consecutive Sequence in Array :\n";
        cout<<"4.Find Triplets with Sum Zero in Array :\n";
        cout<<"5.Move Zeroes to End of Array :\n";
        cout<<"6.Find Element that appears more than n/2 times in Array :\n";
        cout<<"7.Count of Subarray Sum Equals K :\n";
        cout<<"8.Length of Longest Subarray whose sum is less than or equal to K :\n";
        cout<<"9.Exit\n";
        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;
       
     switch(choice){
        case 1: { 
            cout<<"Array elements are:\n";
            for(int i=0;i<size;i++){
               cout<<arr[i]<<" ";}
            cout<<endl;
            
            break;
        }
        case 2: {
            cout<<"Array after removing duplicates:\n";
            Remove_duplicates(arr, size);
            break;
        }
        case 3:{
            Longest_consecutive_sequence(arr, size);
            break;   
        }
        case 4:{
            Sum_zero(arr, size);
            break;  
        }
        case 5:{
            Move_zeroes(arr, size);
            cout<<"Array after moving zeroes to the end:\n";
            for(int i=0;i<size;i++) cout<<arr[i]<<" ";
            cout<<endl;
            break;  
        }
        case 6:{
            More_than_n_by_2(arr, size);
            break;
        }
        case 7:{
            int k;
            cout<<"Enter value of K: ";
            cin>>k;
            Subarray_sum_k(arr, size, k);
            break;
        }
        case 8:{
            int k;
            cout<<"Enter value of K: ";
            cin>>k;
            Longest_subarray_sum_k(arr, size, k);
            break;
        }   
        case 9: {
            delete[] arr;
            cout<<"Exiting the program.\n";
            return 0;
        }
        default: {
            cout<<"Invalid choice. Please try again.\n";
            break;
        }
    }
    }
    return 0;
}