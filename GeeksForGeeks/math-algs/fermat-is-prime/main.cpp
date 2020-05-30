// C++ program for Boggle game 
#include<bits/stdc++.h> 
using namespace std; 


int gcd(int a, int b){
	if(a < b) return gcd(b, a);
	if(a % b == 0) return b;
	return gcd(b, a%b);
}

int powerModulo(int a, int n, int m){
	int res = 1;
	a = a % m;

	while(n > 0){
		if(n & 1) res = (res * a)%m;
		n = n >> 1, a = (a * a)%m;
	}

	return res;
}


// According to fermat, n is prime if
// for all a in [1, n-1]:
// (a^p-1) % p = 1
// This is linked to the exponential modulo alg 
bool fermatIsPrime(int p, int retries){
	if(p <= 0) return 0;
	if(p <= 3) return 1;
	if(p <= 4) return 0;

	while(retries-- >= 0){
		int a = 2 + rand()%(p - 4);
		if(gcd(a, p) != 1) return 0;
		if(powerModulo(a, p - 1, p) != 1) return 0;
	}

	return 1;
}




//Driver program to test above function 
int main() 
{ 
	// https://www.geeksforgeeks.org/primality-test-set-2-fermet-method/
	assert(fermatIsPrime(1, 2) == 1);
	assert(fermatIsPrime(37, 5) == 1);
	assert(fermatIsPrime(22, 7) == 0);
	assert(fermatIsPrime(541, 7) == 1); //100th prime
	assert(fermatIsPrime(542, 7) == 0);


	cout << "Program exited successfully..." << endl;
	return 0; 
} 
