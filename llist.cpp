#include <iostream>

struct node{
    int value,index;
    node* next;
    node(int val=0,int index=0):value(val),index(index){next=nullptr;}
    //intialization 
};

node* search(node *head, int key){
    if(head == nullptr || head->value == key) return head;
    return search(head->next,key);
#if 0
    while(head){
        if(head->value == key) return head;
        head=head->next;
    }
    return nullptr;
#endif
}

void insert(node*& head, int data, int index, int pos=0){
    node *cur=head;
    node *newptr=new node(data,index);

    if(pos==0 || head==nullptr){
        newptr->next = head;
        head=newptr;
        return;
    }
    for(int x = 0; x < pos-1; x++){
        if(cur->next == nullptr) break;
        cur=cur->next;
    }
    newptr->next=cur->next;
    cur->next=newptr;
}

void deletenode(node*& head, int data){
    node *cur=head;
    node *prev=nullptr;

    while(cur && cur->value != data){
        prev=cur;
        cur=cur->next;
    }

    if(cur==nullptr) return;
    if(prev==nullptr){
        head=cur->next;
    } 
    else prev->next=cur->next;
    delete cur;
}

void reverse(node*& head){
    node *prev=nullptr;
    node *cur=head;

    while(cur){
        node *tmp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=tmp;
    }
    head=prev;
}

void traverse(node* head){
    node *cur = head;
    while(cur){
        std::cout << cur->value << " " << cur->index << ' ';
        cur=cur->next;
    }
    std::cout << std::endl;
}

#if 0
int main(){
    node *ptr1=new node(0);
    insert(ptr1,1,6);
    insert(ptr1,2,6);
    insert(ptr1,3,6);
    insert(ptr1,5,1);
    //insert(ptr1,6,0);
    traverse(ptr1);
    reverse(ptr1);
    traverse(ptr1);
}
#endif
