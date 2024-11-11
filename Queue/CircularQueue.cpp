// Queue Using Circular Array
#include <iostream>
using namespace std;

#define MAX_SIZE 5

class CircularQueue {
    int arr[MAX_SIZE];
    int front, rear;
    int size;

public:
    CircularQueue() : front(-1), rear(-1), size(0) {}

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == MAX_SIZE;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << value << ".\n";
            return;
        }

        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = value;
        size++;

        if (front == -1) {
            front = rear;
        }

        cout << "Enqueued: " << value << "\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }

        cout << "Dequeued: " << arr[front] << "\n";
        front = (front + 1) % MAX_SIZE;
        size--;

        if (isEmpty()) {
            front = -1;
            rear = -1;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue elements: ";
        int count = size;
        int i = front;
        while (count--) {
            cout << arr[i] << " ";
            i = (i + 1) % MAX_SIZE;
        }
        cout << "\n";
    }
};

int main() {
    CircularQueue queue;
    int choice, value;

    do {
        cout << "\nQueue Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display Queue\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a value to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.display();
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
