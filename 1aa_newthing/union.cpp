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

struct node{
    int y,weight;
    node(int y,int weight):y(y),weight(weight){};
};

vector<edge> e;

class graph{
 public:
    graph(int somesize){
        Vsize = somesize;
        adj = new std::list<node>[Vsize];
    }

    void add_edge(int u, int v,int weight){
        adj[u].push_back(node(v,weight));
        adj[v].push_back(node(u,weight));
        e.push_back(edge(u,v,weight));
    }       
    int size(){
        return Vsize;
    }
    int Vsize;
    std::list<node> *adj;
};

int find(int p[], int i){
    if(p[i] == -1) return i;
    return find(p,p[i]);
}

void Union(int p[],int i, int j){
    int pi = find(p,i);
    int pj = find(p,j);

    p[pi] = pj;
}

bool isCycle(int size){
    
    int parent[size];
    memset(parent,0xff,sizeof(parent));

    for(int i = 0; i < e.size(); i++){
        int u = find(parent, e[i].src);
        int v = find(parent, e[i].dst);
        if (u==v) return true;
        Union(parent, e[i].src, e[i].dst);
    }
    return false;
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

    bool an = isCycle(9);
    std::cout << "cycle: " << an << std::endl; 
    return 0;
}
