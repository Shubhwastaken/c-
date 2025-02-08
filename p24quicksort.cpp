#include<iostream>
using namespace std;

int partition(int *arr,int sdx,int edx){
    int pivot = arr[edx];
    int i = sdx-1;
    
    for(int j = sdx;j<edx;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[edx]);
    return i+1;
}


void quicksort(int *arr,int sdx,int edx){
    if(sdx>=edx){
        return;
    }
    int pi = partition(arr,sdx,edx);
    quicksort(arr,sdx,pi-1);
    quicksort(arr,pi+1,edx);
        
    
}


int main(){
    int n = 6;
    int arr[]={18,12,30,16,35,20};
    quicksort(arr,0,n-1);
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    



    return 0;
}