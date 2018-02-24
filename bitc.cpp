#include <iostream>

void printbit(int x){
	if(x==0) return;
	printbit(x >> 1);
	if(x%2==0) std::cout << '0';
	else std::cout << '1'; 
}

void printbin(int x){
	for(int i = sizeof(int)*8-1; i >= 0; i--){
		int n = 1<<i;
		if((x&n) == 0) std::cout << '0';
		else std::cout << '1';
	}
	std::cout << std::endl;
}

void changebit(int a, int b, int x){
	int mask = (1<<(b-a))-1;
	mask <<= a;
	int	y = x|mask;
	printbit(y); std::cout << '\n';
	y = x&(~mask);
	printbit(y); std::cout << '\n';
	y=x^mask;
	printbit(y); std::cout << '\n';
}

int main(){
	int y =74;
	printbit(y); std::cout << '\n';
	changebit(1,5,y);
	return 0;
} 
