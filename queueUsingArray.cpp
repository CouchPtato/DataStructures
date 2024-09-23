#include <iostream>
#define MAX 10

using namespace std;

template <class T>
class queue{

    T que[MAX];

    int front, rear;
    public: queue(){
        front = rear = -1;
    }

    bool isfull(){
        if(rear == MAX - 1)
            return true;
        else
            return false;
    }

    bool isempty(){
        if(front == -1 || front > rear)
            return true;
        else
            return false;
    }

    void enqueue(T num){
        if(isfull())
        {
            cout << "Queue is full\n";
            return;
        }

        if(front == -1)
            front = 0;
        else
           que[++rear] = num;
        
    }

    T dequeue()
    {
        T num;
        if (isempty())
        {
            cout << "Queue is empty\n";
            return 0;
        }
        else 
        {
            num = que[front++];

            if(front == rear)
                front = rear = -1;
            return num;
        }
    }

    T peek()
    {
        return que[front];
    }
};

int main() {
    queue<int> q;

    int choice, num;

    while (true) {
        cout << "Queue Operations:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Check if empty\n";
        cout << "5. Check if full\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a number to enqueue: ";
                cin >> num;
                q.enqueue(num);
                break;

            case 2:
                num = q.dequeue();
                if (num != 0) {
                    cout << "Dequeued: " << num << endl;
                }
                break;

            case 3:
                num = q.peek();
                if (num != 0) {
                    cout << "Front of queue: " << num << endl;
                }
                break;

            case 4:
                if (q.isempty()) {
                    cout << "Queue is empty.\n";
                } else {
                    cout << "Queue is not empty.\n";
                }
                break;

            case 5:
                if (q.isfull()) {
                    cout << "Queue is full.\n";
                } else {
                    cout << "Queue is not full.\n";
                }
                break;

            case 6:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}