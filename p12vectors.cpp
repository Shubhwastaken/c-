#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<char> vec = {'a','b','c'};
    // cout<<vec[0]<<endl;
    // for(char val : vec){
    //     cout<<val<<endl;
    // }
    // cout<<"size : "<<vec.size() << endl;

    // vector<int> v(3,0);
    // cout<<v[2]<<endl;

    vector<int> ve;
    ve.push_back(22);
    ve.push_back(2);
    ve.push_back(13);
    ve.pop_back();
    cout<<(ve.front())<<endl;
    for(int value : ve){
        cout<<value<<endl;
    }
    
    return 0;
}