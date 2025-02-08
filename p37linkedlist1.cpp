#include<iostream>
using namespace std;
class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

node* mergelinkedlists(node* &head1,node* &head2){
    node* dummyheadnode = new node(-1);
    node* ptr1 = head1;
    node* ptr2 = head2;
    node* ptr3 = dummyheadnode;
    while(ptr1 && ptr2){
        if(ptr1->data < ptr2->data){
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else{
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }
    if(ptr1){
        ptr3->next = ptr1;
    }
    else{
        ptr3->next = ptr2;
    }

    return dummyheadnode->next;
}

void insertelements(node* &head,int val){
    node* newnode = new node(val);
    if(head == NULL){
        head = newnode;
        return;
    }
    node* temp = head;
    while(temp != head){
        temp = temp ->next;
    }
    temp ->next = newnode;
}

void display(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }cout<<"NULL";
}
int main(){
    node* head1 = NULL;
    node* head2 = NULL;
   
    insertelements(head1,1);
    insertelements(head1,2);
   
    insertelements(head2,3);
    insertelements(head2,4);
    display(head1);
    cout<<endl;
    display(head2);
    cout<<endl;
    node* head3 = mergelinkedlists(head1,head2);
    display(head3);
   
    return 0;
}
