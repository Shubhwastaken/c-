#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* prev;
};

node* head = nullptr;
node* tail = nullptr;

void insertatstart(int val) {
    node* newnode = new node();
    newnode->data = val;
    if (head == nullptr) {
        head = newnode;
        newnode->prev = nullptr;
        newnode->next = nullptr; // Set next to nullptr
        tail = newnode; // Also set tail if it's the first node
        return;
    }

    newnode->next = head;
    head->prev = newnode;
    newnode->prev = nullptr;
    head = newnode;
}

void insertAtTail(int value) {
    node* newNode = new node();
    newNode->data = value;
    newNode->prev = tail;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtKthNode(int val, int k) {
    node* newnode = new node();
    newnode->data = val; 
    node* temp = head;

    if (k == 1) {
        insertatstart(val);
        return;
    }
    for (int i = 1; i < k - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    newnode->prev = temp;
    if (newnode->next != nullptr) {
        newnode->next->prev = newnode;
    } else {
        tail = newnode; 
    }
}

void deleteatstart(){
    node* temp = head;
    if(head == NULL){
        return;
    }
    head = head->next;
    if(head == NULL){
        tail = NULL;
    }else{
        head->prev = NULL;
    }
    delete(temp);

}

void deleteatend(){
    if(tail == NULL){
        return;
    }
    node* temp = tail;
    tail = tail->prev;
    if(tail == NULL){
        head = NULL;
    }
    else{
        tail->next = NULL;
    }
    delete(temp);
}

void deleteatkthnode(int k){
    if(head == NULL){
        return;
    }
    if(k == 1){
        deleteatstart();
        return;
    }

    node* temp = head;
    for(int i = 1;i < k && temp != NULL;i++){
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete(temp);
}


void display() {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << "<->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    insertAtTail(10);
    insertAtTail(20);
    insertAtTail(30);
    insertAtTail(40);
    insertAtKthNode(15, 2);
    display(); 
    deleteatstart();
    display();
    deleteatend();
    display();
    deleteatkthnode(2);
    display();
    return 0;
}
