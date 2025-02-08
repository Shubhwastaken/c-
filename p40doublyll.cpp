#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node* next;
        node* prev;
    
};
node* head = nullptr;
node* tail = nullptr;
void insertelements(int val) {
        node* newNode = new node();
        newNode->data = val;
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
}

void display(){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"<->";
        temp = temp->next;
    }cout<<"NULL"<<endl;
}

void reversedll(node* &head){
    node* temp = head;
    while(temp != NULL){
        node* nextptr = new node();
        nextptr = temp->next;
        temp->next = temp->prev;
        temp->prev = nextptr;
        temp = nextptr;

    }
    node* newhead = tail;
    tail = head;
    head = newhead;
}

bool pallindromecheck(node* &head,node* &tail){
    while(head != tail && tail != head->prev){
        if(head->data != tail->data){
            return false;
        }
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

void deletenodewithsameneighbours(node* &head,node* &tail){
    node* temp = tail->prev;
    while(temp != head){
        node* prevnode = temp->prev;
        node* nextnode = temp->next;
        if(prevnode->data == nextnode->data){
            prevnode->next = nextnode;
            nextnode->prev = prevnode;
            delete(temp);
        }
        temp = prevnode;
    }
}
int main(){
    
    insertelements(1);
    insertelements(2);
    insertelements(3);
    insertelements(2);
    display();
    // reversedll(head);
    // display();
    // cout<<pallindromecheck(head,tail);
    deletenodewithsameneighbours(head,tail);
    display();
    return 0;
}