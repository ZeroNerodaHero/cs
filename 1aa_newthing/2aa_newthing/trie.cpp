#include <iostream>
using namespace std;
const int ASIZE = 128;

class trie {
public:
    struct tnode
    {
        bool end;
        tnode *children[ASIZE];

        tnode()
        {
            end = false;
            for (int i = 0; i < ASIZE; i++)
                children[i] = nullptr;
        }
    };

    trie() {
        root = new tnode();
    }

    ~trie() {
        delete root;
    }

    void insert(const string &key){
		tnode * tmp = root;
		for(int i = 0; i < key.length(); i++){
			int index = key[i];
			if(tmp->children[index] == nullptr){
				tmp->children[index] = new tnode();
			}
			tmp = tmp->children[index];
		}
		tmp->end = true;
	}

    bool search(const string &key){
		tnode * tmp = root;
		for(int i = 0; i < key.length(); i++){
			int index = key[i];
			if(tmp->children[index] == nullptr) return false;
			tmp = tmp->children[index];
		}	
		return tmp->end;
	}

    void deletion(const string &key){
		deletion(root,key,0);	
	}

    void traverse(){
		std::string s;
		traverse(root, s);
	}

private:
    tnode * root;
    void traverse(tnode *p, std::string &s){
		if(p->end == true) std::cout << s << std::endl;
		for(int i = 0; i < ASIZE; i++){
			if(p->children[i] != nullptr){
				s.push_back(char(i));
				traverse(p->children[i], s); 
				s.pop_back();
			}	
		}
	}

    bool deletion(tnode *p,const string &key, int level){
		if(level == key.length()){
			p->end = false;
			return is_free_node(p);		
		}	
		if(p->children[key[level]] == nullptr) return false;	
		if(deletion(p->children[key[level]],key,level+1)){
			delete p->children[key[level]];
			p->children[key[level]] = nullptr;
			return !is_leaf_node(p) && is_free_node(p);
		}
		return false;
	}

    bool is_leaf_node(tnode *p){
		return p->end;
	}

    bool is_free_node(tnode *p){
		for(int i = 0; i < ASIZE; i++){
			if(p->children[i] != nullptr) return false;
		}
		return true;
	}
};

int main(){
	trie t;
	string keys[] = {"the", "a", "there",
                    "answer", "any", "by",
                     "bye", "their" };
	int n = sizeof(keys)/sizeof(keys[0]);
	for (int i = 0; i < n; i++)
        t.insert(keys[i]);	
	t.traverse();
	cout << "\n";
	t.search("the")? cout << "Yes\n" :
                         cout << "No\n";
    t.search("these")? cout << "Yes\n" :
                           cout << "No\n";
	t.deletion("there");
	cout << "\n";
	t.traverse();
	cout << "\n";
	t.search("there")? cout << "Yes\n" : cout << "No\n";
    return 0;
}
