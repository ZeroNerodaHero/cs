#include <iostream>
#include <list>
#include <queue>
#include <stack>

class graph{
 public:
	graph(int somesize){
		Vsize = somesize;
		adj = new std::list<int>[Vsize];
	}

	void add_edge(int u, int v){
		adj[u].push_back(v);
	}
	
	void dfs(int u, bool visited[]){
		visited[u] = true;
		std::cout << "DFS Visited " << u << std::endl;
		for(auto it = adj[u].begin(); it != adj[u].end(); ++it){
			if(!visited[*it]) dfs(*it,visited);
		}	
	}

	void itdfs(int u){
		bool visited[Vsize];
        for(int i = 0; i < Vsize; ++i){
            visited[i] = false;
        }

		std::stack<int> s;
		s.push(u);
		visited[u] = true;

		while(!s.empty()){
			int v = s.top();
			s.pop();
			std::cout << "DFS(it) Visited: " << v << std::endl;
			for(auto it = adj[v].rbegin(); it != adj[v].rend(); it++){
				if(!visited[*it]){
					s.push(*it);
					visited[*it] = true;
				}
			}
		}
		std::cout << std::endl;
	}

	void bfs(int u){
		bool visited[Vsize];
		for(int i = 0; i < Vsize; ++i){
			visited[i] = false;
		}

		std::queue<int> q;
		q.push(u);
		visited[u] = true;
		
		while(!q.empty()){
			int v = q.front();
			q.pop();
			std::cout << "BFS Visited " << v << std::endl;
			for(auto it = adj[v].begin(); it != adj[v].end(); ++it){
				if(!visited[*it]){
					q.push(*it);
					visited[*it] = true;
				}
			}
		}
		std::cout << std::endl;
	}

	bool reachable(int u, int v){
		bool visited[Vsize];
		for(int i = 0; i < Vsize; i++){
			visited[i] = false;
		}

		std::queue<int> q;
		q.push(u);
		visited[u] = true;

		while(!q.empty()){
			if(q.front() == v) return true;
			for(auto it = adj[q.front()].begin(); it != adj[q.front()].end(); ++it){
				if(!visited[*it]){
					q.push(*it);
					visited[*it] = true;
				}
			}
			q.pop();
		}
		return false;		
	}
	
 private:
	int Vsize;
	std::list<int> *adj;
	
};

int main(){
	graph g(8);
	g.add_edge(0,1);
	g.add_edge(0,6);
	g.add_edge(1,2);
	g.add_edge(1,3);
	g.add_edge(2,3);
	g.add_edge(3,4);
	g.add_edge(3,6);
	g.add_edge(4,5);
	g.add_edge(6,7);
	g.add_edge(7,4);
	g.add_edge(7,5);

	bool ar[8] = {false};
	g.dfs(0,ar);
	g.bfs(0);
	g.itdfs(0);

	std::cout << "6->2: " << g.reachable(6,2) << std::endl;
	std::cout << "1->5: " << g.reachable(1,5) << std::endl;
	std::cout << "3->7: " << g.reachable(3,7) << std::endl;
	return 0;
}
