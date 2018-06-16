#include <iostream>

int biggest(int ar[],int size){
    int biggest = 0, bigi = 0, bigj = 0;
    for(int i = 0; i < size; i++){
        for(int j = i; j < size; j++){
            if((ar[i]^ar[j]) > biggest){
                biggest = (ar[i]^ar[j]);
                bigi = ar[i];
                bigj = ar[j];
            } 
        }
    }
    std::cout << bigi << ' ' << bigj << std::endl;
    return biggest;
}

int main(){
    int ar[] = {12, 15, 5, 1, 7, 9, 8, 6, 10, 13};
    int size = sizeof(ar)/sizeof(int);
    std::cout << biggest(ar,size) << std::endl;
    return 0;
}
