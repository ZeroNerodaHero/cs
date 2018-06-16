#include <iostream>
#include <stack>
#include <queue>
using namespace std;


#define N 10
int adj[N][N];

void add_edge(int u, int v, int dist = 1){
    adj[u][v] += dist;
}

void dfs(int u){
    bool visited[N];
    memset(visited,0,sizeof(visited));

    stack<int> s;
    s.push(u);
    visited[u] = true;

    while(!s.empty()){
        u = s.top();
        s.pop();
        std::cout << "DFS->" << u << std::endl;
        for(int i = N-1; i >= 0; i--){
            if(!visited[i] && adj[u][i]){
                s.push(i);
                visited[i] =true;
            }
        }
    }
}

void bfs(int u){
    bool visited[N];
    memset(visited,0,sizeof(visited));
        
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while(!q.empty()){
        int v = q.front();
        q.pop();
        std::cout << "BFS->" << v << std::endl;
        for(int i = 0; i < N; i++){
            if(visited[i] == false && adj[v][i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void print(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            std::cout << adj[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main(){
    add_edge(0,1);
    add_edge(0,6);
    add_edge(1,2);
    add_edge(1,3);
    add_edge(2,3);
    add_edge(3,4);
    add_edge(3,6);
    add_edge(4,5);
    add_edge(6,7);
    add_edge(7,4);
    add_edge(7,5);  

    print();    
    bfs(0);
    std::cout << std::endl;
    dfs(0);

    return 0;
}
