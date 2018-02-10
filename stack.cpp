#include <iostream>
#include <string>
#include <unordered_map>

template <typename T>
class myStack{
 public:
	myStack();
	void push(const T &val);
	void pop();
	T top();
	int size();
	bool empty() const;
 private:
	static const int SSIZE=128;
	T arr[SSIZE];
	int cur;
};

template <typename T>
myStack<T>::myStack(){
	int cur = 0;
}

template <typename T>
void myStack<T>::push(const T &val){
	if(cur==SSIZE) throw std::string("overflow");
	arr[cur++] = val;
}

template <typename T>
void myStack<T>::pop(){
	if(empty()) throw std::string("empty stack -pop"); 
	cur--;
}

template <typename T>
T myStack<T>::top(){
	if(empty()) throw std::string("empty stack -top");
	return arr[cur-1];
}

template <typename T>
int myStack<T>::size(){
	return cur;
}

template <typename T>
bool myStack<T>::empty() const{
	return bool(cur == 0);
}

bool isValid(const std::string &str){
	std::unordered_map<char,char> combo = {{')','('},{'}','{'},{']','['}};
	myStack<char> letters;
	for(int x = 0; x < str.length(); x++){ 
		if(str[x] == '{' || str[x] == '[' || str[x] == '(')
			letters.push(str[x]);
		else if(str[x] == '}' || str[x] == ']' || str[x] == ')'){
			if(letters.empty() || letters.top() == combo[str[x]]) return false;
			letters.pop();
		}
	}
	return letters.empty();
}

#if 0
int main(){
	std::cout << isValid("())") << std::endl;
	std::cout << isValid("a[{{()}}") << std::endl;
	std::cout << isValid("a{{())}}") << std::endl;
	std::cout << isValid("a") << std::endl;
}
#endif
