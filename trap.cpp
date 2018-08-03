#include <iostream>

void print(int ar[], int size){
    for(int i = 0; i < size; i++){
        std::cout << ar[i] << ' ';
    } std::cout << std::endl;
}

void countingsort(int ar[], const int size){
    int i0 = 0, i= 0, i2 = size-1;
    while(i <= i2){
        switch(ar[i]){
            case 0:
                std::swap(ar[i0],ar[i]);
                i0++;
                i++;
            case 1:
                i++;
            case 2:
                std::swap(ar[i2],ar[i]);
                i2--;
        }       
    }
    print(ar,size);
}

int main(){
    int ar[5] = {1,0,0,0,2};
    int size = sizeof(ar)/sizeof(ar[0]);
    countingsort(ar,size);
    return 0;
}
