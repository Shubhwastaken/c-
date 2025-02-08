#include<iostream>
using namespace std;

class node{
    public:
        int val;
        node* next;
};

int main(){
    node* head = new node();
    head ->val = 69;
    head ->next = nullptr; 
    cout<<head->val<<endl;
    cout<<head->next<<endl; 

    return 0;
}