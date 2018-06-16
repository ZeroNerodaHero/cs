#include <iostream>
#include <list>
#include <stack>

#define SIZE 20

class graph{
 public:
    graph(int size){
        Vsize = size;
        for(int i = 0; i < Vsize; i++){
            for(int j = 0; j < Vsize; j++){
                adj[i][j] = 0;
            }
        }
        memset(visited,false,sizeof(visited));
    }
    
    void add_edge(int u, int v){
        adj[u][v] = 1;
    }

    void transpose(){
        for(int x = 0; x < Vsize; x++){
            for(int y = 0; y < Vsize; y++){
                adj1[y][x] = adj[x][y];
            }
        }   
    }

    void dfs1(int v){
        visited[v] = true;
        for(int x = 0; x < Vsize; x++){
            if(!visited[x] && adj[v][x]){
                dfs1(x);
            }  
        }
        st.push(v);
    }

    void dfs2(int v){
        visited[v] = true;
        std::cout << v << ' ';
        for(int i = 0; i < Vsize; i++){
            if(!visited[i] && adj1[v][i]) dfs2(i);
        }       
    }

    void scc(){
        for(int x = 0; x < Vsize; x++){
            if(!visited[x]) dfs1(x);
        }
        transpose();
        for(int i = 0; i < Vsize; i++){
            visited[i] = false;
        }
        while(!st.empty()){
            int u = st.top();
            st.pop();
            if(!visited[u]) dfs2(u);
            std::cout << std::endl;
        }
        std::cout << std::endl;
    } 
 private:
    int Vsize;
    int adj[SIZE][SIZE];    
    int adj1[SIZE][SIZE];       
    bool visited[SIZE];
    std::stack<int> st;
};

int main(){
    graph g(5);
    g.add_edge(0,2);
    g.add_edge(2,1);
    g.add_edge(1,0);
    g.add_edge(0,3);
    g.add_edge(3,4);
    
    g.scc();

    return 0;
}
