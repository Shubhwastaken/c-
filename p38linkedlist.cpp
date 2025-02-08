#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
};
void insertelements(node* &head,int val){
    node* newnode = new node();
    newnode->data = val;
    if(head == NULL){
        newnode = head;
    }
    else{
        node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void display(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }cout<<"NULL";
}
node* reorderlinkedlist(node* &head){
    node* slow = head;
    node* fast = head;
    while(fast != NULL && fast->next != NULL){             //helps in finding middle element where we divide the linkedlist into two
        slow = slow->next;
        fast = fast->next->next;
    }
    node* prev = slow;                                 //reversing the second half of the linkedlist
    node* currentptr = slow->next;
    slow->next = NULL;
    while(currentptr != NULL){
        node* nextptr = currentptr->next;
        currentptr->next = prev;
        prev = currentptr;
        currentptr = nextptr;
    }
    node* ptr1 = head;
    node* ptr2 = prev;
    while(ptr1 != ptr2){
        node* temp = ptr1->next;
        ptr1->next = ptr2;
        ptr1 = ptr2;
        ptr2 = temp;
    }
    return head;
}
int main(){
    node* head = new node();
    insertelements(head,1);
    insertelements(head,2);
    insertelements(head,3);
    insertelements(head,4);
    insertelements(head,5);
    display(head);
    cout<<endl;
    head = reorderlinkedlist(head);
    display(head);

    return 0;
}