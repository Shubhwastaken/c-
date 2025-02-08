#include<iostream>
#include<stack>
#include<vector>
#include <climits>

using namespace std;

int getminimum(vector<int> arr){
    stack<int> st1;
    stack<int> st2;
    for(int i = 0;i < arr.size();i++){
        if(st1.empty()){
            st1.push(arr[i]);
            st2.push(arr[i]);
        }else{
            st1.push(arr[i]);
            st2.push(min(arr[i],st2.top()));
        }
        
    }
    cout<<st1.top()<<endl;
    return st2.top();
}

stack<int> getminimumusingonestack(vector<int> arr) {
    stack<int> st;
    for(int i = 0;i < arr.size();i++){
        if(i == 0){
            st.push(arr[i]);
        }else{
            st.push(min(arr[i],st.top()));
        }
    }
    return st;
}

vector<int> maxofmin(int arr[],int n){
    vector<int> ans (n,0);
    for(int i = 0;i<n;i++){
        for(int j = 0;j < n - i;j++){
            int num = INT_MAX;
            for(int k = j;k < i+1+j;k++){
                num = min(num,arr[k]);
            }
            ans[i] = max(ans[i],num);
        }
    }
    return ans;
}
int main(){
    // question1
    vector<int> arr = {1, 6, 43, 1,2, 0,5}; 
    stack<int>res =  getminimumusingonestack(arr);
    while(!res.empty()){
        cout<<res.top()<<" ";
        res.pop();
    }   
    //question2
    // int n;
    // cout<<"Enter the size of the array :";
    // cin>>n;
    // int arr[n] = {10,20,30,50,10,70,30};
    // vector<int> res = maxofmin(arr,n);
    // for(int i = 0;i < res.size();i++){
    //     cout<<res[i]<<" ";
    // }
    return 0;
}