#include <iostream>
#include <vector>
#include "stack.cpp"

	myStack<int> stk;
int steps(const std::vector<int> n){
	int max = 0; int x = 0;
	
	for(;x < n.size();){
		if(stk.empty() || n[stk.top()] <= n[x]){
			stk.push(x);
			x++;
		}
		else{
			if(max < (x-stk.top()) * n[stk.top()]) max = (x-stk.top()) * n[stk.top()];
			stk.pop();
		}

	}
	while(!stk.empty()){
		int m = n[stk.top()];
		stk.pop();
		if(stk.empty()){if(max < x * m) max = x*m;}
		else {
			if(max < (x-stk.top()-1) * m){ max = (x-stk.top()-1)*m;}}
	}
	return max;
}

int main(){
	std::cout << steps({2,1,5,6,2,3}) << std::endl;
}
