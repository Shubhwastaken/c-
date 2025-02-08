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

void insertattail(node* &head, int value) {
    node* new_node = new node(value);

    if (head == NULL) {
        head = new_node;
        return;
    }

    node* temp = head;
    while (temp != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
}

void display(node* &head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}

void deleteAlternateNodes(node* &head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    node* current = head;
    node* prev = NULL;

    while (current != NULL && current->next != NULL) {
        prev = current;
        current = current->next->next;
        prev->next = current;
    }
}

int main() {
    node* head = NULL;
    insertattail(head, 1);
    insertattail(head, 2);
    insertattail(head, 3);
    insertattail(head, 4);
    insertattail(head, 5);
    insertattail(head, 6);

    cout << "Original linked list: ";
    display(head);

    deleteAlternateNodes(head);

    cout << "\nLinked list after deleting alternate nodes: ";
    display(head);

    return 0;
}