#include<iostream>
using namespace std;
int main(){
    int a = 10;
    cout<<a<<endl;
    int *p = new int();
    *p = 10;
    cout<<*p<<endl;
    cout<<p<<endl;
    delete(p);
    p = new int[4];
    cout<<p<<endl;
    delete[]p;
    p = NULL;
    cout<<p<<endl;
    return 0;
}