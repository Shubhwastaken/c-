#include<iostream>
using namespace std;

int peakelement(int *arr,int size){
    int sdx = 0;
    int edx = size - 1;
    int ans = -1;
    while(sdx <= edx){
        int mid = (sdx+edx)/2;
        if(arr[mid] > arr[mid-1]){
            ans = mid;
            sdx = mid + 1;
        }
        else{
            edx = mid - 1;
        }
    }
    return ans; //index
}



int main(){
    int size = 5;
    int arr[]={4,5,1,2,3}; 
   
    cout<<peakelement(arr,size);
   return 0;
}