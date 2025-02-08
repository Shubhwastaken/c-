#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> onlylikenumbers(vector<int> &arr) {
    stack<int> st;
    for (int i = 0; i < arr.size(); i++) {
        if (st.empty()) {
            st.push(arr[i]);
        } 
        else if (arr[i] > 0) {
            
            if (st.top() >= 0) {
                st.push(arr[i]);
            } 
            
            else {
                st.pop();
            }
        } 
        else {
            
            if (st.top() < 0) {
                st.push(arr[i]);
            } 
            
            else {
                st.pop();
            }
        }
    }
    
    
    vector<int> ans(st.size());
    int i = st.size() - 1;
    while (!st.empty()) {
        ans[i] = st.top();
        st.pop();
        i--;
    }
    
    return ans;
}

int removeconsecutivesame(vector<string> &str){
    stack<string> st;
    for(int i = 0;i < str.size();i++){
        if(st.empty()){
            st.push(str[i]);
        }
        else if(str[i] == st.top()){
            st.pop();
        }
        else{
            st.push(str[i]);
        }
    }
   
     return st.size();
}

bool backgroundtstringcompare(string s, string t) {
    stack<char> st1, st2;

    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '#') {
            if (!st1.empty()) {
                st1.pop();
            }
        } else {
            st1.push(s[i]);
        }
    }

    
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == '#') {
            if (!st2.empty()) {
                st2.pop();
            }
        } else {
            st2.push(t[i]);
        }
    }

    
    if (st1.size() != st2.size()) {
        return false; 
    }

    while (!st1.empty() && !st2.empty()) {
        if (st1.top() != st2.top()) {
            return false; // 
        }
        st1.pop(); 
        st2.pop();
    }

    return true; 
}
    
vector<int> printbrscketnumber(string str){
    stack<int> st;
    vector<int> answer;
    int count = 0;
    for(int i = 0;i < str.size();i++){
        if(str[i] == '('){
            count++;
            st.push(count);
            answer.push_back(count);
        }else if(str[i] == ')'){
           answer.push_back(st.top());
           st.pop(); 
        }
    }
    return answer;
}

stack<int> getminatpop(int arr[],int n){
    stack<int> st;
    for(int i = 0;i < n;i++){
        if(i == 0){
            st.push(arr[i]);
        }else{
            st.push(min(arr[i],st.top()));
        }
    }
    return st;
}
int main() {
    //question1
    // vector<int> v;
    // int n;
    // cout << "Enter size of array: ";
    // cin >> n;
    // for (int i = 0; i < n; i++) { 
    //     int x;
    //     cout << "Enter element: ";
    //     cin >> x;
    //     v.push_back(x);
    // }
    // vector<int> res = onlylikenumbers(v);
    // if (res.empty()) {
    //     cout << "No elements meet the criteria.";
    // } else {
    //     for (int i = 0; i < res.size(); i++) {
    //         cout << res[i] << " ";
    //     }
    // }

    //question2
    // vector<string> c;
    // int n;
    // cout << "Enter size of array: ";
    // cin >> n;
    // for (int i = 0; i < n; i++) { 
    //     string x;
    //     cout << "Enter element: ";
    //     cin >> x;
    //     c.push_back(x);
    // }
    // int res = removeconsecutivesame(c);
    // if (res == 0) {
    //     cout << "No elements meet the criteria." << endl;
    // } else {
    //     cout << "Size after removing consecutive same elements: " << res << endl;
    // }

    //question3
    // string s = "ab#c"; 
    // string t = "ad#c";
    // bool areEqual = backgroundtstringcompare(s, t);
    // if (areEqual) {
    //     cout << "Equal" << endl;
    // } else {
    //     cout << "Not Equal" << endl;
    // }

    //question4
    // string str = "(aa(bdc))p(dee)";
    // vector<int> result = printbrscketnumber(str);
    // cout << "Bracket numbers: ";
    // for (int i = 0; i < result.size(); i++) {
    // cout << result[i] << " ";
    // }
    // cout << endl;
    

    //question 5
    int n;
    cout << "Enter size of the array: ";
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cout << "Enter element: ";
        cin >> arr[i];
    }

    stack<int> res = getminatpop(arr, n);
    cout << "Minimum at each pop: ";
    while(!res.empty()) {
        cout << res.top() << " ";
        res.pop();
    }
    cout << endl;

    return 0;
}
