#include<iostream>
#include<vector>
using namespace std;

vector<int> pairsum(vector<int> v, int key) {
    int size = v.size();
    int i = 0;
    int j = size-1;
    vector<int> ans;
    
    while(i < j) {  
        int pairsum = v[i] + v[j];
        if(pairsum < key) {
            i++;
        }
        else if(pairsum > key) {
            j--;
        }
        else {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
    return ans;
}

int main(){
    // int mx = -99999;
    // int n;
    
    // cout << "Enter the size of the array: ";
    // cin >> n;
    // int array[n];

    // for (int i = 0; i < n; i++) {
    //     cin >> array[i];
    // }
    // for(int i = 0;i<n;i++){
    //     mx = max(mx,array[i]);
    //     cout<<mx<<endl;
        
    // }

    //max sub array sum
    // int n =5;
    // int array[n] = { 1,2,3,4,5};

    // int sum = 0;
    // for (int start=0;start<n;start++){
    //     int currsum = 0;
    //     for(int end = start;end < n;end++){
    //         currsum += array[end];
    //         sum = max(sum,currsum);
    //     }
    // } 

    // cout<<"Max sum of subarray is "<<sum<<endl;

    //pair sum
    vector<int> vec = {2,7,11,15};
    int key = 13;
    vector<int>sol = pairsum(vec,key);
    cout<<sol[0]<<","<<sol[1]<<endl;    
    return 0;
}