#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int front;
    int rear;
    int max_size;

public:
    Queue(int size) {
        max_size = size;
        arr = new int[max_size];
        front = 0;
        rear = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return rear < front;
    }

    bool isFull() {
        return rear == max_size - 1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout <<  value << endl;
            return;
        }
        rear++;
        arr[rear] = value;
        cout << value  << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout<<-1 << endl;
            return;
        }
        cout << arr[front]  << endl;
        front++;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty! No front element." << endl;
        } else {
            cout  << arr[front] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5); 

    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();    

    q.peek();      

    q.dequeue();    

    q.display();

    cout << (q.isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
    cout << (q.isFull() ? "Queue is full.\n" : "Queue is not full.\n");

    return 0;
}
