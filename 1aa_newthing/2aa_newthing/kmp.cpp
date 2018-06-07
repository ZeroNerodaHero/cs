#include <iostream>

void lsp(char* pat, int b[]){
	int m = strlen(pat);
	int i = 0, j = -1;
	b[0] = -1;

	while(i < m){
		while(j >= 0 && pat[j] != pat[i]){
			j = b[j];
		}
		i++; j++;
		b[i] = j; 
	} 	
}

void search(char* txt, char* pat){
	int m = strlen(txt);
	int n = strlen(pat);
	int b[n];
	lsp(pat,b);
	
	for(int i = 0; i < m;){
		int j = 0;
		for(; j < n; j++){
			//std::cout << "i-\t" << i << "j-\t" << j << std::endl;
			while(j >= 0 && txt[i] != pat[j]){
				j = b[j];
			}
			i++;
			if(j == -1) break;
		}
		if(j == n) std::cout << i - n << std::endl;
	} 
}

int main(){
	char txt[] = "GEEKS FOR GEEKS";
    char pat[] = "GEEK";
	search(txt, pat);
	return 0;
}
