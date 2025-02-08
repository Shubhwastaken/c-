#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>
using namespace std;
void bucketsort(float *arr,int n){
    vector<vector<float> > bucket(n,vector<float>());
    for(int i = 0;i<n;i++){
        int index = floor(arr[i]*n);
        bucket[index].push_back(arr[i]);
    }
    for(int i = 0;i<n;i++){
        if(!bucket[i].empty()){
            sort(bucket[i].begin(),bucket[i].end());
        }
    }
    int k = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < bucket[i].size();j++){
            arr[k++]=bucket[i][j];
        }
    }
}

int main(){
    int n = 9;
    float arr[]={0.13,0.34,0.12,0.22,0.45,0.78,0.630,0.85,0.59};
    bucketsort(arr,n);
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}