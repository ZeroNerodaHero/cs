#include <iostream>
#include <iomanip>
#include <stack>
#include <queue>
using namespace std;
#define N 9
#define INF 0X1F1F1F1F
int adj[N][N];

struct node{
    int dist;
    int id;
    bool operator <(const node &o) const{
        return dist > o.dist;
    } 

    node(int dist,int id): dist(dist), id(id) {}
};

void add_edge(int u, int v, int dist = 1){
    adj[u][v] += dist;
    adj[v][u] += dist;
}

void dijkstra(int src){
    int dist[N];
    memset(dist, 0x1F, sizeof(dist));
    bool visited[N];
    memset(visited,0, sizeof(visited));
    priority_queue<node> q;
    node n(0, src);
    q.push(n);
    dist[src] = 0;

    while(!q.empty()){
        n = q.top();
        int u = n.id;
        q.pop();
        std::cout << u << std::endl;
        visited[n.id] = 1;
        for(int j = 0; j < N; j++){
            if(!visited[j] && adj[u][j] > 0 && dist[u]+adj[u][j] < dist[j]){
                dist[j] = dist[u]+adj[u][j];
                q.push(node(dist[j],j));            
            }
        }
    }

    for(int i = 0; i < N; i++){
        std::cout << i << ' ' << dist[i] << std::endl;
    }
}

void warshall(){
    int d[N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j) d[i][j] = 0;
            else if(adj[i][j] > 0) d[i][j] = adj[i][j];
                 else d[i][j] = INF;
        }
    }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
    for(int k = 0; k < N; k++){
                if((d[i][k] + d[k][j]) < d[i][j]) d[i][j] = d[i][k] + d[k][j];
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            std::cout.width(2);
            std::cout << d[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl; 
}

void print(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            std::cout.width(2);
            std::cout << adj[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main(){
    add_edge(0,1,4);
    add_edge(0,7,8);    
    add_edge(1,7,11);   
    add_edge(1,2,8);    
    add_edge(7,8,7);    
    add_edge(7,6,1);    
    add_edge(2,8,2);    
    add_edge(6,8,6);    
    add_edge(2,5,4);    
    add_edge(6,5,2);    
    add_edge(2,3,7);    
    add_edge(3,5,14);   
    add_edge(3,4,9);    
    add_edge(5,4,10);   

    print();    
    dijkstra(0);
    warshall();
    return 0;
}
