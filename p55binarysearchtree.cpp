#include<iostream>
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
Node* createbst(Node* &root,int target){
    if(root == NULL){
        Node* temp = new Node(target);
        return temp;
    }
    if(target < root->data){
        root->left = createbst(root->left,target);
    }else{
        root->right = createbst(root->right,target);
    }
    return root;
}

void inorder(Node* root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

bool searchinbst(Node* root,int target){
    if(root == NULL){
        return false;
    }
    if(root->data == target){
        return true;
    }
    if(target < root->data){
         return searchinbst(root->left,target);
    }else{
        return searchinbst(root->right,target);
    }
    
}
int main(){
    int arr[] = {6,3,17,5,11,18,2,1,20,14};
    Node* root = NULL;
    for(int i = 0;i < 10;i++){
        root = createbst(root,arr[i]);
    }
    inorder(root);
    cout<<endl;
    int target = 18;
    cout<<searchinbst(root,target)<<endl;
    return 0;
}