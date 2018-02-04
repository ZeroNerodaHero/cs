#include "llist.cpp"
#include <iostream>
#include <exception>
#define SIZE 256

class hashtbl{
 public:	
	hashtbl();
	void insert(int key);
	void deletenode(int key);
	node* search(int key);
	int &operator [](int key);
	void print();
 private:
	node* _hashtbl[SIZE];
	int hash(int num){
        return ((num >> 8)^(num << 4))%SIZE;
    }
};

hashtbl::hashtbl(){
	for(int i = 0; i < SIZE; i++){
		_hashtbl[i] = nullptr;
	}
}

void hashtbl::insert(int key){
	int index = hash(key);
	::insert(_hashtbl[index],key,index); 
}

void hashtbl::deletenode(int key){
	int index = hash(key);
	::deletenode(_hashtbl[index], key);
}

node* hashtbl::search(int key){
	int index = hash(key);
	return ::search(_hashtbl[index],key);
}

int &hashtbl::operator [](int key){
	node* n = search(key);
	if(n == nullptr) throw std::string("Not Found");
	else return n->index;
}

void hashtbl::print(){
	for(int i = 0; i < SIZE; i++){
		if(_hashtbl[i]){
			std::cout << i << ":\t";
			::traverse(_hashtbl[i]);
		}
	}
	std::cout << "_\n";
}

int main(){
	hashtbl h;
	h.insert(456);
	h.insert(456);
	h.insert(632);
	h.insert(832);
	h.insert(932);
	h.print();
	h.deletenode(456);
	h.deletenode(832);
	h[932] = 100;
	h.print();
	std::cout << "h[456]:\t" << h[456] << std::endl;
	try {std::cout << "h[457]:\t" << h[457] << std::endl;} 
	catch(std::string e) {std::cout << e << std::endl;} 
}
