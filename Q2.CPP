#include <iostream>
using namespace std;

class CircularQueue {
    int* arr;
    int front;
    int rear;
    int max_size;

public:
    CircularQueue(int size) {
        max_size = size;
        arr = new int[max_size];
        front = -1;
        rear = -1;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % max_size == front;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full" << value << "." << endl;
            return;
        }
        if (isEmpty()) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % max_size;
        }
        arr[rear] = value;
        cout << value << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << arr[front] << " removed from the queue." << endl;
        if (front == rear) {
           
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % max_size;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            cout  << arr[front] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % max_size;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q(5);  

   
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
