#include <iostream>
#include <string>
#include <algorithm>

int lcstr(std::string x, std::string y){
	if(x.length() == 0 || y.length() == 0) return 0;
	if(x[x.length()-1] != y[y.length()-1]) return std::max(lcstr(x.substr(0,x.length()-1), y),lcstr(y.substr(0,y.length()-1), x));
	return 1+lcstr(x.substr(0,x.length()-1), y.substr(0,y.length()-1));
}

int lcstring(std::string x, std::string y){
	int n = x.length(); int m = y.length();
	int arr[n+1][m+1];
	for(int i = 0; i <= n; i++){
		arr[i][0] = 0;
	}

    for(int i = 0; i <= m; i++){
        arr[0][i] = 0;
    }

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(x[i] == y[j]){
				arr[i][j] = arr[i-1][j-1]+1;
			} else{
				arr[i][j] = std::max(arr[i-1][j],arr[i][j-1]);
			}
		} 
	}
	return arr[n][m];
}

int main(){
	std::cout << lcstring("ABCDGH","AEDFHR") << std::endl;
	std::cout << lcstring("AGGTAB","GXTXAYB") << std::endl;
	return 0;
}
