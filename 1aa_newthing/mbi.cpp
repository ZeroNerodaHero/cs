#include <iostream>

#define MAXN 100

int adj[MAXN][MAXN];
int N, M;
void addEdge(int a, int b){
	adj[a][b] = 1;
}

bool bpm(int n, bool matched[],int matches[]){
	for(int i = 0; i < N; i++){
		if(adj[n][i] == 1){
			if(matches[i] == -1){
				matches[i] = n;
				return true;
			}
			else{
				if(!matched[i]){
					matched[i] = true;
					if(bpm(matches[i],matched,matches)){	
						matches[i] = n;
						return true;
					}	
				}
			}		
		}
	}
	return false;
}

int amaximum(){
	int maxi = 0;
	bool matched[N];
	int matches[N];
	memset(matches,-1,sizeof(matches));
	for(int i = 0; i < M; i++){
		memset(matched,0,sizeof(matched));
		if(bpm(i,matched,matches)){
			maxi++;
		}
	}
	return maxi;
}

int main(){
	M = 2; N = 2;
	addEdge(0,0);
	addEdge(1,0);
	addEdge(0,1);
	std::cout << amaximum() << std::endl;	
}
