#include<iostream>
using namespace std;
int main(){
    int n,array[n];
    cout<<"Enter the number of elements :";
    cin>>n;
    for (int  i = 1; i < n; i++)
    {
        cout<<"Enter"<<i + 1<<"element :"<<endl;
        cin>>array[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout<<array[i];
    }
    
    
    
    return 0;
}