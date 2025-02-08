#include<iostream>
using namespace std;
int firstoccurence(int *arr, int size, int sdx, int edx, int target){
    
    while(sdx<=edx){
        int mid = (sdx + edx) / 2;
        if (arr[mid] == target) { 
            edx = mid - 1; 
            if(arr[mid-1]!= target){
                return mid;
            }
        }
        else if(arr[mid] > target){
            edx = mid - 1;
        }
        else{
            sdx = mid + 1;
        }
    }
    
}
//2nd problem
int sqrt(int x){
    int sdx = 1;
    int edx = x;
    int ans = -1;
    while(sdx<=edx){
        int mid = sdx + (edx-sdx)/2;
        if(mid*mid <=x){
            ans = mid;
            sdx =  mid + 1;
        }
        else{
            edx = mid - 1;
        }
    }
    return ans;
}
int main(){
    int size = 10;
    int target;
    int arr[]={2,5,5,5,5,6,9,9,9,9};
    cout<<"Enter the target element: ";
    cin>>target;
    cout<<firstoccurence(arr,size,0,size-1,target);


//2nd problem
    cout<<sqrt(40);
    return 0;
}