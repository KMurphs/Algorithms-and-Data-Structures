// C++ program for Boggle game 
#include<bits/stdc++.h> 
using namespace std; 


int gcd(int a, int b){
	if(a < b) return gcd(b, a);
	if(a % b == 0) return b;
	return gcd(b, a % b);
}




//Driver program to test above function 
int main() 
{ 
	// https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/
	assert(gcd(10, 15) == 5);
	assert(gcd(15, 10) == 5);
	assert(gcd(15, 1) == 1);
	assert(gcd(5, 3) == 1);
	assert(gcd(4, 2) == 2);

	cout << "Program exited successfully..." << endl;
	return 0; 
} 
