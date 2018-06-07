#include <iostream>

void search(char* txt, char* pat){
	int pathash = 0, txthash = 0;
	int m = strlen(pat), n = strlen(txt);
	for(int i = 0; i < m; i++){
		pathash	+= pat[i]%101;
		txthash += txt[i]%101;
	}
	if(pathash == txthash) std::cout << 0 << std::endl;
	for(int i = 1; i < n; i++){
		txthash += (txt[i+m]%101) -(txt[i]%101);
		if(pathash == txthash) std::cout << i << std::endl;
	}
}

int main(){
	char txt[] = "GEEKS FOR GEEKS";
    char pat[] = "GEEK";
	search(txt, pat);
	return 0;
}
