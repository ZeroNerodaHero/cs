#include <iostream>

void hanoi(int n, char from, char to, char via,int &step){
	if(n == 1){
		step++;
		std::cout << step <<"-move " << n << " from " << from << " to " << to << std::endl;
		return;
	}
	hanoi(n-1,from,via,to,step);
	step++;
	std::cout << step <<"-move " << n << " from " << from << " to " << to << std::endl;
	hanoi(n-1,via,to,from,step);
}

int main(){
	int n = 0;
	hanoi(10,'A','B','C',n);
	return 0;
}
