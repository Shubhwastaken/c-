#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertElements(Node* &head, int val) {
    Node* newNode = new Node();
    newNode->data = val;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display(Node* head) {
    Node* current = head;

    while (current != NULL) {
        cout << current->data << "-> ";
        current = current->next;
    }
    cout <<"NULL"<<endl;
}
Node* middleNode(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

bool checkcycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        if(head == NULL){
        return false;
        }
    slow = slow->next;
    fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
}

void createcycle(Node* &head){
    Node* temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    temp->next = head->next->next;
}

void deletecycle(Node* &head) {
    Node* slow = head;
    Node* fast = head;

    do {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast && fast != NULL && fast->next != NULL);

    if (slow != fast) {
        return; 
    }

    fast = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL;
}

bool llpalindromecheck(Node* &head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* prevptr = NULL;
    Node* currentptr = slow;
    Node* nextptr = NULL;
    while (currentptr != NULL) {
        nextptr = currentptr  ->next;
        currentptr->next = prevptr;
        prevptr = currentptr;
        currentptr = nextptr; 

    }

    Node* ptr1 = head;
    Node* ptr2 = prevptr;
    while (ptr2 != NULL) {
        if (ptr1->data != ptr2->data) {
            return false;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return true;
}

int main() {
    Node* head = NULL;
    insertElements(head, 1);
    insertElements(head, 2);
    insertElements(head, 3);
    insertElements(head, 4);
    insertElements(head, 5);
   
    //q1
    // Node* middle = middleNode(head);
    // display(head);
    // cout << "Middle node value: " << middle->data << endl;


    //q2
    // createcycle(head);
    // cout<<checkcycle(head)<<endl;
    // deletecycle(head);
    // cout<<endl;
    // cout<<checkcycle(head)<<endl;
    // display(head);

    //q3linkedlistpalindrome
    Node* head1 = NULL;
    insertElements(head1, 1);
    insertElements(head1, 2);
    insertElements(head1, 3);
    insertElements(head1, 3);
    insertElements(head1, 2);
    insertElements(head1, 1);
    cout<<llpalindromecheck(head1)<<endl;
    display(head1);
    return 0;
}