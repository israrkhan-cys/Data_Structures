#include <iostream>
using namespace std;

//Fxn for linear search
void Linearsearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            cout << "Element found at index: " << i << endl;
            return;
        }
    }
    cout << "Element not found" << endl;
}

//Fxn for binary search
void Binarysearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    while(left <=right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == target) {
            cout << "Element found at index: " << mid << endl;
            return;
        }
        else if(arr[mid]<target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << "Element not found" << endl;
}

//Fxn for recursive binary search
int BinarysearchRecursive(int arr[], int left,int right, int target) {
    if(left > right) {
        return -1;
    }
    int mid =left +(right-left)/2;

    if(arr[mid] ==target) {
        return mid;
    }

    else if(arr[mid] <target) {
      BinarysearchRecursive(arr, mid + 1, right, target);
    }
    else {
        BinarysearchRecursive(arr, left, mid - 1, target);
    }
    return -1;
}


//Fxn to implement Bubble sort
void BubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j]= arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
//Fxn to implement Selection sort
void SelectionSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int minI = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minI]) {
                minI = j;
            }
        }
        int temp = arr[minI];
        arr[minI] = arr[i];
        arr[i] = temp;
    }
}


//Fxn to implement Insertion sort
void InsertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
          while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

}

//fxn for implementing merge sort
void Merge(int arr[], int left, int mid, int right) {
    int n1= mid - left + 1;
    int n2 =right - mid;
    int* Le=new int[n1];
    int* Ri= new int[n2];

    for (int i = 0; i < n1; ++i) Le[i] = arr[left + i];
    for (int j = 0; j < n2; ++j) Ri[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (Le[i] <= Ri[j]) arr[k++] = Le[i++];
        else arr[k++] = Ri[j++];
    }
    while (i < n1) arr[k++] = Le[i++];
    while (j < n2) arr[k++] = Ri[j++];

    delete[] Le;
    delete[] Ri;
}
void MergeSort(int arr[], int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);
    Merge(arr, left, mid, right);
}



//Fxn to implement Quick sort
int Partition(int arr[],int low,int high) {
    int pivot=arr[high];  
    int i = low - 1;

    for (int j =low; j<high; j++) {
        if (arr[j]< pivot) {
            i++;
            int temp =arr[i];
            arr[i]=arr[j];
            arr[j] = temp;
        }
    }
    int temp= arr[i+1];
    arr[i+1]= arr[high];
    arr[high] =temp;
    return i + 1;
}

void QuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = Partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

//Fxn for implementing Heap sort using Max Heap
void Heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if(largest!=1){
        int temp = arr[i];
        arr[i]= arr[largest];
        arr[largest]=temp;
        Heapify(arr, n,largest);
    }
}
void HeapSort(int arr[], int n) {
      for(int i= n/2-1 ; i >= 0; i--) {
        Heapify(arr, n, i);
    }
    for(int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0]= arr[i];
        arr[i] = temp;
        Heapify(arr,i,0);
    }
}

//Fnx for counting sort
void CountingSort(int arr[], int n) {
    int max=arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    int* count = new int[max + 1]();
    for(int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    int index = 0;
    for(int i = 0; i <= max; i++) {
        while(count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
    delete[] count;
}

//fxn for ary display
void Display(int arr[], int n) {
    cout << "Array elements: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size;
    cout<<"Enter size for array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter elements for array: ";
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    while(true){
        //searching
        cout<<"1.Linear Search."<<endl;
        cout<<"2.Binary Search."<<endl;
        cout<<"3.Binary Seach(Recursive)."<<endl;
        //sorting Part
        cout<<"4.Bubble Sort."<<endl;
        cout<<"5.Selection Sort."<<endl;
        cout<<"6.Insertion Sort."<<endl;
        cout<<"7.Merge Sort."<<endl;
        cout<<"8.Quick Sort."<<endl;
        cout<<"9.Heap Sort."<<endl;
        cout<<"10.Counting Sort."<<endl;
        cout<<"11.Display Array."<<endl;
        cout<<"12.Exit."<<endl;
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;


        switch(choice){
            case 1:{
             
            case 2:{
                int key; cout<<"Enter element to search: "; cin>>key;
                Binarysearch(arr, size, key);
                break;
            }
            case 3:{
                int key; cout<<"Enter element to search: "; cin>>key;
                int result = BinarysearchRecursive(arr, 0, size - 1, key);
                if(result != -1) {
                    cout << "Element found at index: " << result << endl;
                } else {
                    cout << "Element not found" << endl;
                }
                break;
            }
            case 4:{
                BubbleSort(arr, size);
                cout << "Array after Bubble Sort: ";
                for(int i = 0;i< size; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                break;
            }
            case 5:{
                SelectionSort(arr, size);
                cout<<"Array after Selection Sort: ";
                for(int i= 0;i< size; i++) {
                    cout<<arr[i] << " ";
                }
                cout << endl;
                break;
            }
            case 6:{
                InsertionSort(arr, size);
                cout<<"Array after Insertion Sort: ";
                for(int i = 0;i < size; i++) {
                    cout<<arr[i] << " ";
                }
                cout << endl;
                break;
            }
            case 7:{
                MergeSort(arr,0,size - 1);
                cout << "Array after Merge Sort: ";
                for(int i =0; i <size; i++) {
                    cout<<arr[i] << " ";
                }
                cout<<endl;
                break;
            }
            case 8:{
                QuickSort(arr, 0, size - 1);
                cout<<"Array after Quick Sort: ";
                for(int i=0; i< size; i++) {
                    cout<<arr[i] << " ";
                }
                cout<<endl;
                break;
            }
            case 9:{
                HeapSort(arr, size);
                cout << "Array after Heap Sort: ";
                for(int i = 0; i < size; i++) {
                    cout<<arr[i] << " ";
                }
                cout<<endl;
                break;
            }
            case 10:{
                CountingSort(arr, size);
                cout << "Array after Counting Sort: ";
                for(int i = 0; i < size; i++) {
                    cout<<arr[i] << " ";
                }
                cout<<endl;
                break;
            }
            case 11:{
                Display(arr, size);
                break;
            }
            case 12:{
                cout<<"Exiting teh program...."<<endl;
                return 0;
            }
            
            default:{
                cout<<"Invalid choice. Please try again."<<endl;
            }
        }
    }
    }


    
    return 0;
}