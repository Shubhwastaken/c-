#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

void printsubsets(vector<int>&arr,vector<int> &ans,int i){
    if(i == arr.size()){
        for(int val : ans){
            cout<<val<<" ";
        }
        cout<<endl;
        return;
    }
    ans.push_back(arr[i]);
    printsubsets(arr,ans,i+1);

    ans.pop_back();
    printsubsets(arr,ans,i+1);
}

void permutationString(string& str, vector<string>& ans, int idx) {
    if(idx == str.length()) {
        ans.push_back(str);
        cout << str << endl;
        return;
    }
    
    for(int i = idx; i < str.length(); i++) {
        swap(str[idx], str[i]);
        permutationString(str, ans, idx+1);
        swap(str[idx], str[i]);
    }
}


void pathfinder(vector<vector<int>> &matrix,int row,int col,vector<string>&ans,string  path){
    int n = matrix.size();
    if(row < 0 || col < 0 || row >= n || col >= n || matrix[row][col] == 0 || matrix[row][col] == -1){
        return ;
    }
    if(row == n-1 && col == n-1){
        ans.push_back(path);
        return ;
    }
    matrix[row][col] = -1;
    pathfinder(matrix,row+1,col,ans,path+"D");
    pathfinder(matrix,row-1,col,ans,path+"U");
    pathfinder(matrix,row,col+1,ans,path+"R");
    pathfinder(matrix,row,col-1,ans,path+"L");
    matrix[row][col] = 1;
}

vector<string>findpath(vector<vector<int>> &matrix){
    int m = matrix.size();
    
    vector<string>ans;
    string path = "";
    pathfinder(matrix,0,0,ans,path);
    return ans;
}
int main() {
    // string str = "abc";
    // vector<string> ans;
    // permutationString(str, ans, 0);
    vector<vector<int>> matrix = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
    vector<string> ans = findpath(matrix);
    for(string path : ans){
        cout<<path<<endl;
    }
    return 0;
}
