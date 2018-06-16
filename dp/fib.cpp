#include <iostream>

int fib1(int a){
    if(a <= 1) return 1;
    return fib(a-1) + fib(a-2);
}

#define SIZE 100
int ar[SIZE];

int fib2(int n){
    if(ar[n] != 0) return ar[n];
    ar[n] = fib2(n-1) + fib2(n-2);
    return ar[n];
}

int fib3(int n){
    int ar[n];
    ar[0] = 1; ar[1] = 1;

    for(int a = 2; a <= n; a++){
        ar[a] = ar[a-1] + ar[a-2];
    }
    return ar[n];
}
