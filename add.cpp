#include <iostream>

int add(int a, int b){
	while(b!=0){
		int tmp = a&b;
		a = a^b;
		b = tmp << 1;
	}
	return a;
}

int main(){
	std::cout << add(10,10) << std::endl;
	std::cout << add(20,20) << std::endl;
	std::cout << add(-10,10) << std::endl;
}
