#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
};

void insertelements(node* &head,int val){
    node* newNode = new node();
    newNode->data = val;

    if (head == NULL) {
        head = newNode;
    } else {
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
}

void display(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }cout<<"NULL";
}
node* rotatebyktimes(node* &head,int k){
    int n;
    node* tail = head;
    while(tail->next != NULL){
        n++;
        tail = tail->next;
    }
    n++;
    k = k%n;
    if(k == 0){
        return head;
    }
    tail ->next = head;
    node* temp = head;

    for(int i = 0;i<n-k;i++){
        temp = temp ->next;
    }

    node* newhead = temp->next;
    temp->next = NULL;
    return newhead;
}

node* oddeven(node* &head){
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    node* even = head->next;
    node* evenptr = even;
    node* oddptr = head;
    while(evenptr != NULL && evenptr->next != NULL){
        oddptr->next = oddptr->next->next;
        evenptr->next = evenptr->next;
        oddptr = oddptr->next;
        evenptr = evenptr->next;
    }
    oddptr->next = even;
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
    // head = rotatebyktimes(head,2);
    // cout<<endl;
    // display(head);


   

    head = oddeven(head);
    cout<<endl;
    display(head);

    return 0;
}