#include <iostream>
#include <stack>
using namespace std;

void sortStack(stack<int>& s) {
    if (s.empty()) {
        return;
    }
    stack<int> tempStack;
    while (!s.empty()) {
        int temp = s.top();
        s.pop();
        while (!tempStack.empty() && tempStack.top() > temp) {
            s.push(tempStack.top());
            tempStack.pop();
        }
        tempStack.push(temp);
    }
    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
}

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << "Stack is empty" << endl;
        return 0;
    }
    if (n > 10) {
        cout << "Stack is full" << endl;
        return 0;
    }
    stack<int> inputStack;
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        inputStack.push(element);
    }
    cout << "Original stack: ";
    stack<int> originalStack = inputStack;
    
    
    stack<int> temps;
    while (!originalStack.empty()) {
        temps.push(originalStack.top());
        originalStack.pop();
    }
    while (!temps.empty()) {
        cout << temps.top() << " ";
        temps.pop();
    }
    cout << endl;

    sortStack(inputStack);

    cout << "Sorted stack: ";
    while (!inputStack.empty()) {
        cout << inputStack.top() << " ";
        inputStack.pop();
    }
    cout << endl;
}
