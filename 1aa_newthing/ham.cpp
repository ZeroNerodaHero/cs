#include <iostream>
#include <queue>
#define N 10
using namespace std;
int adj[N][N];
bool dp[N][1<<N];
int V;

void addedge(int u, int v){
	adj[u][v] = 1;
	adj[v][u] = 1;
}

void remedge(int u, int v){
	adj[u][v] = -1;
	adj[v][u] = -1;
}

bool isCycle(){
	int vertex[V];
	for(int i = 0; i < V; i++){
		vertex[i] = i;
	} 

	do{
		int i;
		for(i = 0; i < V-1; i++){
			int u = vertex[i];
			int v = vertex[i+1];
			if(!adj[u][v]) break;
		}
		if(i == V-1){
			if(adj[vertex[i]][vertex[0]]){
				for(int j = 0; j < V; j++){
					std::cout << vertex[j] << ' ';
				} std::cout << std::endl;
				return true;
			}
		}
	} while(std::next_permutation(vertex,vertex+V));
	return false;
}

bool ham(bool visited[],int path[],int num){
	if(num == V){
		return adj[path[V-1]][path[0]]; 		
	}
	int u = path[num-1];
	for(int i = 0; i < V; i++){
		if(adj[u][i] && !visited[i]){
			path[num] = i;
			visited[i] = true;
			if(ham(visited,path,num+1)){
				return true;
			}
			visited[i] = false;  
		}
	}
	return false;
}

bool hasCycle(){
	bool visited[V];
	memset(visited,0,sizeof(visited));
	int path[V]; 
	for(int i = 0; i < V; i++){
		visited[i] = true;
		path[0] = i;
		if(ham(visited,path,1)){
			for(int j = 0; j < V; j++){
				std::cout << path[j] << ' ';
			} std::cout << std::endl;
			return true;
		}
		visited[i] = false;				
	}	

	return false;
}

bool dpCycle(){
	for(int i = 0; i < V; i++){
		dp[i][1<<i] = true;
	}	
	for(int i = 0; i < 1<<V; i++){
		for(int j = 0; j < V; j++){
			int x = 1 << j;
			if(i & x){ 
				int y = i ^ x;
				for(int k = 0; k < V; k++){
					if(k != j && dp[k][y] && adj[k][j]){
						dp[j][i] = true;
					}
				}
			} 
		}
	}

	for(int i = 0; i < 1<<V; i++){
		std::cout.width(3);
		std::cout << i;
	} std::cout << std::endl;
	
	for(int y = 0; y < V; y++){
		for(int x = 0; x < (1<<V); x++){
			std::cout.width(3);
			std::cout << dp[y][x];
		} std::cout << std::endl;
	}
	return true;
}

int main(){
    V = 4;
    addedge(0, 1);
    addedge(1, 2);
    addedge(2, 3);
    addedge(3, 1);
	dpCycle();
#if 0
    V = 4;
    addedge(0, 1);
    addedge(0, 2);
    addedge(1, 2);
    addedge(2, 3);
	std::cout << "isCycle(): " <<isCycle() << std::endl;
	std::cout << "dpCycle(): " <<dpCycle() << std::endl;

	std::cout << "--------------------\n";
 
    V = 3;
    addedge(0, 1);
    addedge(1, 2);
    addedge(2, 0);
	std::cout << "isCycle(): " <<isCycle() << std::endl;
	std::cout << "dpCycle(): " <<dpCycle() << std::endl;

	std::cout << "--------------------\n";
    
	V = 5;
    addedge(1, 0);
    addedge(0, 2);
    addedge(2, 1);
    addedge(0, 3);
    addedge(3, 4);
    addedge(3, 2);
    addedge(3, 1);
    addedge(2, 4);
	std::cout << "isCycle(): " <<isCycle() << std::endl;
	std::cout << "dpCycle(): " <<dpCycle() << std::endl;
#endif
	return 0;
}
