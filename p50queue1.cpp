#include<iostream>
#include<queue>
#include<stack>
using namespace std;
queue<int> reversequeue(queue<int>&q){
    stack<int>s;
    
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    return q;
}

queue<int>reversefirstkelements(queue<int> &q,int k){
    stack<int>st;
    while(k--){
        st.push(q.front());
        q.pop();
    }
    int n = q.size();
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    while(n--){
        int i = q.front();
        q.pop();
        q.push(i);
    }
    return q;
}
int main(){
    //printing elements of queue and then returning the same queue
    queue<int> q ;
    q.push(2);
    q.push(56);
    q.push(32);
    q.push(23);
    q.push(48);
    q.push(69);
    int k = 3;

    
    // queue<int>ans = reversequeue(q);
    // int n = ans.size();
    // while ((n--))
    // {
    //     cout<<ans.front()<<" ";
    //     ans.push(ans.front());
    //     ans.pop();
    // }
    queue<int>ans = reversefirstkelements(q,k);
    int n = ans.size();
    while ((n--))
    {
        cout<<ans.front()<<" ";
        ans.push(ans.front());
        ans.pop();
    }
    return 0;
}