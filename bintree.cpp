#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct node{
    node *left,*right;
    int key;
    node(int key=0):key(key){left=right=nullptr;};
};

node* insert(node* root,int val){
    if(root == nullptr) return new node(val);
    if(val < root->key) root->left = insert(root->left,val);
    else if(val > root->key) root->right = insert(root->right,val);

    return root;
}

void preorder(node* root){
    if(root == nullptr) return;
    std::cout << root->key << ' ';
    preorder(root->left);
    preorder(root->right);
}

void itpre(node* root){
    std::stack<node*> s;
    while(root || !s.empty()){
        if(root){
            s.push(root);
            std::cout << root->key << ' ';
            root=root->left;
        }else{
            root=s.top();
            s.pop();
            root=root->right;
        }
    }   
    std::cout << '\n';
}

void postorder(node* root){
    if(root==nullptr) return;
    postorder(root->left);
    postorder(root->right);
    std::cout << root->key << ' ';
}

void itpost(node* root){
    std::stack<node*> s;
    node* prev = nullptr;
    while(root || !s.empty()){
        if(root){
            s.push(root);
            root=root->left;
        }else{
            node*n=s.top();
            if(n->right==nullptr || n->right == prev){
                std::cout << n->key << ' ';
                prev = n;
                s.pop();
            } else{
                root = n->right;
            }
        }
    }
    std::cout << '\n';
}

void inorder(node* root){
    if(root == nullptr) return;
    inorder(root->left);
    std::cout << root->key << ' ';
    inorder(root->right);
}

void itin(node* root){
    std::stack<node*> s;
    while(root || !s.empty()){
        if(root){
            s.push(root);
            root=root->left;
        } else{
            root=s.top();
            std::cout<<root->key << ' ';
            s.pop();
            root=root->right;
        }
    }
    std::cout << '\n';
}

void bfs(node* root){
    std::queue<node*> q;
    if(root) q.push(root);
    while(!q.empty()){
        root=q.front();
        q.pop();
        std::cout << root->key << ' ';
        if(root->left) q.push(root->left);
        if(root->right) q.push(root->right);
    }
    std::cout << '\n';
}

void pprint(node* root,int level){
    if(root == nullptr) return;
    pprint(root->right,level+1);
    for(int i = 0; i < level; i++) std::cout << "    ";
    std::cout << root->key << '\n';
    pprint(root->left,level+1);
}

node* minvalue(node* root){
    if(root == nullptr) return root;
    while(root->left){
        root = root->left;
    }
    return root;
}

node* maxvalue(node* root){
    if(root == nullptr) return root;
    while(root->right){
        root = root->right;
    }
    return root;
}

int height(node* root){
    if(root == nullptr) return 0;
    int t1 = 1; int t2 = 1;
    if(root->left) t1 += height(root->left);
    if(root->right) t2 += height(root->right);
    return t1 < t2 ? t2:t1;
}

int size(node* root){
    if(root == nullptr) return 0;
    return size(root->left)+size(root->right)+1;
}

node* find_next(node* root,int val){
    if(!root) return nullptr;
    node* prev = nullptr;
    while(root){
        if(root->key > val){
            prev = root;
            root = root->left;
        } else if(root->key < val) {
            root = root->right;
        } else{
            if(root->right==nullptr) return prev;
            return minvalue(root->right);
        }
    }
    return nullptr;
}

node* search(node* root, int key){
    if(root == nullptr || root->key == key) return root;
    if(root->key < key) return search(root->right,key);
    else return search(root->left,key);
}

node* deletenode(node* root, int key){
    if(root == nullptr) return root;
    if(root->key == key){
        if(root->right && root->left){
            node* n = minvalue(root->right);
            root->key = n->key;
            root->right=deletenode(root->right,n->key); 
        } else{
            node* n;
            if(root->right) n= root->right;
            else n = root->left;
            delete root;
            return n;
        }
    } else{
        if(root->key < key){
            root->right = deletenode(root->right,key);
        }
        else{
            root->left = deletenode(root->left,key);
        }
    } 
    return root;
}

void delete_tree(node* root){
    if(root==nullptr) return;
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}

bool isbal(node* root){
    if(root == nullptr) return true;
    int h = height(root->left) - height(root->right);
    return (h <= 1 && h >= -1);
}

bool isbst(node* root, int minv, int maxv){
    if(root == nullptr) return true;
    return (root->key> minv && root->key<maxv) &&  isbst(root->left,minv,root->key) && isbst(root->right,root->key,maxv);
}

bool isbst(node* root){
    return isbst(root, INT_MIN,INT_MAX);
}

bool sametree(node* a, node* b){
    if(a && b){
        if(a->key != b->key) return false;
        return sametree(a->right,b->right) && sametree(a->left,b->left); 
    }
    else return a==b;
}

#include "pprint.cpp"

int main(){
    node * root=nullptr;
    root = insert(root,8);
    root = insert(root,3);
    root = insert(root,10);
    root = insert(root,14);
    root = insert(root,13);
    root = insert(root,1);
    root = insert(root,6);
    root = insert(root,4);
    root = insert(root,7);

    preorder(root); std::cout << '\n';
    itpre(root);
    postorder(root); std::cout << '\n';
    itpost(root);
    inorder(root); std::cout << '\n';
    itin(root);
    bfs(root);
    pprint(root,0); std::cout << '\n';
    pprint(root,1,0);

    root = deletenode(root,7);
    preorder(root); std::cout << '\n';

    std::cout << minvalue(root)->key << '\n';
    std::cout << maxvalue(root)->key << '\n';
    std::cout << height(root) << '\n';
    std::cout << size(root) << '\n';
    std::cout << "Find(10)next\t"<<find_next(root,10)->key << '\n';
    std::cout << "Find(7)next\t"<<find_next(root,7)->key << '\n';

    root = insert(root,15);
    std::cout << isbal(root) << '\n';
    root = insert(root,16);
    std::cout << isbal(root) << '\n';
    root = insert(root,17);
    std::cout << isbal(root) << '\n';
    std::cout << isbst(root) << '\n';
    return 0;
}
