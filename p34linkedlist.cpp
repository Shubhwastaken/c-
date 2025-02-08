#include<iostream>
using namespace std;
class node{
    public:
    int val;
    node* next;
};
void traverselinkedlist(node* head){
    node* temp = head;
    while(temp != nullptr){
        cout<<temp ->val<<endl;
        temp = temp ->next;
    }
}
int main(){
    node* head = new node;
    head -> val = 1;

    node* node2 = new node;
    node2 ->val = 2;
    head -> next = node2;

    node* node3 = new node;
    node3 ->val = 3;
    node2 ->next = node3;

    node3 ->next = nullptr;
    traverselinkedlist(head);
    return 0;
}