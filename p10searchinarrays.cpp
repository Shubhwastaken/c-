#include<iostream>
using namespace std;
int linearsearch(int array[],int n,int key){
    for(int i = 0;i < n;i++){
        if(array[i]==key){
            return i;
        }
    }
    return -1;
}
int binarysearch(int array[],int n,int key){
    int s =  0;
    int e = n;
    
    while(s<=e){
        int mid = (s +e)/2;
        if(array[mid]==key){
            return mid;
        }
        else if(array[mid]>key)
        {
           e = mid -1;
        }
        else{
            s = mid +1;
        }
        
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter the size of the array :";
    cin>>n;
    int array[n];
    for(int i = 0;i < n;i++){
        cin>>array[i];
    }
    int key;
    cout<<"Enter the element you want to find :";
    cin>>key;
    // cout<<linearsearch(array,n,key);
    cout<<binarysearch(array,n,key);
    return 0;
}