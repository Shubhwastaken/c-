#include <iostream>

using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = nullptr;
    }
};

void insertElements(node* &head, int val) {
    node* new_node = new node(val);
    new_node->next = head; 
    head = new_node;
}

void display(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}

void deleteDuplicates(node* &head) {
    if (head == NULL) {
        return;
    }

    node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

void reverseprint(node* &head){
    if(head == nullptr){
        return;
    }
    reverseprint(head->next);
    cout<<head->data;
}

node* reverselinkedlist(node* &head){
    node* prevptr = NULL;
    node* currptr = head;
    while(currptr != NULL){
        node* nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    node* new_head = prevptr;
    return new_head;
}
int main() {
    node* head = nullptr;
    insertElements(head, 3);
    insertElements(head, 3);
    insertElements(head, 2);
    insertElements(head, 2);
    insertElements(head, 1);

    display(head);
    cout<<endl;
    deleteDuplicates(head);
    cout<<endl;
    display(head);
    cout<<endl;
    reverseprint(head);
    cout<<endl;
    head = reverselinkedlist(head);

    cout << "\nReversed linked list: ";
    display(head);
    return 0;
}