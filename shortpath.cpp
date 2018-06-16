#include <iostream>
#include <stack>
#include <queue>
using namespace std;


#define N 9
#define INF 0X7F7F7F7F
int adj[N][N];

void add_edge(int u, int v, int dist = 1){
    adj[u][v] += dist;
    adj[v][u] += dist;
}


int minDist(int dist[], bool visited[]){
    int min = INF;
    int minindex;

    for(int i = 0; i < N-1; i++){
        if(dist[i] < min && !visited[i]){
            min = dist[i];
            minindex = i;
        }
    }
    return minindex;
}

void shortest(int src){
    int dist[N];
    memset(dist, 0x7F, sizeof(dist));
    bool visited[N];
    memset(visited,0, sizeof(visited));

    dist[src] = 0;
    for(int i = 0; i < N-1; i++){
        int u = minDist(dist, visited);
        visited[u] = true;
        for(int j = 0; j < N; j++){
            if(!visited[j] && adj[u][j] > 0 && dist[u]+adj[u][j] < dist[j]){
                dist[j] = dist[u]+adj[u][j];
            }
        }       
    }
    
    for(int i = 0; i < N; i++){
        std::cout << i << ' ' << dist[i] << std::endl;
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
    shortest(2);

    return 0;
}
