// C++ program for Boggle game 
#include<bits/stdc++.h> 
using namespace std; 


int gcdExtended(int a, int b, int *x, int *y){
	if(a == 0) { *x = 0; *y = 1; return b; }
	int x1, y1, gcd = gcdExtended(b%a, a, &x1, &y1);
	*x = y1 - x1 * (b/a); *y = x1; return gcd;
}


// Return b such that (a * b) % m = 1
// b exists iif a and m are coprime
// 1 + km = ab or ab - km = 1
// this can solved using gcdExtended
int inverseModulo(int a, int m){
	a = a % m;

	int b, k, gcd = gcdExtended(a, m, &b, &k);
	if(gcd != 1) return INT_MAX;

	return ((b % m) + m) % m;
}




//Driver program to test above function 
int main() 
{ 
	assert(inverseModulo(11, 2) == 1);
	assert(inverseModulo(11, 5) == 1);
	assert(inverseModulo(11, 7) == 2);


	cout << "Program exited successfully..." << endl;
	return 0; 
} 
