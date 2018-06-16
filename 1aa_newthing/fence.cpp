/*
ID: wzhang11
TASK: fence
LANG: C++11
*/


#include <iostream>
#include <queue>
#include <fstream>
#include <stack>
#define N 501
using namespace std;

std::ofstream out("fence.out");
std::stack<int> st;
int adj[N][N];
int V;

void addedge(int u, int v){
    adj[u][v] += 1;
    adj[v][u] += 1;
}

void remedge(int u, int v){
    adj[u][v] -= 1;
    adj[v][u] -= 1;
}

void circuit(int u){
    for(int v = 1; v <= V; v++){
        if(adj[u][v] > 0){
            remedge(u,v);
            circuit(v); 
        }   
    }
    st.push(u);
} 

void findcircuit(){
    int current = 1;
    for(int i = 1; i <= V; i++){
        int deg = 0;
        for(int j = 1; j <= V; j++){
            if(adj[i][j] > 0) deg+=adj[i][j];
        }
        if(deg&1){
            current = i;
            break;
        }
    }
    circuit(current);
    while(!st.empty()){
        out << st.top() << '\n';
        st.pop();
    }
}

int main(){
    std::ifstream in("fence.in");

    int fences;
    in >> fences;

    for(int i = 0; i < fences; i++){
        int x, y;
        in >> x >> y;
        addedge(x,y);
        if(x > V) V = x;
        if(y > V) V = y;
    }
    findcircuit();

    in.close(); out.close();
    return 0;
}
