#include<iostream>
using namespace  std;
class node{
    public:
        int data;
        node* next;
    node(int value){
        data = value;
        next = NULL;
    }    
};
class stack{
    node* head;
    int size;
    int currsize;
    public:
    stack(int s){
        head = NULL;
        size = s;
        currsize =0; 
    }

    void push(int x){
        if(currsize == size){
            cout<<"Stack overflow"<<endl;
        }
        node* newnode = new node(x);
        newnode->next = head;
        head = newnode;
        currsize++;
    }

    void pop(){
        if(head == NULL){
            cout<<"Stack underflow"<<endl;
            return;
        }
        node* temp = head;
        head = temp->next;
        delete(temp);
    }

    bool isempty(){
        if(head == NULL){
            cout<<"Stack is empty"<<endl;
            return true;
        }
        return false;
    }

    int issize(){
        node* temp = head;
        size = 0;
        while(temp != NULL){
            temp = temp->next;
            size++;
        }
        return size;
    }
    
    int peek() {
    if (head == NULL) {
        cout << "Stack underflow" << endl;
        return -1; 
    }
    return head->data;
}
};
int main(){
    stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(7);
    st.push(5);
    
    st.pop();
    st.pop();
    cout<<st.peek()<<endl;
    cout<<st.issize()<<endl;
    cout<<st.isempty()<<endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout<<st.isempty()<<endl;

    return 0;
}