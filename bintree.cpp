#include <iostream>

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

void postorder(node* root){
	if(root==nullptr) return;
	postorder(root->left);
	postorder(root->right);
	std::cout << root->key << ' ';
}

void inorder(node* root){
	if(root == nullptr) return;
	inorder(root->left);
	std::cout << root->key << ' ';
	inorder(root->right);
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
	postorder(root); std::cout << '\n';
	inorder(root); std::cout << '\n';

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
