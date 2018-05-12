#include <iostream>
#include <queue>
#define MAXN 100
int adj[MAXN][MAXN];
int r[MAXN][MAXN];
int V;

void addEdge(int i, int j, int weight){
	adj[i][j] = weight;
}

bool bfs(int s,int t,int parent[]){
	for(int i = 0; i < V; i++){
		parent[i] = -1;
	}
	std::queue<int> q;
	q.push(s);
	parent[s] = 0;
	while(!q.empty()){
		int n = q.front();
		q.pop();
		for(int i = 0; i < V; i++){
			if(r[n][i] && parent[i] == -1){
				q.push(i);
				parent[i] = n;
			}
		}
	}
	std::cout << "pass1\n";
	return parent[t] != -1;
}

int res(int s, int t){
	for(int i = 0; i < V; i++){
		for(int j = 0; j < V; j++){
			r[i][j] = adj[i][j];
		}
	}
	int parent[V];
	int maxflow = 0;
	while(bfs(s,t,parent)){
		int minflow = 9999;
		int i, j;
		for(j = t; j != s; j = i){
			i = parent[j];
			std::cout << i << ' ' << j << "\tpass3\n";
			minflow = std::min(minflow,r[i][j]); 
		}
		for(j = t; j != s; j = i){
            i = parent[j];
			r[i][j] -= minflow;
			r[j][i] += minflow;
        }
		maxflow += minflow;
		std::cout << minflow << "\tpass2\n";
	}
	return maxflow;
}

void dfs(int c, bool visited[]){
	visited[c] = true;
	for(int i = 0; i < V; i++){
		if(r[c][i] != 0 && !visited[i]){
			dfs(i,visited);
		}
	}
}

void mincut(){
	res(0,V-1);
	std::cout <<  "er0\n";	
	bool visited[V];
	memset(visited,false,sizeof(visited));

	dfs(0,visited);
	for(int i = 0; i < V; i++){
		for(int j = 0; j < V; j++){
			if(visited[i] && !visited[j] && adj[i][j]){
				std::cout << i << ' ' << j << ' ' << adj[i][j] << std::endl;
			}
		}
	}
}

int main(){
	V = 6;
	addEdge(0,1,16);
	addEdge(0,2,13);
	addEdge(1,2,10);
	addEdge(1,3,12);
	addEdge(2,1,4);
	addEdge(2,4,14);
	addEdge(3,2,9);
	addEdge(3,5,20);
	addEdge(4,3,7);
	addEdge(4,5,4);


	mincut();	
	return 0;
}
