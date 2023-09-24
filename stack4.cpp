#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> myStack;

    while (true) {
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cin >> value;
                myStack.push(value);
                break;
            }
            case 2: {
                if (!myStack.empty()) {
                    myStack.pop();
                } else {
                    cout << "Stack is empty. Cannot perform pop operation." << endl;
                }
                break;
            }
            case 3: {
                if (!myStack.empty()) {
                    cout << "Elements in the stack:";
                    while (!myStack.empty()) {
                        cout << " " << myStack.top();
                        myStack.pop();
                    }
                    cout << endl;
                } else {
                    cout << "Stack is empty." << endl;
                }
                break;
            }
            case 4:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
