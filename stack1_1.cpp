#include <iostream>
#include <stack>
using namespace std;

void display(stack<int> st,int size){
    stack<int> temp;
    int count=0;
    for(int i=1;i<=size;i++){
        temp.push(st.top());
        st.pop();
        count++;
        if(st.empty()){
            break;
        }
    }
    for(int i=1;i<=count;i++){
        cout << temp.top() << " ";
        temp.pop();
    }
}

int main(){
    int size;
    stack<int> st;
    cin >> size;

    for(int i=1;i<=size;i++){
       int a;
       cin >> a;
       st.push(a); 
    }

    if(size>15){
        cout<<"Stack Overflow" << endl;
    }
    else{
        //st.pop();
        if(st.empty()){
            cout << "Stack is empty." << endl;
        }
        else{
            display(st,size);
            cout << endl;
            cout << "Top element: " << st.top() << endl;
            st.pop();
            display(st,size-1);
        }
    }
    
}