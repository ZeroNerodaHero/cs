#include <iostream>

struct node{
    node *left, *right;
    int key;
};

bool is_minheap(node *root){
    if(root == nullptr) return true;
    if(root->left == nullptr && root->right = nullptr) return true;
    if(root->left == nullptr) return false; 
    if(root->right == nullptr){
        if(root->left->key < root->key) return false;
        else return is_minheap(root->left);
    }
    if(root->right->key < root->key || root->left->key < root->key) return false;
    return is_minheap(root->right) && is_minheap(root->left);
}
