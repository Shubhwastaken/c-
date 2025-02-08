#include <iostream>

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

bool checklinkedlistequal(node* head1,node* head2){
    while(head1 != NULL && head2 != NULL){
        if(head1 ->data != head2 ->data){
            return false;
        }
        head1 = head1 ->next;
        head2 = head2 ->next;
    }
    return (head1 == NULL && head2 == NULL);
}

void removeknodefromend(node* &head,int k){
    node* ptr1 = head;
    node* ptr2 = head;
    int count = k;
    while(count--){
        ptr2 = ptr2->next;  
    }
    if(ptr2 == NULL){
        node* temp = head;
        head = head->next;
        free(temp);
        return;
    }
    while(ptr2->next != NULL){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;  
    }
    node* temp = ptr1->next;
    ptr1->next = ptr1->next->next;
    free(temp);
}
int main() {
    
    // node* head1 = NULL;
    // insertelements(head1, 1);
    // insertelements(head1, 2);
    // insertelements(head1, 3);
   
    // node* head2 = NULL;
    // insertelements(head2, 6);
    // insertelements(head2, 7);
    // insertelements(head2, 3);
    
    
    // if (checklinkedlistequal(head1, head2)) {
    //     cout << "The linked lists are equal." << endl;
    // } else {
    //     cout << "The linked lists are not equal." << endl;
    // }
    node* head3 = NULL;
    insertelements(head3, 1);
    insertelements(head3, 2);
    insertelements(head3, 3);
    insertelements(head3, 6);
    insertelements(head3, 7);
    insertelements(head3, 8);
    display(head3);
    cout<<endl;
    removeknodefromend(head3,2);
    display(head3);
    return 0;
}