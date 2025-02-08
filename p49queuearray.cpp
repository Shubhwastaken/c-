#include<iostream>
using namespace std;

class queue{
    int *arr;
    int front,rear,size;
    public:
        queue(int n){
            arr = new int[n];
            size = n;
            front=rear=-1;
        }

        bool isempty(){
            return front == -1;
        }

        bool isfull(){
            return (rear+1) % size == front;
        }

        void push(int x) {
            if (isfull()) {
                cout << "Queue Overflow" << endl;
                return;
            }

            if (isempty()) {
                front = rear = 0;
                arr[0] = x; 
            } else {
                rear  = (rear+1)%size;
                arr[rear] = x;
            }

            
        }

        void pop() {
            if (isempty()) {
                cout << "Queue underflow" << endl;
                return;
            } else {
                if (front == rear) {
                    front = rear = -1 ; 
                } else {
                    front = (front+1)%size;
                }
            }
        }

        int start(){
            if(isempty()){
                cout<<"Queue is empty"<<endl;
                return -1;
            }else{
                return arr[front];
            }
        }
};
int main(){
    queue q(5);
    q.push(15);
    q.push(25);
    
    return 0;
}