// C++ program for Boggle game 
#include<bits/stdc++.h> 
using namespace std; 


int gcdExtended(int a, int b, int *x, int *y){

	if(a == 0){ *x = 0; *y = 1; return b; }
	int x1, y1, gcd = gcdExtended(b%a, a, &x1, &y1);
	*x = y1 - x1 * (b/a); *y = x1; return gcd;

}




//Driver program to test above function 
int main() 
{ 
	// https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/
	int x, y;
	assert(gcdExtended(10, 15, &x, &y) == 5);
	assert(gcdExtended(15, 10, &x, &y) == 5);
	assert(gcdExtended(15, 1, &x, &y) == 1);
	assert(gcdExtended(5, 3, &x, &y) == 1);

	cout << "Program exited successfully..." << endl;
	return 0; 
} 
