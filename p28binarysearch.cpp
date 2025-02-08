#include<iostream>
using namespace std;
int binarysearch(int *arr,int size,int target){
    int sdx = 0;
    int edx = size-1;
   
    while(sdx<=edx){
        int mid = (sdx+edx)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[mid]<target){
            sdx = mid + 1;
        }
        else{
            edx = mid - 1;
        }

    }
    return -1;
}

//recursive implementation
int recursivebinary(int *arr,int size,int target,int sdx,int edx){
    if(sdx>edx){
        return -1;
    }
    int mid = (sdx+edx)/2;
    if(arr[mid]==target){
        return mid;
    }
    if(arr[mid<target]){
        return recursivebinary(arr,size,target,mid+1,edx);
    }
    else{
        return recursivebinary(arr,size,target,sdx,mid-1);
    }
}


int main(){
    int size = 8;
    int target;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout<<"Enter element of the array:";
        cin>>arr[i];
    }
    cout<<"Enter the target element: ";
    cin>>target;
    // cout<<binarysearch(arr,size,target);
    cout<<recursivebinary(arr,size,target,0,size-1);
    
    return 0;
}