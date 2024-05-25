#include<iostream>
#include<queue>
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


// insert an element in the tree
node* insert(int data, node *root){
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node *temp = q.front();
        q.pop();
        if(temp->left == NULL){
            temp->left = new node(data);
            break;
        } else {
            q.push(temp->left);
        }

        if(temp->right == NULL){
            temp->right = new node(data);
            break;
        } else {
            q.push(temp->right);
        }

    }
    return root;
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
    
    root = insert(7, root);

    cout<<"Preoder"<<"\n";
    preorder(root);
    return 0;

}
