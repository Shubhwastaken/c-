#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

   node(int data) {
     this->data = data;
     next = NULL;
    }
};

void insertathead(node* &head, int data) {
    node* new_node = new node(data);
    new_node->next = head;
    head = new_node;
}

void insertattend(node* &head,int data){
    node* new_node = new node(data);

    if (head == nullptr) {
        head = new_node;
        return;
    }

    node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = new_node;
}

void insertatposition(node* &head,int val,int pos){
    if(pos == 0){
        insertathead(head,val);
        return;
    }
    node* new_node = new node(val);
    node* temp = head;
    int current_pos = 0;
    while(current_pos != pos-1){
        temp = temp ->next;
        current_pos++;
    }
    new_node ->next = temp ->next;
    temp ->next = new_node;
}

void updationatposition(node* &head,int val,int pos){
    node* temp = head;
    int currentposition = 0;
    while(currentposition != pos){
        temp = temp ->next;
        currentposition++;
    }
    temp ->data = val;
}

void deleteathead(node* &head){
    node* temp = head;
    head = temp ->next;
    free(temp);
}

void deleteatend(node* &head){
   node* second_last = head;
   while(second_last ->next->next != nullptr){
    second_last = second_last->next;
   }
   node* temp = second_last->next;
   second_last->next = nullptr;
   free(temp);
}

void deleteatposition(node* &head, int pos) {
    if (pos == 0) {
        deleteathead(head);
        return;
    }

    int current_pos = 0;
    node* prev = head;

    while (current_pos < pos - 1) {
        prev = prev->next;
        current_pos++;
    }

    node* temp = prev->next;
    prev->next = prev->next->next;
    free(temp);
}

void display(node* head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << "->";
        }
        temp = temp->next;
    }
    cout << "->NULL" << endl;
}

int main() {
    node* head = NULL;
    insertathead(head, 2);
    display(head);
    insertathead(head, 1);
    display(head);
    insertattend(head,3);
    display(head);
    insertatposition(head,5,1);
    display(head); 
    // updationatposition(head,4,2);
    // display(head);
    // insertathead(head, 6);
    // display(head);
    // insertathead(head, 7);
    // display(head);
    // insertathead(head, 8);
    // display(head);
    // // deleteathead(head);
    // // display(head);
    // // deleteatend(head);
    // // display(head);
    // deleteatposition(head,3);
    // display(head);
    return 0;
}