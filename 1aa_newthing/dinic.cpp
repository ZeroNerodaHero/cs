#include <iostream>
#include <queue>
using namespace std;

#define N 100

class dinic{
 public:
    dinic(int size){
        vsize = size;
        for(int i = 0; i < vsize; i++){
            for(int j = 0; j < vsize; j++){
                adj[i][j] = 0;
            }   
        }
    }
    
    void addEdge(int s, int e, int cap){
        adj[s][e] += cap;
    }

    bool bfs(int s,int t,int level[]){
        for(int i = 0; i < vsize; i++){
            level[i] = -1;
        }
        queue<int> q;
        q.push(s);
        level[s] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            //std::cout << u << ' ';
            for(int i = 0; i < vsize; i++){
                if(adj[u][i] && level[i] == -1){
                    q.push(i);
                    level[i] = level[u]+1;
                }
            }
        }
        return level[t] != -1;  
    }

    int blocking(int s, int t,int flow,int level[]){
        std::cout << s << "\t" << t << std::endl;
        if(s == t) return flow;
        for(int i = 0; i < vsize; i++){
            if(adj[s][i] && level[i] == level[s]+1){
                int tmpflow = std::min(flow,adj[s][i]);
                int pathflow = blocking(i,t,tmpflow,level);
                if(pathflow){
                    adj[s][i] -= pathflow;
                    adj[i][s] += pathflow;
                    return pathflow;
                }
            }
        }
        return 0;
    }

    int maxflow(int s, int t){
        int level[vsize];
        int flow = 0;
        while(bfs(s,t,level)){
            int pathflow = blocking(s,t,INT_MAX,level);
            while(pathflow > 0){    
                flow += pathflow;
                pathflow = blocking(s,t,INT_MAX,level);
            }
        }
        return flow;
    }
 private:
    int vsize;
    int adj[N][N];
};

int main(){
    dinic g(6);
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


