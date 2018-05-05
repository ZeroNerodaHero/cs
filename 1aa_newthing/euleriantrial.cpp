#include <iostream>
#include <queue>
#define N 10
using namespace std;
int adj[N][N];
int V;

void addedge(int u, int v){
	adj[u][v] = 1;
	adj[v][u] = 1;
}

void remedge(int u, int v){
	adj[u][v] = -1;
	adj[v][u] = -1;
}

int bfs_count(int u){
	bool visited[V];
	memset(visited,false,sizeof(visited));
	int count = 0;
	std::queue<int> q;
	q.push(u);
	visited[u] = true;
	while(!q.empty()){
		int n = q.front();
		q.pop();
		count++;		
		for(int i = 0; i < V; i++){
			if(adj[n][i] == 1 && !visited[i]){
				q.push(i);
				visited[i] = true;
			}
		}
	}	
	return count;
}

bool isbridge(int u, int v){
	int c1 = bfs_count(u);
	remedge(u,v);
	int c2 = bfs_count(u);
	addedge(u,v);
	return c1 > c2;		
}

bool isvalid(int u, int v){
	int deg = 0;
	for(int i = 0; i < V; i++){
		if(adj[u][i] == 1) deg++; 
	}

	
	if(deg == 1) return true;
	return !isbridge(u,v);
}

void dfs(int u){
	
	for(int i = 0; i < V; i++){
		if(adj[u][i] == 1 && isvalid(u,i)){
			remedge(u,i);
			std::cout << u << ' ' << i << std::endl;
			dfs(i);
		}
	}
}

void flueury(){
	int u = 0; int count = 0;
	for(int i = 0; i < V; i++){
		int deg = 0;
		for(int j = 0; j < V; j++){
			if(adj[i][j] == 1) deg++;
		}
		if(deg&1)  u = i,count++;
	}	
	if(count != 0 && count != 2) return;
	dfs(u);
}

int main(){
    V = 4;
    addedge(0, 1);
    addedge(0, 2);
    addedge(1, 2);
    addedge(2, 3);
	flueury();

	std::cout << "--------------------\n";
 
    V = 3;
    addedge(0, 1);
    addedge(1, 2);
    addedge(2, 0);
	flueury();

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
	flueury();
}
