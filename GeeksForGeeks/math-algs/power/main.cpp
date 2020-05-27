// C++ program for Boggle game 
#include<bits/stdc++.h> 
using namespace std; 


int power(int x, int n){
	int res = 1;

	while(n > 0){
		if(n & 1) res = res * x;
		n = n>>1, x = x * x;
	}

	return res;
}




//Driver program to test above function 
int main() 
{ 
	assert(power(2, 1) == 2);
	assert(power(3, 4) == 81);

	cout << "Program exited successfully..." << endl;
	return 0; 
} 
