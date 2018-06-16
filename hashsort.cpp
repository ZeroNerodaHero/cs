#include <iostream>

void heapfy(int arr[], int i, int size){
    int l = 2*i+1; int r = 2*i+2;
    int largest = i;
    if(l < size && arr[l] < arr[largest]){
        largest = l;
    }   
    if(r < size && arr[r] < arr[largest]){
        largest = r;
    }
    
    if(largest != i){
        std::swap(arr[largest],arr[i]);
        heapfy(arr, largest, size);
    }
}

void heapsort(int arr[], int size){
    while(size){
        for(int i = (size-2)/2; i >= 0; i--){
            heapfy(arr,i,size);
        }
        std::swap(arr[0], arr[size-1]); 
        size--;
    }   
}

void printarr(int arr[],int size){
    for(int i = 0; i < size; i++){
        std::cout << arr[i] << ' ';
    } std::cout << std::endl;
}

int main(){
    int arr[] = {7,4,9,32,7,4,2,10,0,1};
    int size = sizeof(arr)/sizeof(int);
    heapsort(arr,size);
    printarr(arr,size);
}
