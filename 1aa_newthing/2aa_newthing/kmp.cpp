#include <iostream>

void lps(char* pat, int b[]){
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
    int n = strlen(txt);
    int m = strlen(pat);
    int b[m+1];
    lps(pat,b);
    
    for(int i = 0, j = 0; i < n;){;
        while(j >= 0 && txt[i] != pat[j]){
            j = b[j];
        }
        i++; j++;
        if(j == m){
            std::cout << i - m << std::endl;
            j = b[j];
        }
    } 
}

int main(){
    char txt[] = "GEEKS FOR GEEKS";
    char pat[] = "GEEK";
    search(txt, pat);
    return 0;
}
