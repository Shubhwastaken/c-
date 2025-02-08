#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
};

void insertatstart(node* &head, int val) {
    node* newnode = new node();
    newnode->data = val;
    if (head == NULL) {
        head = newnode;
        newnode->next = newnode; 
        return;
    }
    node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }
    newnode->next = head;
    tail->next = newnode;
    head = newnode;
}

void insertatend(node* &head, int val) {
    node* newnode = new node();
    newnode->data = val;
    newnode->next = head; 
    if (head == NULL) {
        head = newnode;
        newnode->next = newnode; 
        return;
    }
    node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void insertatpos(node* &head, int pos, int val) {
    if (pos < 1) {
        return;
    }
    node* newnode = new node();
    newnode->data = val;
    if (head == NULL) {
        head = newnode;
        newnode->next = newnode; 
        return;
    }
    if (pos == 1) {
        insertatstart(head, val);
        return;
    }
    int count = 1;
    node* temp = head;
    while (temp->next != head && count < pos - 1) {
        temp = temp->next;
        count++;
    }
    
    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteatstart(node* &head) {
    if (head == NULL) return;
    node* temp = head;
    if (head->next == head) {
        delete head; 
        head = NULL;
        return;
    }
    node* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }
    head = head->next;
    tail->next = head;
    delete temp;
}

void deleteatend(node* &head) {
    if (head == NULL) {
        return;
    }
    if (head->next == head) { 
        delete head;
        head = NULL;
        return;
    }
    node* temp = head;
    while (temp->next->next != head) {
        temp = temp->next;
    }
    delete temp->next; 
    temp->next = head;
}

void deleteatpos(node* &head, int pos) {
    if (head == NULL) {
        return; 
    }

   
    if (pos == 1) {
        deleteatstart(head);
        return;
    }

    node* temp = head;
    int count = 1;

    
    while (temp->next != head && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    
    if (temp->next == head && count < pos - 1) {
        cout << "Position out of bounds" << endl;
        return; 
    }

   
    node* nextNode = temp->next; 
    
    temp->next = nextNode->next;

    
    if (nextNode == head) {
        head = temp->next; 
    }

    delete nextNode; 
}


void display(node* head) {
    if (head == NULL) return; 
    node* temp = head;
    do {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
    cout<<endl;
}

int main(){
    node* head = NULL; 
    insertatstart(head, 3);
    insertatstart(head, 2);
    insertatstart(head, 1);
    display(head);
    insertatend(head, 4);
    display(head);
    insertatpos(head, 2, 5);
    display(head);
    deleteatstart(head);
    display(head);
    deleteatend(head);
    display(head);
    deleteatpos(head,2);
    display(head);
    return 0;
}
