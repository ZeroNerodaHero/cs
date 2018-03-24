#include <iostream>
#include <algorithm>
#include <ctime>
#define MAXN 100

int knap(int w[],int v[],int n,int weight){
	if(n == 0) return 0;
	if(w[n-1] > weight) return knap(w,v,n-1,weight);
	return std::max(knap(w,v,n-1,weight-w[n-1])+v[n-1], knap(w,v,n-1,weight));
}

int dp[MAXN][MAXN];
int knapsack(int w[],int v[],int n,int weight){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= weight; j++){
			if(w[i-1] > weight){
				dp[i][j] = dp[i-1][j];
			} else{
				dp[i][j] = std::max(dp[i-1][j-w[i-1]]+v[i-1],dp[i-1][j]);
			}
		}
	}
	return dp[n][weight];
}

int main(){
	int v[3] = {60,100,120};
	int w[3] = {10,20,30};
	clock_t t = clock();
	std::cout << knap(w,v,3,50) << std::endl;
	std::cout << (clock() - (float)t)/CLOCKS_PER_SEC << std::endl;

	t = clock();
	std::cout << knapsack(w,v,3,50) << std::endl;
	std::cout << (clock() - (float)t)/CLOCKS_PER_SEC << std::endl;
	return 0;
}
