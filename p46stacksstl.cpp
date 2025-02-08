#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(5);
    st.push(4);
    st.pop();
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;
    cout<<st.empty()<<endl;
    
    
    return 0;
}