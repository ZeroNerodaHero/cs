#include <iostream>

struct tnode{
    tnode * ar[2];
    tnode(){
        ar[0] = nullptr;
        ar[1] = nullptr;
    }
};

void insert(tnode * root, int var){ 
    for(int i = 31; i >= 0; i--){
        int index = (var>>i) & 1;
        if(root->ar[index] == nullptr){
            root->ar[index] = new tnode;
        }
        root = root->ar[index];
    }
}

int search(tnode * root, int var){
    int ret = 0;
    for(int i = 31; i >= 0; i--){
        ret = ret << 1;
        int index = (var>>i);
        index = index - (index & ~1);
        int b = (index ^ 1);
        if(root->ar[b] != nullptr){
            root = root->ar[b];
            ret = ret | 1;
        }
        else root = root->ar[index];
    }
    return ret;
}

int findmax(int ar[], int size){
    tnode *root = new tnode;
    int big = 0;
    for(int i = 0; i < size; i++){
        insert(root, ar[i]);
        int n = search(root,ar[i]);
        if(n > big) big = n;        
    }
    return big;
}

int main(){
    int ar[] = {12, 15, 5, 1, 7, 9, 8, 6, 10, 13};
    int size = sizeof(ar)/sizeof(int);
    std::cout << findmax(ar,size) << std::endl;
    return 0;       
}
