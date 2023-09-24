#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack is empty." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void deleteEven() {
        if (top == NULL) {
            cout << "Stack is empty." << endl;
            return;
        }
        Node* current = top;
        Node* prev = NULL;

        while (current != NULL) {
            if (current->data % 2 == 0) {
                if (prev == NULL) {
                    // If the even element is at the top
                    top = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                current = prev;
            }
            prev = current;
            current = current->next;
        }
    }

    void printStack() {
        if (top == NULL) {
            cout << "Stack is empty." << endl;
            return;
        }
        Node* current = top;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    int n, element;
    cin >> n;

    Stack stack;

    for (int i = 0; i < n; i++) {
        cin >> element;
        stack.push(element);
    }

    stack.printStack();

    stack.deleteEven();

    stack.printStack();

    return 0;
}
