#include <iostream>
#include <stack>

using namespace std;

stack<char> reverseStack(stack<char> st) {
    stack<char> temp;
    
    while (!st.empty()) {
       char curr = st.top();  
       st.pop();
       temp.push(curr);
    }
    
    return temp;
}

stack<int> copystack(stack<int> st){
    stack<int> temp;
    while (!st.empty()) {
       int curr = st.top();  
       st.pop();
       temp.push(curr);
    }
    stack<int> result;
    while(!temp.empty()){
        int current = temp.top();
        temp.pop();
        result.push(current);
    }
    return result;
}

void insertatbottom(stack<int> &st,int value){
    stack<int> temp;
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        temp.push(curr);
    }
    st.push(value);
    while(!temp.empty()){
        int cur = temp.top();
        temp.pop();
        st.push(cur);
    }

}

void insertatindex(stack<int> &st,int value,int idx){
    stack<int> temp;
    st.size();
    while(st.size() != idx){
        int curr = st.top();
        st.pop();
        temp.push(curr);
    }
    st.push(value);
    while(!temp.empty()){
        int cur = temp.top();
        temp.pop();
        st.push(cur);
    }
}

int main() {
    // stack<char> st;
    // st.push('h');
    // st.push('e');
    // st.push('l');
    // st.push('l');
    // st.push('o');

    
    // stack<char> res = reverseStack(st);

    // while (!st.empty()) {
    //     cout << st.top();  
    //     st.pop();
    // }
    // cout<<endl;
    // while (!res.empty()) {
    //     cout << res.top();  
    //     res.pop();
    // }

    //question 2
    // stack<int> st;
    // st.push(1);
    // st.push(2);
    // st.push(3);
    // stack<int> res = copystack(st);
    // while(!st.empty()){
    //     cout << st.top();  
    //     st.pop();
    // }
    // cout<<endl;
    // while (!res.empty()) {
    //     cout << res.top();  
    //     res.pop();
    // }


    //question3
    // stack<int> st;
    // st.push(1);
    // st.push(2);
    // st.push(3);
    // insertatbottom(st,0);
    // while(!st.empty()){
    //     cout << st.top()<<endl;  
    //     st.pop();
    // }
    

    //question4

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    
    insertatindex(st,100,1); 
    while(!st.empty()){
        cout << st.top()<<endl;  
        st.pop();
    }
    return 0;
}
