#include<iostream>
using namespace std;
int getbit(int n,int pos){
    return ((n & (1<<pos))!=0);//this is done to get the bit at the given position
}
int setbit(int n,int pos){
    return (n | (1<<pos));
}
int clearbit(int n,int pos){
    int mask = ~(1<<pos);
    return (n & mask);
}
int main(){
    int a = 5;
    cout<<(a<<2)<<endl;//left shifting by 2
    cout<<a<<endl;
    
    cout<<getbit(5,2)<<endl;
    cout<<setbit(5,1)<<endl;
    cout<<clearbit(5,2)<<endl;
    return 0;
}