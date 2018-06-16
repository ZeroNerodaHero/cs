#include <iostream>
#include <queue>
using namespace std;

#define MAXN 100
#define NIL 0
#define INF 9999
int U, V;
int adj[MAXN][MAXN];
int pairU[MAXN];
int pairV[MAXN];
int dist[MAXN];

void addEdge(int u, int v){
    adj[u][v] = 1;
}

bool bfs(){
    std::queue<int> q;
    for(int u = 1; u <= U; u++){
        if(pairU[u] == 0){
            dist[u] = 0;
            q.push(u);
        }
        else dist[u] = INF;
    }
    dist[NIL] = INF;
    while(!q.empty()){
        int u = q.front();
        q.pop();

        if(dist[u] < dist[NIL]){
            for(int v = 1; v <= V; v++){
                if(adj[u][v] == 1){
                    if(dist[pairV[v]] == INF){
                        dist[pairV[v]] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
        }
    }
    return dist[NIL] != INF;
}

bool dfs(int u){
    if(u == 0) return true;
    for(int v = 1; v <= V; v++){
        if(adj[u][v] && dist[pairV[v]] == dist[u] + 1){
            if(dfs(pairV[v])){
                pairV[v] = u;
                pairU[u] = v;
                return true;
            }
        }
    }
    dist[u] = INF;
    return false;
}

int hopKarp(){
    int maxedmatch = 0;
    while(bfs()){
        for(int u = 1; u <= U; u++){
            if(pairU[u] == 0 && dfs(u)){
                maxedmatch++;
            }
        }
    }
    return maxedmatch;
}

void print(){
    for(int u = 1; u <= U; u++){
        std::cout <<  u  << ' '<< pairU[u] << ":\n";
    }
    std::cout << std::endl;
    for(int v = 1; v <= V; v++){
        std::cout <<  pairV[v]  << ' '<< v << ":\n";
    }
}

int main(){
    U = 6; V = 6;
    addEdge(1,2);
    addEdge(1,3);
    addEdge(3,1);
    addEdge(3,4);
    addEdge(4,3);
    addEdge(5,3);
    addEdge(5,4);
    addEdge(6,6);
    std::cout << hopKarp() << std::endl;    
    print();
}

