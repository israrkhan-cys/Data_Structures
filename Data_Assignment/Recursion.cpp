#include <iostream>
using namespace std;


//Fxn for Print All Subsets of a Given Set (Power Set Problem)
void printSubsets(int arr[], int n, int index, int sub[], int sub_Size) {
    if (index == n) {
        cout << "{ ";
        for (int i = 0; i < sub_Size; i++) {
            cout << sub[i] << " ";
        }
        cout << "}" << endl;
        return;
    }
    printSubsets(arr, n, index + 1, sub, sub_Size);
    sub[sub_Size] = arr[index];
    printSubsets(arr, n, index + 1, sub, sub_Size + 1);
}

//Fxn for generate all permutations of a string
void string_permutations(string str, int left, int right) {
    if (left==right) {
        cout<<str<< endl;
    } else {
        for (int i = left; i <= right; i++) {
                char temp= str[left];
                str[left]=str[i];
                str[i]=temp;

                string_permutations(str, left + 1, right);
                temp= str[left];
                str[left]=str[i];
                str[i]=temp;
        }
    }

}


//Fxn for Subset Sum Problem
void subset_sum(int arr[], int n, int index, int current_sum, int target_sum) {
    if (index == n) {
        if (current_sum == target_sum) {
            cout<<"Subset found with sum " <<target_sum<<endl;
        }
        return;
    }
    subset_sum(arr, n, index + 1, current_sum, target_sum);
    current_sum += arr[index];
    subset_sum(arr, n, index + 1, current_sum, target_sum);
}


//Fxn for Fibonacci Series
int fib(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n-1) + fib(n-2);
}

//Fxn for reverse a string
void reverse_string(string &str, int start, int end) {
    if (start >= end)
        return;
     char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverse_string(str, start + 1, end - 1);
}

//Fxn for finding power of a number
int power(int X, int n) {
    if (n == 0)
        return 1;
    return X * power(X, n - 1);
}


//Fxn for coiunting number
int count_digits(int n) {
    if (n == 0)
        return 0;
    return 1 + count_digits(n / 10);
}

//Bianry search FXn 
void Bianry_search(int arr[],int left,int right,int target) {
    if (left >right) {
        cout<<"Element not found in the array."<< endl;
        return;
    }
    int mid =left + (right - left) / 2;
    if (arr[mid] == target) {
        cout << "Element "<<target<<" found at index "<< mid << "." << endl;
        return;
    }
    if (arr[mid] >target) {
        Bianry_search(arr, left, mid - 1, target);
    } else {
        Bianry_search(arr, mid + 1, right, target);
    }
} 

//Fxn for Find max an array
void find_max(int arr[], int n, int index, int &max_num) {
    if (index ==n) {
        return;
    }
    if (arr[index] >max_num) {
        max_num  = arr[index];
    }
    find_max(arr, n, index + 1, max_num);
}

//count Occurrences of a number in arraay
 int count(int arr[],int n,int i,int target,int &cnt){
    if(i==n){
        return cnt;
    }
    if(arr[i]==target){
        cnt++;
    }
    return count(arr, n, i+1, target, cnt);
}

//Fxn for reversing an array
void reverse_array(int arr[], int start, int end) {
    if (start >= end)
        return;
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    reverse_array(arr, start + 1, end - 1);
}


