// C++ program for Boggle game 
#include<bits/stdc++.h> 
using namespace std; 


int powerModulo(int a, int n, int m){
	int res = 1;
	a = a % m;

	while(n > 0){
		if(n & 1) res = (res * a)%m;
		n = n >> 1, a = (a * a)%m;
	}

	return res;
}




//Driver program to test above function 
int main() 
{ 

	assert(powerModulo(3, 4, 7) == 4);
	assert(powerModulo(2, 10, 2) == 0);

	cout << "Program exited successfully..." << endl;
	return 0; 
} 
