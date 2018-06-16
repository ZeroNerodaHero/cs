#include <iostream>

void findsubbrute(char* text, char* pattern){
    int n = strlen(text);
    int m = strlen(pattern);
    for(int i = 0; i < n; i++){
        int j = 0;
        for(; j < m; j++){
            if(text[i+j] != pattern[j]){
                break;
            }
        }
        if(j == m) std::cout << i << std::endl;
    }
}

int main(){
    char txt[] = "GEEKS FOR GEEKS";
    char pat[] = "GEEK";
    findsubbrute(txt, pat);
    return 0;
}
