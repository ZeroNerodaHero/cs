#include <iostream>
#include <list>
#include <queue>
#include <stack>
using namespace std;

struct edge{
	int src,dst,weight;
	edge(int src,int dst,int weight):src(src),dst(dst),weight(weight){};
	bool operator <(const edge &o) const {
		return weight > o.weight;
	}
};
std::vector<edge> mst;


struct node{
	int y,weight;
	node(int y,int weight):y(y),weight(weight){};
};

class graph{
 public:
	graph(int somesize){
		Vsize = somesize;
		adj = new std::list<node>[Vsize];
	}

	void add_edge(int u, int v,int weight){
		adj[u].push_back(node(v,weight));
		adj[v].push_back(node(u,weight));
	}		
	int size(){
		return Vsize;
	}
	int Vsize;
	std::list<node> *adj;
};

void prim(graph &g){
	bool visited[g.size()];
	memset(visited,0,sizeof(visited));
	priority_queue<edge> q;

	for(auto i = g.adj[0].begin(); i != g.adj[0].end(); i++){
		q.push(edge(0,i->y,i->weight));
	}
	visited[0] = 1;
	while(!q.empty()){
		edge n = q.top();
		q.pop();

		if(visited[n.dst]){
			continue;
		}
		visited[n.dst] = 1;
		mst.push_back(n);
		for(auto i = g.adj[n.dst].begin(); i != g.adj[n.dst].end(); i++){
			if(!visited[i->y]){
				q.push(edge(n.dst,i->y,i->weight));
			}
		}
	}
}

void print(){
	for(int i = 0; i < mst.size(); i++){
		std::cout << mst[i].src << ' ' << mst[i].dst << ' '<< mst[i].weight << '\n'; 
	}
}

int main(){
	graph g(9);
	g.add_edge(0,1,4);
	g.add_edge(0,7,8);
	g.add_edge(1,7,11);
	g.add_edge(1,2,8);
	g.add_edge(2,8,2);
	g.add_edge(7,8,7);
	g.add_edge(7,6,1);
	g.add_edge(6,8,6);
	g.add_edge(6,5,2);
	g.add_edge(2,5,4);
	g.add_edge(2,3,7);
	g.add_edge(3,5,14);
	g.add_edge(3,4,9);
	g.add_edge(5,4,10);

	return 0;
}
