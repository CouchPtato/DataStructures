// Circular linked list
#include <iostream>
using namespace std;

class cnode{
    private: 
        int data;
        cnode* next;
    public:
        cnode(){
            next = NULL;
        }
    friend class CLL;
};

class CLL{
    private:
        cnode* cursor;
    public:
        CLL();
        ~CLL();

    bool empty() const;
    int front() const;
    int back() const;
    void advance();
    void add(const int);
    void remove();
    int search(int);
};

CLL :: CLL(){
    cursor = NULL;
}

CLL :: ~CLL(){
    while (!empty());
    remove();
}

bool CLL :: empty() const{
    return cursor == NULL;
}

int CLL :: front() const{
    return cursor -> next -> data;
}

int CLL :: back() const{
    return cursor -> data;
}

void CLL :: advance() {
    cursor = cursor -> next;
}

void CLL :: add(const int x) {
    cnode* newCnode = new cnode();
    newCnode -> data = x;
    if (cursor == NULL){
        newCnode -> next = newCnode;
        cursor = newCnode;
    }else{
        newCnode -> next = cursor -> next;
        cursor -> next = newCnode;
    }
}

void CLL :: remove(){
    cnode* ptr = cursor -> next;
    cout << "Deleted Node: " << ptr -> data;
    if (cursor == NULL){
        cursor = NULL;
    }else{
        cursor -> next = ptr -> next;
        delete ptr;
    }
}

int CLL :: search(int loc){
    cnode* ptr = cursor;
    for (int i; i <= loc; i++){
        if (ptr == NULL){
            cout << "Location out of range." << endl;
        }
        ptr = ptr -> next;
    }
    cout << "Element at location '" << loc << "': "<< ptr -> data << endl;
    
    return 1;
}


int main(){
    CLL cll;
    int choice;
    int num;
    int loc;
    while (true){
        cout << "1. Add Node\n2. Remove Node\n3. Check if empty\n";
        cout << "4. Check front\n5. Check back\n6. Advance\n7. Search\n";
        cout << "8. Exit.\n";
        cout << "Enter your choice: "; cin >> choice;
    
        switch (choice) {
            case 1:
                cout << "Enter the Node to be added: ";
                cin >> num;
                cll.add(num);
                break;
            case 2:
                cll.remove();
                break;
            case 3:
                if (cll.empty()){
                    cout << "The list is empty.";
                }
                break;
            case 4:
                cout << "Front of the list: " << cll.front() << "\n";
                break;
            case 5: 
                cout << "Back of the list: " << cll.back() << endl;
                break;
            case 6:
                cll.advance();
                break;
            case 7:
                cout << "Enter the Node to be searched:";
                cin >> loc;
                cll.search(loc);
                break;
            case 8:
                return 0;
        }
    }
    return 0;
}
