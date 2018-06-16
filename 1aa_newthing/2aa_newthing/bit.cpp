#include <iostream>
int bit[100];
void update(int i, int diff, int n);
void build(int ar[], int n){
    for(int i = 0; i < n; i++){
        update(i,ar[i],n);
    }       
}

void update(int i, int diff, int n){
    i++;
    while(i <= n){
        bit[i] += diff;
        i += (i&(-i));
    }
}

int query(int i){
    i++;
    int sum = 0;
    while(i > 0){
        sum += bit[i];
        i -= (i&(-i));
    }
    return sum;
}

int main(){
    int ar[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(ar)/sizeof(ar[0]);   

    build(ar,n);
    std::cout << (query(3)-query(0)) << std::endl;
    update(1,10,n);
    std::cout << (query(3)-query(0)) << std::endl;
    return 0;
}
