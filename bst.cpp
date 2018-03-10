#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct node{
	node *left,*right;
	int key;
	node(int key=0):key(key){left=right=nullptr;};
};

class bst {
public:


	class iterator {
		iterator(node *n==nullptr) {
		} 

	operator !=()

	operator *

	operator ++()
	};

	iterator begin() {
		return iterator(root); 
	}

	iterator end() {	
		return iterator(); 
	}

bst(){
	root = nullptr;
}

void insert(int val){
	if(root == nullptr) root = new node(val);
	else insert(root, val);
}

node * insert(node *n, int val)
{
	if(n== nullptr) return  new node(val);

	if(val < n->key) n->left = insert(n->left,val);
	else if(val > n->key) n->right = insert(n->right,val);
	return n;
}

void trav()
{
	inorder(root);
}

void inorder(node *n){
	if(n == nullptr) return;
	inorder(n->left);
	std::cout << n->key << ' ';
	inorder(n->right);
}

private:
	node *root;
};


int main(){
	bst b;
	b.insert(3);
	b.insert(5);
	b.insert(6);
	b.insert(7);
	b.insert(9);
	b.insert(8);
	b.trav(); std::cout << '\n';

	for (bst::iterator it=b.begin(); it !=b.end(); ++it) {
		cout << *it << ' ';
	}
	cout << endl;
	return 0;
}
