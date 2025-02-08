#include<iostream>
#include<vector>
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

vector<int> pairsumdll(node* head,node* tail,int targetsum){
    vector<int> ans(2,-1);
    while(head != tail){
        int sum = head->data + tail->data;
        if(sum == targetsum){
            ans[0] = head->data;
            ans[1] = tail->data;
            return ans;
        }
        if(sum > targetsum){
            tail = tail->prev;
        }
        else{
            head = head->next;
        }
    }
    return ans;
}
void display(){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"<->";
        temp = temp->next;
    }cout<<"NULL"<<endl;
}

int main(){
    insertelements(2);
    insertelements(5);
    insertelements(6);
    insertelements(8);
    insertelements(10);
    display();
    vector<int> ans = pairsumdll(head,tail,11);
    cout<<ans[0]<<" "<<ans[1]<<endl;

    return 0;
}