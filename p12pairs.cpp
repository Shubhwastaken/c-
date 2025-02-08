#include<iostream>
#include<vector>
using namespace std;

int main(){
    pair<int,int>p = {2,5};
    cout<<p.first<<endl;
    cout<<p.second<<endl;
    cout<<endl;
    cout<<endl;
    pair<int,pair<char,int>>pair_in_pair = {5,{'a',1}};
    cout<<pair_in_pair.first<<endl;
    cout<<pair_in_pair.second.first<<endl;
    cout<<pair_in_pair.second.second<<endl;
    vector<pair<int,int>> vec = {{2,3},{4,5}};
    vec.push_back({6,7});
    vec.emplace_back(8,9);
    for(auto p : vec){
        cout<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}