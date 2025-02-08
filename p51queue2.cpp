#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void printQueue(const queue<int>& q) {
    queue<int> temp = q; // Create a copy of the queue to avoid modifying the original

    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
}

void printWindowElements(const vector<int>& arr, int k) {
    int size = arr.size();
    if (k > size) {
        cout << "Invalid window size" << endl;
        return;
    }
    queue<int> q;
    for (int i = 0; i < k - 1; i++) {
        q.push(arr[i]);
    }
    for (int i = k - 1; i < size; i++) {
        q.push(arr[i]); 
        printQueue(q);
        q.pop();
    }
}

int getnegative(queue<int>q){
    while(!q.empty()){
        if(q.front()< 0){
            return q.front();
        }
        q.pop();
    }
    return 0;
}


vector<int> printfirstnegativeinwindow(vector<int>arr,int k){
    vector<int>ans;
    int size = arr.size();
    
    queue<int> q;
    for (int i = 0; i < k - 1; i++) {
        q.push(arr[i]);
    }
    for (int i = k - 1; i < size; i++) {
        q.push(arr[i]); 
        ans.push_back(getnegative(q));
        q.pop();
    }
    return ans;
}

int main() {
    // vector<int> arr = {2, 3, 1, 5, 6, 7, 8};
    // int k = 3; 

    // printWindowElements(arr, k);
    vector<int> arr = {2,-3,-4,-2,7,8,9,-10};
    int k = 3;
    vector<int>ans = printfirstnegativeinwindow(arr,k);
    for (int num : ans) {
        cout << num << " "; 
    }
    cout << endl; 
    

    return 0;
}