#include <iostream>
#include <list>
#include <stack>
#include <queue>
#define SIZE 20

class graph{
 public:
	graph(int size){
		vsize = size;
		for(int i = 0; i < vsize; i++){
			for(int j = 0; j < vsize; j++){
				adj[i][j] = 0;
			}
		}
		memset(indegree,0,sizeof(indegree));
		memset(visited,false,sizeof(visited));
	}
	
	void addEdge(int u, int v){
		adj[u][v] = 1;
		indegree[v]++;
	}
	
	void dfs(int u){
		visited[u] = true;
		for(int i = 0; i < vsize; i++){
			if(adj[u][i] && visited[i] == false) dfs(i);
		}
		st.push(u);
	}

	void topo(){
		for(int i = 0; i < vsize; i++){
			if(!visited[i]) dfs(i);
		}
		while(!st.empty()){
			std::cout << st.top() << ' ';
			st.pop();
		} std::cout << std::endl;
	}

	void topo2(){
		std::queue<int> q;	
		for(int i = 0; i < vsize; i++){
			if(indegree[i] == 0) q.push(i);
		}
		
		while(!q.empty()){
			int u = q.front();
			std::cout << u << ' ';
			q.pop();
			for(int i = 0; i < vsize; i++){
				if(adj[u][i]){
					indegree[i]--;
					if(indegree[i] == 0) q.push(i);
				}
			}
		} std::cout << std::endl;
	}

	void printarr(int arr[]){
		for(int i = 0; i < vsize; i++){
			std::cout << arr[i] << ' ';
		} std::cout << std::endl;
	}


    void dfs3(int arr[], int n = 0){
		if (n == vsize) {
             printarr(arr);
			return;
		}

        for(int i = 0; i < vsize; i++){
            if(indegree[i] == 0 && !visited[i]) {
        		visited[i] = true;
        		arr[n] = i;

            	for(int j = 0; j < vsize; j++){
                	if(adj[i][j]) indegree[j]--;
            	}
				
				dfs3(arr,n+1);

            	for(int j = 0; j < vsize; j++){
                	if(adj[i][j]) indegree[j]++;
            	}
        		visited[i] = false;
            }
        }
    }


	void alltop1(){
        int arr[SIZE];
        for(int i = 0; i < vsize; i++){
            visited[i] = false;
            indegree[i] = 0;
            for(int j = 0; j < vsize; j++){
                if(adj[j][i]) indegree[i]++;
            }
        }

		dfs3(arr);
    }

	void alltop(){
		int arr[SIZE];
		for(int i = 0; i < vsize; i++){
			visited[i] = false;
			indegree[i] = 0;
			for(int j = 0; j < vsize; j++){
				if(adj[j][i]) indegree[i]++;
			}
		}

		for(int i = 0; i < vsize; i++){
			if(indegree[i] == 0) dfs2(i,arr);
		}	
	}
	
	void dfs2(int u, int arr[], int n = 0){
		visited[u] = true;
		arr[n] = u;
		n++;
		if(n == vsize){
			 printarr(arr);
		} else{
			for(int i = 0; i < vsize; i++){
				if(adj[u][i]) indegree[i]--;
				if(!visited[i] && indegree[i] == 0) dfs2(i,arr,n);
			}
			for(int j = 0; j < vsize; j++){
				if(adj[u][j]) indegree[j]++;	
			}
		}
		visited[u] = false;	
	}
 private:
	int indegree[SIZE];
	int vsize; 
	int adj[SIZE][SIZE];	
	bool visited[SIZE];
	std::stack<int> st;
};

int main(){
	graph g(6);
	g.addEdge(5,2);
	g.addEdge(5,0);
	g.addEdge(4,0);
	g.addEdge(4,1);
	g.addEdge(2,3);
	g.addEdge(3,1);
	g.topo();
	g.topo2();
	std::cout << "-------------------------\n";
	g.alltop1();
	return 0;
}
