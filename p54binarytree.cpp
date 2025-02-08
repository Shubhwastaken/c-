#include<iostream>
#include<vector>
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

Node* Binarytree(){
    int x;
    cin>>x;
    
    if(x == -1){
        return NULL;
    }
    Node* temp = new Node(x);
    cout<<"Enter left child of "<<x<<" :";
    temp->left = Binarytree();
    cout<<"Enter right child of "<<x<<" :";
    temp->right = Binarytree();
    return temp;
}

void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

void postorder(Node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int sumofbt(Node* root){
    if(root == NULL){
        return 0;
    }
    return root->data + sumofbt(root->left) + sumofbt(root->right);
}

int leafnodescount(Node* root,int &count){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL || root->right == NULL){
        count++;
        
    }
    leafnodescount(root->left,count);
    leafnodescount(root->right,count);
    
    return count;
}

int nonleafnodescount(Node* root,int &count){
    if(root == NULL){
        return 0;
    }
    if(root->left != NULL || root->right != NULL){
        count++;
        
    }
    leafnodescount(root->left,count);
    leafnodescount(root->right,count);
    
    return count;
}
int heightoftree(Node* root,int h){
    if(root == NULL){
        return 0;
    }
    return 1 + max(heightoftree(root->left),heightoftree(root->right));
}


int main(){

    cout<<"Enter root node : ";
    Node* root;
    root = Binarytree();

    //cout<<"Preorder : ";
    //preorder(root);

    //cout<<"\nInorder : ";
    //inorder(root);

    //cout<<"\nPost Order : "<<endl;
    //postorder(root);
    int sum = sumofbt(root);
    cout<<sum<<endl;
    int count = 0;
    // int leafnodes = leafnodescount(root,count);
    // cout<<leafnodes<<endl;
    int nonleafnodes = nonleafnodescount(root,count);
    cout<<leafnodes<<endl;
    return 0;
}