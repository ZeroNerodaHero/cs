#include <map>
#include <array>
#include <fstream>
#include <iostream>
int psmthing(){
	std::ifstream fin("job.in");
	int d,p,c,f,s; int cost = 0;
	fin >> d; fin >> p; fin >> c; fin >> f; fin >> s;
	std::map<int,int[2]> paths;
	for(int i = 0; i < p; i++){
		int x, y;
		fin >> x;
		fin >> y;
		paths[i][0] = x;
		paths[i][1] = y;
	}

	for(auto i = paths.begin(); i != paths.end(); i++){
		if(i->second[0] == s){
			int pjet[c][c];
			memset(pjet,0,sizeof(pjet));
			for(int i = 0; i < f; i++){
				int x,y,money;
				fin >> x;
				fin >> y;
				fin >> money;
				pjet[x][y] = money;
			}
		
			for(auto i = paths.begin(); i != paths.end(); i++){
				cost -= pjet[i->second[0]][i->second[1]];
			}
			std::cout << cost << std::endl;	
			return cost + d*(p-1);
		}
	}
	return 0;
}

int main(){
	std::ofstream fout("job.out");
	fout << psmthing();
	return 0;
}	
