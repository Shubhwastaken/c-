#include<iostream>
using namespace std;

class stack{
    int *arr;
    int top;
    int size;
    public:
        stack(int s){
            top = -1;
            size = s;
            arr = new int[s];
        }

    void push(int value){
        if(this->top == this->size-1){
            cout<<"Stack overflow"<<endl;
            return;
        }
        this->top++;
        this->arr[this->top]=value;
    }
    
    void pop(){
        if(this->top == -1){
            cout<<"Stack underflow"<<endl;
            return;
        } else {
            this->top--;
        }
    }

    int peek(){
        if(this->top == -1){
            cout<<"Stack is empty"<<endl;
            return -1;
        } else {
            return this->arr[this->top];
        }
    }

    bool isempty(){
        return this->top == -1;
    }

    bool isfull(){
        return this->top == this->size-1;
    }

    int issize(){
        return this->top + 1;
    }
};

int main(){
    stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.pop();
    st.push(4);
    
    cout << "Peek: " << st.peek() << endl;
    cout << "Size: " << st.issize() << endl;
    cout << "Is Empty: " << (st.isempty() ? "Yes" : "No") << endl;
    cout << "Is Full: " << (st.isfull() ? "Yes" : "No") << endl;
    
    
    return 0;
}
