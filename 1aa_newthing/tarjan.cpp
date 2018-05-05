#include <iostream>
#include <list>
#include <stack>

#define SIZE 20

class graph{
 public:
	graph(int size){
		Vsize = size;
		for(int i = 0; i < Vsize; i++){
			for(int j = 0; j < Vsize; j++){
				adj[i][j] = 0;
			}
		}
		memset(visited,false,sizeof(visited));
	}
	
	void addEdge(int u, int v){
		adj[u][v] = 1;
	}

	void dfs(int v){
		static int order = 1;
		st.push(v);
		instack[v] = true;
		low[v] = disc[v] = order++;
		for(int i = 0; i < Vsize; i++){
			if(adj[v][i]){
				if(disc[i] == -1){
					dfs(i);
					low[v] = std::min(low[v],low[i]);
				} else{
					if(instack[i]) low[v] = std::min(low[v],disc[i]);
				}
			}
		}

		if(disc[v] == low[v]){
			while(!st.empty()){
				int u = st.top();
				st.pop();
				instack[u] = false;
				std::cout << u << ',';
				if(disc[u] == disc[v]) break; 
			} std::cout << std::endl;
		}		
	}

	void scc(){
		for(int i = 0; i < Vsize; i++){
			disc[i] = -1;
			low[i] = -1;
			instack[i] = false;
		}
		for(int x = 0; x < Vsize; x++){
			if(disc[x] == -1) dfs(x);
		}
	} 
 private:
	int Vsize;
	int low[SIZE];
	int disc[SIZE];
	int adj[SIZE][SIZE];	
	bool visited[SIZE];
	bool instack[SIZE];
	std::stack<int> st;
};

int main(){
	graph g4(11);
    g4.addEdge(0,1);g4.addEdge(0,3);
    g4.addEdge(1,2);g4.addEdge(1,4);
    g4.addEdge(2,0);g4.addEdge(2,6);
    g4.addEdge(3,2);
    g4.addEdge(4,5);g4.addEdge(4,6);
    g4.addEdge(5,6);g4.addEdge(5,7);g4.addEdge(5,8);g4.addEdge(5,9);
    g4.addEdge(6,4);
    g4.addEdge(7,9);
    g4.addEdge(8,9);
    g4.addEdge(9,8);
    g4.scc();

	std::cout << "------------------------------\n";

	graph g(11);
	g.addEdge(0,1);	
	g.addEdge(1,2);
	g.addEdge(2,3); g.addEdge(2,0); g.addEdge(2,4);
	g.addEdge(3,0);
	g.addEdge(4,5);
	g.addEdge(5,6); g.addEdge(5,7);
	g.addEdge(6,2); g.addEdge(6,4);
	g.addEdge(7,8);
	g.addEdge(8,5); g.addEdge(8,9);
	g.addEdge(9,5);
	g.addEdge(10,0);
	g.scc();

	return 0;
}
