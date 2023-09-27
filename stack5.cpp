#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void findNextGreaterElement(vector<int>& arr) {
    stack<int> s;
    vector<int> result(arr.size(), -1);

    for (int i = 0; i < arr.size(); i++) {
        while (!s.empty() && arr[i] > arr[s.top()]) {
            result[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " " << result[i] << endl;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    findNextGreaterElement(arr);

    return 0;
}
