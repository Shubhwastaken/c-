#include<iostream>
using namespace std;
template<typename T>
class node{
    public:
        T data;
        node* next;
    node(T val){
        data = val;
        next = NULL;
    }    
};
int main(){
    node<int>*  node1 = new node<int>(3);
    cout<<node1->data<<endl;
    node<char>* node2 = new node<char>('a');
    cout<<node2->data<<endl;
    return 0;
}