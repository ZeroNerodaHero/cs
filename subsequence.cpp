#include <iostream>

int dp[100];
int lis(int ar[],int length){
	dp[0] = 1;
	for(int i = 1; i < length; i++){
		for(int j = 0; j  < i; j++){
			if(ar[i] > ar[j]) dp[i] = std::max(dp[i],dp[j]+1);
		} 
	}
	int big = 0;
	for(int i = 0; i < length; i++){
		if(dp[i] > big) big = dp[i];
	}
	return big;
}

int main(){
	int ar[] = {3,10,2,1,20};
	std::cout << lis(ar,sizeof(ar)/sizeof(int)) << std::endl;
	return 0;
}
