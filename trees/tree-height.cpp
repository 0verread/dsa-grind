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

int tree_height(node *root){

    if(root==NULL) return 0;
    else {

        int lheight = tree_height(root->left);
        int rheight = tree_height(root->right);

        return max(lheight, rheight) + 1;
    }
}

int main(){
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);
    root->right->right->left = new node(7);
    
    struct node *root1 = new node(10);
    int max_height = tree_height(root);
    int max_height_1 = tree_height(NULL);
    int max_height_2 = tree_height(root1);
    cout <<"Max height of the tree is: " << max_height << "\n";
    cout <<"Max height of the tree is: " << max_height_1 << "\n";
    cout <<"Max height of the tree is: " << max_height_2 << "\n";

    return 0;

}
