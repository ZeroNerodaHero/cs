#include <iostream>
#include <iomanip>
using namespace std;
void print_call_stack_frame(unsigned long int* start){
	start += 16;
	for(unsigned long int i = 0; i < 32; ++i){
		cout << setfill('0') << std::hex << start << " : ";
		cout << setfill('0') << std::hex << *start << std::endl;
		start--;
	}
}

void func2(unsigned long num){
	std::cout << "funct2\n";
}

void func1(unsigned long num){
	std::cout << "func1\t"<<num << std::endl;
}

void func0(unsigned long num){
	unsigned long x = 100;
	std::cout << "num address:\t" << &num << std::endl;
	std::cout << "x address:\t" << &x << std::endl;
	std::cout << "func0\n";
	print_call_stack_frame(&x);
	func1(num);
}

int main(){
	std::cout << "func0\t\taddress:\t" << (void*)func0 << std::endl;
	std::cout << "func1\t\taddress:\t" << (void*)func1 << std::endl;
	std::cout << "func2\t\taddress:\t" << (void*)func2 << std::endl;
	func0(2);
}
