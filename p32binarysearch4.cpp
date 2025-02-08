#include<iostream>
using namespace std;
bool candistchocolates(int *arr, int size, int mid, int nostudents) {
    int studentsreqd = 1;
    int currsum = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > mid) {
            return false;
        }

        if (currsum + arr[i] > mid) {
            studentsreqd++;
            currsum = arr[i];

            if (studentsreqd > nostudents) {
                return false;
            }
        } else {
            currsum += arr[i];
        }
    }

    return true;
}
int distchocolates(int *arr,int size,int nostudents){
    int sdx = 0;
    int edx = 0;
    for(int i = 0;i < size;i++){
        edx += arr[i];
    }
    int ans = -1;
    while(sdx <= edx){
        int mid = (sdx+edx)/2;
        if(candistchocolates(arr,size,mid,nostudents)){
            ans = mid;
            edx = mid - 1;
        }
        else{
            sdx = mid + 1;
        }
    }
    return ans;
}


//q2
bool canplacestudents(int *arr,int nodrivers,int mid,int size){
    int studentsreqd = 1;
    int lastplaced = arr[0];
    for(int i = 0;i < size;i++){
        if(arr[i]-lastplaced >= mid){
            studentsreqd++;
            lastplaced=arr[i];
            if(studentsreqd == nodrivers){
                return true;
            }
        }
    }
    return false;
}
int maxdistance(int *arr,int size,int nodrivers){
    int sdx = arr[0];
    int edx = arr[size-1]-arr[0];
    int ans = -1;
    while(sdx <= edx){
        int mid = (sdx+edx)/2;
        if(canplacestudents(arr,nodrivers,mid,size)){
            ans = mid;
            sdx = mid + 1;
        }
        else{
            edx = mid - 1;
        }
    }
    return ans;
}

int main(){
    //q1
    // int size = 4;
    // int nostudents = 2;
    // int arr[]={12,34,67,90};
    // cout<<distchocolates(arr,size,nostudents);
    //q2
    int size = 5;
    int nodrivers = 3;
    int arr[]={1,2,4,8,9};
    cout<<maxdistance(arr,size,nodrivers);                                                          
    
    return 0;
}