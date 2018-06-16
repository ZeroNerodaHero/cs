#include <iostream>
#include <queue>
using namespace std;

#define N 100

class fulk{
 public:
    fulk(int size){
        VSIZE = size;
        for(int i = 0; i < VSIZE; i++){
            for(int j = 0; j < VSIZE; j++){
                adj[i][j] = 0;
            }   
        }
    }
    
    void addEdge(int s, int e, int cap){
        adj[s][e] += cap;
    }

    bool bfs(int s,int t,int p[]){
        for(int i = 0; i < VSIZE; i++){
            p[i] = -1;
        }
        queue<int> q;
        q.push(s);
        p[s] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            //std::cout << u << ' ';
            if(u == t) return true;
            for(int i = 0; i < VSIZE; i++){
                if(adj[u][i] && p[i] == -1){
                    q.push(i);
                    p[i] = u;
                }
            }
        }
        return false;   
    }

    int augment(int s, int t, int parent[]){
        int flow = INT_MAX;
        int j = t;
        while(j != parent[j]){
            flow = std::min(flow,adj[parent[j]][j]); 
            j = parent[j];
        }
        j = t;
        while(j != parent[j]){
            adj[parent[j]][j] -= flow;
            adj[j][parent[j]] += flow;
            j = parent[j];
        }

        return flow;
    }

    int maxflow(int s, int t){
        int parent[VSIZE];
        int flow = 0;
        while(bfs(s,t,parent)){
            for(int i = 0; i < VSIZE; i++){
                flow += augment(s,t,parent);
            }
        }
        return flow;
    }
 private:
    int VSIZE;
    int adj[N][N];
};

int main(){
    fulk g(6);
    g.addEdge(0, 1, 16 );
    g.addEdge(0, 2, 13 );
    g.addEdge(1, 2, 10 );
    g.addEdge(1, 3, 12 );
    g.addEdge(2, 1, 4 );
    g.addEdge(2, 4, 14);
    g.addEdge(3, 2, 9 );
    g.addEdge(3, 5, 20 );
    g.addEdge(4, 3, 7 );
    g.addEdge(4, 5, 4);

    std::cout << g.maxflow(0,5) << std::endl;
}


