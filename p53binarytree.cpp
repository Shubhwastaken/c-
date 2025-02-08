#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }

};

int main(){
    //queue implementation

    int x,leftchild,rightchild;
    cout<<"Enter value of root node : ";
    cin>>x;
    queue<Node*>q;
    Node* rootnode = new Node(x);
    q.push(rootnode);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout<<"Enter left child value "<<temp->data<<" : ";
        cin>>leftchild;
        if(leftchild != -1){
            temp->left = new Node(leftchild);
            q.push(temp->left);
        }

        cout<<"Enter right child value "<<temp->data<<" : ";
        cin>>rightchild;
        if(rightchild != -1){
            temp->right = new Node(rightchild);
            q.push(temp->right);
        }
    }

    return 0;
}