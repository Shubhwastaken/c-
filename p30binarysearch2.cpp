#include <iostream>
using namespace std;
//problem1
int firstOccurrence(int* arr, int size, int sdx, int edx, int target) {
    while (sdx <= edx) {
        int mid = (sdx + edx) / 2;
        if (arr[mid] == target) {
            edx = mid - 1;
            if (mid == 0 || arr[mid - 1] != target) {
                return mid;
            }
        } else if (arr[mid] > target) {
            edx = mid - 1;
        } else {
            sdx = mid + 1;
        }
    }
    return -1; 
}

int lastOccurrence(int* arr, int size, int sdx, int edx, int target) {
    while (sdx <= edx) {
        int mid = (sdx + edx) / 2;
        if (arr[mid] == target) {
            sdx = mid + 1;
            if (mid == size - 1 || arr[mid + 1] != target) {
                return mid;
            }
        } else if (arr[mid] > target) {
            edx = mid - 1;
        } else {
            sdx = mid + 1;
        }
    }
    return -1; 
}


//problem 2
int rotatedarr(int *arr, int size) {
    int sdx = 0;
    int edx = size - 1;
    int mid = (sdx+edx)/2;
    if(arr[mid] > arr[mid+1])
    {
        return mid+1;
    }
    else if(arr[mid] < arr[mid-1]){
        return mid;
    }
     while (sdx <= edx) {
        if (arr[mid] > arr[sdx]) {
            sdx = mid + 1;
        } else {
            edx = mid - 1;
        }
    }

    return sdx; 
}
//3rd problem
int rotatedtargetarr(int *arr,int siz,int target){
    int sdx = 0;
    int edx = siz - 1;
    while(sdx<=edx){
        int mid = (sdx+edx)/2;
        if(arr[mid]==target){
            return mid;
        }
        if(arr[mid] >= arr[sdx]){
            if(target > arr[sdx] && target <= arr[mid]){
                edx = mid - 1;
            }
            else{
                sdx = mid + 1;
            }
        }
        else{
            if(target >= arr[mid] && target <= arr[edx]){
                sdx = mid + 1;
            }
            else{
                edx = mid - 1;
            }
        }
    }
    return  -1;
}



int main() {
    // int size = 10;
    // int target;
    // int arr[] = {2, 5, 5, 5, 5, 6, 9, 9, 9, 9};
    // cout << "Enter the target element: ";
    // cin >> target;

    // int firstIndex = firstOccurrence(arr, size, 0, size - 1, target);
    // int lastIndex = lastOccurrence(arr, size, 0, size - 1, target);

    // cout<<firstIndex<<" "<<lastIndex<<endl;

    //ans2
    // int n = 5;
    // int brr[]={3,4,5,1,2};
    
    // int min_index = rotatedarr(brr, n);
    // printf("Minimum element is: %d\n", brr[min_index]);


    //3rd answer
    int siz = 5;
    int crr[]={3,4,5,1,2};
    int target;
    cout<<"Enter target element:";
    cin>>target;
    cout<<rotatedtargetarr(crr,siz,target);
    return 0;
}