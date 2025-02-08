#include<iostream>
using namespace std;

void swapzeroestoend(int *arr,int n){
    for(int i = n-1;i>=0;i--){
        int j = 0;
        bool flag = false;
        while(j!=i){
            if(arr[j]==0 && arr[j+1]!=0){
                swap(arr[j],arr[j+1]);
                flag = true;
            }
            j++;
        }
        if(!flag){
            break;
        }
    }
    return;
}





int main(){
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }
    swapzeroestoend(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    return 0;
}