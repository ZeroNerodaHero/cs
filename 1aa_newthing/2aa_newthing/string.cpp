#include <iostream>
#define N_EVENT 128
int FSM[128][N_EVENT];


int transition(char *pat, int len, int state, char event){
    if(state < len && pat[state] == event){
        return state+1;
    }
    for(int i = state-1; i > 0; i--){
        if(pat[i-1] == event){
            int j = 0;
            for(; j < i-1; j++){
                if(pat[j] != pat[state-i+j+2]){
                    break;
                }
            }
            if(j == i-1) return i;              
        }
    }
    return 0;
}

void build_FSM(char* pat, int M){
    for(int i = 0; i <= M; i++){
        for(int j = 0; j < N_EVENT; j++){
            FSM[i][j] = transition(pat,M,i,j);
        }
    }
}

void search(char *pat, char* text){
    int M = strlen(pat);
    int N = strlen(text);
    int state = 0;
    build_FSM(pat,M);   
    
    for(int i = 0; i < N; i++){
        //state = transition(pat,M,state,text[i]);
        state = FSM[state][text[i]];
        if(state == M){
            std::cout << i << std::endl;
        }
    }
}

int main(){
    char txt[] = "GEEKS FOR GEEKS";
    char pat[] = "GEEK";
    search(pat,txt);
    return 0;
}
