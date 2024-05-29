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

bool level(struct node *root, struct node *a, int lvl){
    if(root == NULL) return false;
    if(root->data == a->data) return true;

    if(!level(root->left, a, lvl+1)) return false;
    
    return level(root->right, a, lvl+1);
}
bool isSiblings(struct node *root, struct node *a, struct node *b){
    if(root == NULL) return false;

    return((root->left == a && root->right == b) 
            || (root->right == a && root->left ==b)
            || isSiblings(root->left, a, b)
            || isSiblings(root->right, a, b));
}

bool isCousins(struct node *root, struct node *a, struct node *b){
    // check the level of the both nodes
    bool llvl = level(root, a, 1);
    bool rlvl = level(root, b, 1);

    return ((llvl == rlvl) && !isSiblings(root, a, b));

}

int main(){
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);

    // Tests
    if(isCousins(root, root->left->left, root->right->right)){
        cout<<"They are siblings\n";
    } else {
        cout<<"They are NOT siblings\n";
    }
    if(isCousins(root, root->left->right, root->right->right)){
        cout<<"They are siblings\n";
    } else {
        cout<<"They are NOT siblings\n";
    }
    if(isCousins(root, root->left, root->right)){
        cout<<"They are siblings\n";
    } else {
        cout<<"They are NOT siblings\n";
    }
    return 0;

}
