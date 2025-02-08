#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of the array :";
    cin>>n;
    int array[n];
    for(int i = 0;i < n;i++){
        cin>>array[i];
    }
    for(int j=0;j<n-1;j++){
        for(int k = j+1;k<n;k++){
            if(array[k]<array[j]){
                int temp = array[k];
                array[k]= array[j];
                array[j]=temp;
            }
        }
    }
    for(int i = 0;i < n;i++){
        cout<<array[i]<<endl;
    }
 return 0;
}