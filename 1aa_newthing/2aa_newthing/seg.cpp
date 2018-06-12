#include <iostream>

class segtree{
 public:
	segtree(int ar[],int len){
		size = len;
		root = build(ar,0,size-1);
	}
	void  update(int id, int diff){
		update(root,0,size-1,id,diff);
	}
	int query(int l, int r){
		return query(root,0,size-1,l,r);
	}
 private:
	struct segnode{
		segnode *left, *right;
		int sum;
		segnode(){
			sum = 0;
			left = right = nullptr;
		}
	};
	int size; 
	segnode *root;

	segnode * build(int ar[], int start, int end){
		segnode * tmp = new segnode;
		if(start == end){
			tmp->sum = ar[start];
			return tmp;
		}
		int mid = (start + end)/2;
		tmp->left = build(ar,start,mid);
		tmp->right = build(ar,mid+1,end);
		tmp->sum = tmp->left->sum + tmp->right->sum;
		return tmp;

	}

	void update(segnode *n, int start, int end, int id, int diff){
		n->sum += diff;
		if(start == end) return;
		int mid = (start + end)/2;
		if(id <= mid){
			return update(n->left,start,mid,id,diff);	
		}
		return update(n->right,mid+1,end,id,diff);
	}

	int query(segnode *n, int start, int end, int l, int r){
		if(start >= l && end <= r) return n->sum;
		if(start > r || end < l) return 0;
		int mid = (start + end)/2;
		return query(n->left,start,mid,l,r) + query(n->right,mid+1,end,l,r);
	}
};

int main(){
	int ar[] = {1, 3, 5, 7, 9, 11};
	int n = sizeof(ar)/sizeof(ar[0]);	
	segtree t(ar,n);

	std::cout << t.query(1,3) << std::endl;
	t.update(1,10);
	std::cout << t.query(1,3) << std::endl;		
	return 0;
}
