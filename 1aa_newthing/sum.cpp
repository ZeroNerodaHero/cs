#include <iostream>
bool dp[100][100];

/*
bool isSum2(int set[], int sum, int size){
    if(sum == 0) return true;
    if(size == 0) return false;

    if(set[size-1] > sum) return isSum2(set,sum,size-1);
    return isSum2(set,sum,size-1) || isSum2(set, sum-set[size-1], size-1);
}
*/

bool isSum(int set[], int sum, int size){
    dp[0][0] = true;
    for(int i = 1; i <= size; i++){
        for(int j = 0; j <= sum; j++){
            if(set[i] > sum) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j] || dp[i-1][j-set[i-1]];
        }
    }
    return dp[size][sum];
}

int main(){
    int set[] = {1,7,4,2,9,12,13};
    std::cout << isSum(set,9,7) << std::endl;   
    for(int i = 0; i <= 7; i++){
        std::cout << (i>0?set[i-1]:0) << '\t';
        for(int j = 0; j <= 9; j++){
            std::cout << dp[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

