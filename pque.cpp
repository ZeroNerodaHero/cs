#include <iostream>
#include "llist.cpp"

class myque{
 public:
    myque();
    void push(const int &val);
    void insert(const int &val);
    void pop();
    int &front();
    int &back();
    bool empty() const;
    int size() const;
    void swap(myque & other);
    ~myque(){
        while(!empty()) pop();
        std::cout << "Empty - " << empty() << std::endl;
    }
 private:
    node *head,*tail;
    //node dummy;
    int count;
};

myque::myque(){
    head = tail = nullptr;
    count = 0;
}

void myque::insert(const int &val){
    node *tmp = new node(val);
    if(tail == nullptr) head = tail = tmp;
    while(val < head->value){
        head = head->next;
    } 
    node *smthing = head->next;
    head->next = tmp;
    tmp->next = smthing;
}

void myque::push(const int &val){
    node*tmp = new node(val);
    if(tail != nullptr){
        tail->next = tmp;
        tail = tail->next;
    } else{
        head = tail = tmp;
    }
    count++;
}

void myque::pop(){
    if(empty()) throw std::string("empty que");
    if(size()==1){
        delete head;
        head = tail = nullptr;
    } else{
        node*tmp = head;
        head= head->next;
        delete tmp;
    }
    count--;
}

int &myque::front(){
    if(empty()) throw std::string("no front");
    return head->value;
}

int &myque::back(){
    if(empty()) throw std::string("no back");
    return tail->value;
}

bool myque::empty() const{
    return head==nullptr;
}

int myque::size() const{
    return count;
}

void myque::swap(myque & other){
    node*tmp=other.head;
    other.head=head;
    head=tmp;
    tmp=other.tail;
    other.tail=tail;
    tail=tmp;
}

void print(myque &que){
    que.front() = 100;
    std::cout << que.back() << std::endl;
    while(!que.empty()){
        std::cout << que.front() << " ";
        que.pop();
    }
    std::cout<< '\n';
}

int main(){
    myque que1;
    que1.insert(1);
    que1.insert(2);
    que1.insert(2);
    que1.insert(3);
    que1.insert(3);
    que1.insert(4);
    myque que2;
    que2.insert(5);
    que2.insert(6);
    que2.insert(7);
    que2.insert(8);
    que1.swap(que2);
    std::cout << "que 1: "; print(que1);
    std::cout << "que 2: "; print(que2);
    std::cout << que1.empty() << std::endl;
}
