#include <iostream>

int modp(int b, int p, int n){
	int t = 1;;
	for(int i = 0; i < p; i++){
		t = (t * b)%n;
	}
	return t;
}

int gcd(int a, int b){
	if(a%b == 0) return b;
	return gcd(b,a%b);
}

int lcm(int a, int b){
	return (a * b)/gcd(a,b);
}

int e, d, n;

int encrypt(int m){
	return modp(m,e,n);
}

int decrypt(int m){
	return modp(m,d,n);
}

int main(){
	int p = 17;
	int q = 47;
	n = p * q;
	int tot = lcm((p-1),(q-1));
	for(e = 7; e < tot; e++){
		if(gcd(e,tot) == 1) break;
	}

	for(d = 2; d < tot; d++){
		if((e*d)%tot == 1) break;	
	}

	std::cout << "n- " << n << "\ne- "<< e 
			  << "\nd- " << d << std::endl;

	for(int i = 100; i < 110; i++){
		int enc = encrypt(i);
		int dec = decrypt(enc);
		std::cout << i <<" Enc: " << enc << "\tDec: "<< dec << std::endl;
	}

	return 0;
}
