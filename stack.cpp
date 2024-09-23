#include <iostream>
#include <string>
#define STKSIZE 10

using namespace std;

template <class T>
class Stack {
    int top;
    T stk[STKSIZE];

public : 
    Stack() {top = -1;}

    bool isFull() {
        return(top == STKSIZE-1);
    }

    bool isEmpty() {
        return(top == -1);
    }

    void push(T num){
        if(isFull()){
            cout << "error : Overflow" << endl;
            return ;
        }

        else{
            stk[++top] = num;
        }
    }

    T pop(){
        if(isEmpty()){
            cout << "error : Underflow" << endl;
            return 0;
        }
        else{
            return (stk[top--]);
        }
    }

    T peek(){
        return(stk[top]);
    }

};

int main() {
    Stack<int> s;
    int choice, num;

    while (true) {
        cout << "-----------------------------------------------" << endl;
        cout << "Stack Operations" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Check if Full" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
    

        switch (choice) {
            case 1:
                cout<< "Enter a number to push: ";
                cin >> num;
                s.push(num);
                break;

            case 2:
                if (s.isEmpty()) {
                    cout << "Stack is already empty" << endl;
                }
                else {
                    cout << "Popped number is: " << s.pop() << endl;
                }
                break;

            case 3:
                cout << "Top Element: " << s.peek() << endl;
                break;

            case 4:
                if (s.isFull()) {
                    cout << "Stack is full" << endl;
                }
                else{
                    cout << "Stack is not full" << endl;
                }
                break;

            case 5:
                if (s.isEmpty()) {
                    cout << "Stack is empty" << endl;
                }
                else{
                    cout << "Stack is not empty" << endl;
                }
                break;

            case 6:
                return 0;

            default:
                cout << "Invalid choice" << endl;
        }
    }    
    return 0;
}
