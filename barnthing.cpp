#include <iostream>
#include <queue>
#include "pque.cpp"

#define N 10

void goto(int A, int arr[]){
    priority_queue<node> n;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            n.push(arr[i]);
        }
        
    }   
}

int main(){
    int arr[N][N];
    memset(arr,9999,sizeof(arr));
    arr[1][2] = 1;
    arr[1][4] = 4;
    arr[2][4] = 0;
    arr[2][3] = 6;
    arr[3][4] = 4;
    arr[3][6] = 2;
    arr[4][5] = 3;
    arr[5][6] = 1;
    

    return 0;
}
