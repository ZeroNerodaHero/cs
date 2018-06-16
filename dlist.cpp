#include <iostream>

struct node{
    node *next, *prev;  
    int key;
    node(int x=0): key(x){ next=prev=nullptr;}
};

class dlist{
 public:
    dlist();
    void insert(int val,int pos=0);
    void erase(int pos=0);
    void remove(int val);
    void swap(dlist & other){
        node *tmp = other.head; 
        other.head=head;
        head = tmp;

        tmp = other.tail;
        other.tail = tail;
        tail = tmp;

        int tmp1 = other.count;
        other.count=count;
        count=tmp1;
    }
    void print(){
        node *cur = head;
        while(cur){
            std::cout << cur->key << ' ';
            cur=cur->next;
        }
        std::cout << '\n';
    }
    int &front();
    int &back();
    bool empty();
 private:
    node *head,*tail;
    int count;
};

dlist::dlist(){
    head = tail = nullptr;
    count = 0;
}
void dlist::insert(int val,int pos){
    node *tmp = new node(val); node *cur = head;
    if(empty()){
        head = tail = tmp;
    } 
    else if(pos == 0){
        tmp->next=head;
        head->prev=tmp;
        head = tmp;
    }
    else{
        while(pos != 0 && cur != nullptr){
            cur=cur->next;
            pos-=1;
        }
        if(cur == nullptr){
            tail->next = tmp;
            tmp->prev = tail;
            tail = tmp;
        }
        else{
            tmp->next=cur;
            tmp->prev=cur->prev;
            cur->prev->next=tmp;
            cur->prev=tmp;
        }
    }
    count++;
}
void dlist::erase(int pos){
    node *cur = head;
    if(empty() || pos >= count) return;
    while(pos != 0){
        cur=cur->next;
        pos--;
    }
    if(cur == head || cur == tail){
        if(cur == head){
            if(head->next) head->next->prev=nullptr;
            head = head->next;
        }
        if(cur == tail){
            if(tail->prev) tail->prev->next=nullptr;
            tail=tail->prev;
        }
    }   
    else{
    cur->prev->next = cur->next;
    cur->next->prev= cur->prev;
    }
    count--;
    delete cur;
}
void dlist::remove(int val){
    if(empty()) return;
    node *cur = head;

    while(cur && cur->key != val){
        cur=cur->next;  
    }
    if(cur == nullptr) return;
    if(cur == head || cur == tail){
        if(cur == head){
            if(head->next) head->next->prev=nullptr;
            head = head->next;
        }   
        if(cur == tail){
            if(tail->prev) tail->prev->next=nullptr;
            tail=tail->prev;
        }   
    }
    else{
    cur->prev->next = cur->next;
    cur->next->prev= cur->prev;
    }
    count--;
    delete cur;
}
int &dlist::front(){
    if(head) return head->key;
    else throw std::string("No head");
}
int &dlist::back(){
    if(tail) return tail->key;
    else throw std::string("No tail");
}
bool dlist::empty(){
    return count==0;
}

int main(){
    dlist l1;
    l1.insert(0);
    l1.insert(1);
    l1.insert(2);
    l1.print();
    dlist l2;
    l2.insert(9);
    l2.insert(8);
    l2.insert(7);
    l2.print();
    l1.swap(l2);
    std::cout << "l1\t"; l1.print();
    return 0;
}
