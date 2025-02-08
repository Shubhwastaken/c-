#include<iostream>
#include<vector>
using namespace std;
int sum(int n){
    if (n==0)
    {
        return 0;
    }
    
    int prevsum = sum(n-1);
    return n + prevsum;
}
int power(int n,int p){
    if(p==0){
        return 1;
    }
    int prevpow = power(n,p-1);
    return n*prevpow;
}
int fib(int n){
    if(n == 0 || n == 1){
        return n;
    }
    return fib(n-1)+fib(n-2);
}
int factorial(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    return n * factorial(n-1);
}

int sumofdigits(int n){
    if(n<=9 && n>=0){
        return n;
    }
    return sumofdigits(n/10)+(n%10);
}
void rarr(int *arr,int idx,int n){
    if(idx==n){
        return ;
    }
    cout<<arr[idx]<<endl;
    rarr(arr,idx+1,n);
}
int maxelement(int *arr,int idx,int n){
    if(idx == n-1){
        return arr[idx];
    }
    return max(arr[idx],maxelement(arr,idx+1,n));
}
int sumarray(int *arr,int idx,int n){
    if(idx == n-1){
         return arr[idx];
    }
    return arr[idx]+sumarray(arr,idx+1,n);
}
string removeletter(string &s,int idx,int n){
    if(s[idx]==n){
        return "";
    }
    string curr = "";
    curr += s[idx];
    return ((s[idx]== 'a')? "" : curr) + removeletter(s,idx+1,n);
}
void sequence(int n){
    if(n<1){
        return;
    }
    sequence(n-1);
    cout<<n<<endl;
}
void multiple(int num,int k){
    if(k==0){
        return;
    }
    multiple(num,k-1);
    cout<<num*k<<endl;
}
int alternate(int n){
    if (n==0)
    {
        return 0;
    }
    return alternate(n-1) + ((n%2==0)?(-n):(n));
    
}
int gcd(int a, int b) {
    if (a == 0 && b == 0) {
        return 0; // Or handle this case according to your specific requirements
    }

    if (b > a) {
        return gcd(b, a);
    }

    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}
bool findarrayelement(int *arr,int size,int i,int x){
    if(i==size){
        return false;
    }
    return (arr[i]==x) || findarrayelement(arr,size,i+1,x);
}
int waystoreachbottomrightofmatrix(int i,int j,int m,int n){
    if(i == m-1 || j == n-1){
        return 1;
    }
    if(i>=m or j >=n){
        return  0;
    }
    return waystoreachbottomrightofmatrix(i+1,j,m,n)+ waystoreachbottomrightofmatrix(i,j+1,m,n);
}
void stringsequence(string &str,int i,string result,vector<string> &li){
    if(i==str.length()){
        li.push_back(result);
        return;
    }
    stringsequence(str,i+1,result + str[i],li);
    stringsequence(str,i+1,result,li);
}
int main(){
    // int n=6;
    // string s = "abzxac";
    int arr[]= {1,2,3,4,5,6};
    // cout<<"Enter value of n:";
    // cin>>n;
    // cout<<sum(n)<<endl;
    // cout<<power(2,2)<<endl;
    // cout<<fib(n)<<endl;
    // cout<<factorial(n)<<endl;
    // cout<<sumofdigits(n)<<endl;
    // rarr(arr,0,n);
    // cout<<maxelement(arr,0,n)<<endl;
    // cout<<sumarray(arr,0,n)<<endl;
    // cout<<removeletter(s,0,n)<<endl;
    // sequence(1);
    // multiple(3,8);
    // cout<<alternate(10);
    // cout<<gcd(40,48);
    


    //finding element in array using recursion
    // bool result = findarrayelement(arr,6,0,8);
    // if (result)
    // {
    //     cout<<"YES";
    // }
    // else{
    //     cout<<"NO";
    // }


//find the number of ways to reach at the bottom right of a MxN matrix
// cout<<waystoreachbottomrightofmatrix(0,0,3,3);
    vector<string>res;
    string str = "abc";
    stringsequence(str,0," ",res);
    for(int i = 0;i,res.size();i++){
        cout<<res[i]<<" ";
    }

    return 0;

}