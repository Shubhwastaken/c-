#include<iostream>

using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int val){
            data = val;
            next = NULL;
            prev = NULL;
        }
};

class dequeu{
    Node* front;
    Node* rear;
    public:
    dequeu(){
        front = rear = NULL;
    }
    void push_front(int x){
        if(front==NULL){
            
            front = rear = new Node(x);
            cout<<"Pushed "<<x<<"in front of  the deque\n";
            return;
        }else{
            Node* temp = new Node(x);
            temp->next = front;
            front->prev = temp;
            front = temp;
            cout<<"Pushed "<<x<<" in front of the deque\n";
            return;

        }       
    }

    void push_back(int x){
        if(front == NULL){
            front = rear = new Node(x);
            cout<<"Pushed "<<x<<" in back of the deque\n";
            return;
        }else{
            Node* temp = new Node(x);
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
            cout<<"Pushed "<<x<<" in back of the deque\n";
            return;
        }
    }

    void pop_front(){
        if(front == NULL){
            cout<<"Deque is already empty"<<endl;
            return;
        }else{
            Node* temp = front;
            cout<<"Popped "<<temp->data<<" from the front\n";
            front = front->next;
            delete(temp);
            if(front){
                front->prev = NULL;
            }else{
                rear = NULL;
            }
        }
    }

    void pop_back(){
        if(front == NULL){
            cout<<"Deque is already empty"<<endl;
            return;
        }else{
            Node* temp = rear;
            cout<<"Popped "<<temp->data<<" from the back\n";
            rear = rear->prev;

            delete(temp);
            if(front){
                rear->next = NULL;
            }else{
                front = NULL;
            }
        }
    }
    
    int start(){
        if(front == NULL){
            return -1;
        }else{
            return front->data;
        }
    }

    int end(){
        if(front == NULL){
            return -1;
        }else{
            return rear->data;
        }
    }
};
int main(){
    dequeu d;
    d.push_back(1);
    d.push_back(2);
    d.push_front(0);
    d.pop_back();
    cout<<d.start()<<endl;
    cout<<d.end()<<endl;
    return 0;
}