int main() {
    
  int size;
    cout<<"=======RECURSION OPERATIONS MENU========"<<endl;
    while(true){
         cout<<"1.Insert elements of the array.\n";
        cout<<"2.Print All Subsets of a Given Set (Power Set Problem).\n";
        cout<<"3.Generate all permutations of a string.\n";
        cout<<"4.Fibonacci Series up to N terms.\n";
        cout<<"5.Reverse a string.\n";
        cout<<"6.Find Power of a Number.\n";
        cout<<"7.Count number of digits in an integer.\n";
        cout<<"8.find number using Binary Search.\n";
        cout<<"9.Find maximum element in an array.\n";
        cout<<"10.Count Occurrences of a number in array.\n";
        cout<<"11.Reverse an array.\n";
        cout<<"12.Exit\n";
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;

        switch (choice){
        
        case 1:{
      
        cout<<"Enter Array size: ";
       cin>>size;
        int arr[size];
            cout<<"Enter "<<size<<" elements: ";
            for(int i=0;i<size;i++){
                cin>>arr[i];
            }
            break;
        }
        case 2:{
            cout<<"Enter Array size: ";
            cin>>size;
            int arr[size];
                int sub[size];
                
                cout<<"All Subsets of the Given Set are: "<<endl;
                printSubsets(arr, size, 0, sub, 0);
            }
            break;
        case 3:{
                string str;
                cout<<"Enter a string: ";
                cin.ignore();
                getline(cin, str);
                cout<<"All permutations of the string are: "<<endl;
                string_permutations(str, 0, str.length() - 1);
            }
            break;
        case 4:{
                int n;
                cout<<"Enter number of terms for Fibonacci Series: ";
                cin>>n;
                cout<<"Fibonacci Series up to "<<n<<" terms is: "<<endl;
                for (int i = 0; i <= n; i++) {
                    cout << fib(i) << " ";
                }
                cout<<endl;
            }    
               break;
        case 5:{
                string str;
                cout<<"\nEnter a string to reverse: ";
                cin.ignore();
                getline(cin, str);
                reverse_string(str, 0, str.length() - 1);
                cout<<"\nReversed string is: "<<str<<endl;
            }
            break; 
        case 6:{
                int X, n;
                cout<<"Enter base number (X): ";
                cin>>X;
                cout<<"Enter exponent (n): ";
                cin>>n;
                int result = power(X, n);
                cout<<X<<" raised to the power "<<n<<" is: "<<result<<endl;
            }        
            break;
        case 7:{
                int num;
                cout<<"Enter an integer: ";
                cin>>num;
                int digit_count = count_digits(num);
                cout<<"Number of digits in "<<num<<" is: "<<digit_count<<endl;
            }        
            break;         
         case 8:{
                cout<<"Enter Array size: ";
                cin>>size;
                int arr[size];
                cout<<"Enter elements in sorted order: ";
                for(int i=0;i<size;i++){
                    cin>>arr[i];
                }
                int target;
                cout<<"Enter the element to search: ";  
                cin>>target;
                Bianry_search(arr, 0, size - 1, target);
            }        
            break;   
        case 9:{
                cout<<"Enter Array size: ";
                cin>>size;        
                int arr[size];
                cout<<"Enter "<<size<<" elements: ";
                for(int i=0;i<size;i++){
                    cin>>arr[i];
                }
                int max_num = arr[0];
                find_max(arr, size, 0, max_num);
                cout << "Maximum element in the array is: " << max_num << endl;
            }
            break;
        case 10:{
                cout<<"Enter Array size: ";
                cin>>size;        
                int arr[size];
                cout<<"Enter "<<size<<" elements: ";
                for(int i=0;i<size;i++){
                    cin>>arr[i];
                }
                
                int target;
                cout<<"Enter the number to count occurrences: ";
                cin>>target;
                int count_occurrences = 0;
                count(arr, size, 0, target, count_occurrences);
                cout<<"Number of occurrences of "<<target<<" is: "<<count_occurrences<<endl;
            }
            break;
        case 11:{
                cout<<"Enter Array size: ";
                cin>>size;        
                int arr[size];
                cout<<"Enter "<<size<<" elements: ";
                for(int i=0;i<size;i++){
                    cin>>arr[i];
                }
                reverse_array(arr, 0, size - 1);
                cout<<"Reversed array is: ";
                for(int i=0;i<size;i++){    
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
            }
            break;
        case 12:
            cout<<"Exiting the program."<<endl;
            return 0;
        default:
          
            break;  
        }
        
    }
    
    return 0;
}