#include <iostream>

int sum(int ar[], int SIZE, int i, int j){
	int sum = 0;
	for(int k = i; k <= j && k < SIZE; k++){
		sum += ar[k];
	} 
	return sum;
}

void update(int ar[], int i, int diff){
	ar[i] += diff;
} 

int main(){
	int ar[] = {1, 3, 5, 7, 9, 11};
	int n = sizeof(ar)/sizeof(ar[0]);
    printf("Sum of values in given range = %dn\n", 
            sum(ar, n, 1, 3));
 
    update(ar, 1, 10);
 
    printf("Updated sum of values in given range = %dn\n",
             sum(ar, n, 1, 3));
	return 0;
}
