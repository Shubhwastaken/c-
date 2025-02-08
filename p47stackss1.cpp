#include<iostream>
#include<stack>
#include<vector>
using namespace std;
//balanced brackets
bool isvalid(string str){
    stack<char> st;
    for(int i = 0;i < str.size();i++){
        char ch = str[i];
        if(ch == '(' or ch == '{' or ch == '[' ){
            st.push(ch);
        }
        else{
            if(ch == ')' and !st.empty() and st.top() == '('){
                st.pop();
            }
            else if(ch == '}' and !st.empty() and st.top() == '{'){
                st.pop();
            }
            else if(ch == ']' and !st.empty() and st.top() == '['){
                st.pop();
            }
            else{
                return false;
            }
        }
    }
    return st.empty();
}

vector<int> nge(vector<int> &arr){//next greaterr element
    int n = arr.size();
    vector<int> output(n,-1);
    stack<int> st;
    for(int i = n-1;i >= 0;i--){
        int current = arr[i];
        while(!st.empty() and st.top() <= current){
            st.pop();
        }
        if (!st.empty()) {
            output[i] = st.top();
        }
        st.push(current);
    }
    return output;
}

vector<int> nse(vector<int> &arr){//next smaller element
    int n = arr.size();
    vector<int> output(n,-1);
    stack<int> st;
    st.push(-1);
    for(int i = n-1;i >= 0;i--){
        int current = arr[i];
        while(st.top() >= current){
            st.pop();
        }
        if (!st.empty()) {
            output[i] = st.top();
        }
        st.push(current);
    }
    return output;
}


vector<int> stockspan(vector<int> &arr) {
    int n = arr.size();
    vector<int> output(n, 1); 
    stack<int> st;
    st.push(0);

    for (int i = 1; i < n; i++) {
        while (!st.empty() && arr[i] >= arr[st.top()]) {
            st.pop();
        }

        if (st.empty()) {
            output[i] = i + 1;
        } else {
            output[i] = i - st.top();
        }

        st.push(i);
    }
    return output;
}



int main(){
    // string str = "((({{([])})))";
    // cout<<isvalid(str)<<endl;

    //question2
    int n;
    cin>>n;
    vector<int> v;
    while(n--){
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector<int> res = nge(v);
    for(int i = 0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    // vector<int> res = nse(v);
    // for(int i = 0;i<res.size();i++){
    //     cout<<res[i]<<" ";
    // }

    //question3
    // int n;
    // cin>>n;
    // vector<int> v;
    // while(n--){
    //     int x;
    //     cin>>x;
    //     v.push_back(x);
    // }
    // vector<int> res = stockspan(v);
    // for(int i = 0;i<res.size();i++){
    //     cout<<res[i]<<" ";
    // }
    return 0;
}