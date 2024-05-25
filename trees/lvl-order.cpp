#include<iostream>
#include<queue>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int v){
        data = v;
        left = right = NULL;
    }
};

void level_order(node *root){
    if(root == NULL) return;
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node *temp = q.front();
        q.pop();

        cout<<temp->data<<" ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }

}

int main(){
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);
    level_order(root);
    return 0;
}
