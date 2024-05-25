#include<iostream>

using namespace std;

// structure of the binary tree
struct node{
    int data;
    struct node *left, *right;
    node(int v){
        data = v;
        left = right = NULL;
    }
};

//left root right
void inorder(struct node *node){
    if(node == NULL) return;

    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

// left right root
void postorder(struct node *node){
    if(node == NULL) return;
    
    postorder(node->left);
    postorder(node->right);
    cout<<node->data<< " ";
}

// root left right
void preorder(struct node *node){
    if(node == NULL) return;

    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}

int main(){
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);

    cout<<"Inorder"<<"\n";
    inorder(root);
    cout<<"Preoder"<<"\n";
    preorder(root);
    cout<<"Postorder"<<"\n";
    postorder(root);
    return 0;

}
