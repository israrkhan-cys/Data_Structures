#include <iostream>
using namespace std;

class Order{
    string Item_name;
    int  price;
    int Quantity;
    string costumer_name;
    int priority;

public:
Order(){}

   Order(string item_name, int price, int quantity, string customer_name, int priority) {
        Item_name = item_name;
        this->price = price;
        Quantity = quantity;
        costumer_name = customer_name;
        this->priority = priority;
    } 
void DisplayOrder() {
        cout << "Item Name: " << Item_name << ", Price: " << price 
             << ", Quantity: " << Quantity << ", Customer Name: " 
             << costumer_name << ", Priority: " << priority << endl;
    }

    int getPriority() const {
        return priority;
    }
};


class MaxHeap {
    Order* heap;
    int capacity;
    int size;
public:
    MaxHeap(int cap = 100){
        capacity = cap;
        size = 0;
        heap = new Order[capacity];
    }

void Insert(Order order) {
        if (size == capacity) {
            cout << "Heap is full. Cannot insert new order.\n";
            return;
        }
        heap[size] = order;
        size++;
        HeapifyUp(size - 1);
    }

void HeapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index].getPriority() <= heap[parent].getPriority()) {
            break;
        }
        Order temp = heap[index];
        heap[index] = heap[parent];
        heap[parent] = temp;
        index = parent;
        }
    }

void HeapifyDown(int index) {
        int left = 2*index + 1;
        int right = 2*index + 2;
        int largest = index;

        if (left < size && heap[left].getPriority() > heap[largest].getPriority()) {
            largest = left;
        }
        if (right < size && heap[right].getPriority() > heap[largest].getPriority()) {
            largest = right;
        }
        if (largest != index) {
            Order temp = heap[index];
            heap[index] = heap[largest];
            heap[largest] = temp;
            HeapifyDown(largest);
        }
    }
    void Display() {
        if (size == 0) {
            cout << "Heap is empty.\n";
            return;
        }
        for (int i = 0; i < size; i++) {
           heap[i].DisplayOrder();
        }
    }
    void ProcessOrder() {
        if (size == 0) {
            cout << "No orders to process.\n";
            return;
        }
        cout << "Processing order: ";
        heap[0].DisplayOrder();
        heap[0] = heap[size - 1];
        size--;
        HeapifyDown(0);
    }
};


 
int main() {
    MaxHeap m1;

   

     string item_name, customer_name;
    int price, quantity, priority;

    cout<<"======Restaurant Order Management System Using Max Heap=======\n";
    while (true) {
        cout << "1. Add Order\n";
        cout << "2. Process Order\n";
        cout << "3. Display Orders\n";  
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch(choice) {
            case 1:
               
                cout << "Enter item name: ";
                cin >> item_name;
                cout << "Enter price: ";
                cin >> price;
                cout << "Enter quantity: ";
                cin >> quantity;
                cout << "Enter customer name: ";
                cin >> customer_name;
                cout << "Enter priority: ";
                cin >> priority;
                m1.Insert(Order(item_name, price, quantity, customer_name, priority));
                cout << "Order added successfully.\n";
                break;
            case 2:{
                m1.ProcessOrder();
                break;
            }
            case 3:
                m1.Display();
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    }
    
    
    return 0;
}