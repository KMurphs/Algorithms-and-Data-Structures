// C++ program for Boggle game 
#include<bits/stdc++.h> 
using namespace std; 


int gcdExtended(int a, int b, int *x, int *y){
	if(a == 0){ *x = 0; *y = 1; return b; }
	int x1, y1, gcd = gcdExtended(b%a, a, &x1, &y1);
	*x = y1 - x1 * (b/a); *y = x1; return gcd;
}


// Find b such that a * b % m = 1
// 1 + km = ab or ab - km = 1
// gcdExtended is used to find b and k
int inverseModulo(int a, int m){
	a = a % m;
	int b, k, gcd = gcdExtended(a, m, &b, &k);
	if(gcd != 1) return INT_MAX;
	return (b%m + m)%m;
}


// Under the chinese remainder theorem, assuming that { nums[i] } are pair wise coprime
// We can find N such that N % nums[i] = rems[i]
// Formula N = sum( rems[i] * PI(nums[j]) * PI(nums[j])^-1(modulo nums[i]) ) 
// where j != i, and i,j go from 0 to length of nums and rems
int findNumByChineseRemainder(vector<int> nums, vector<int> rems){
	
	int product = 1;
	for(int i = 0 ; i < nums.size() ; i++) product *= nums[i];

	int N = 0, PI;
	for(int i = 0 ; i < nums.size() ; i++){
		PI = product / nums[i];
		N = N + (rems[i] * PI * inverseModulo(PI, nums[i]));
	}

	return N%product;
}




//Driver program to test above function 
int main() 
{ 
	
	assert(findNumByChineseRemainder({2, 3, 5}, {0, 0, 2}) == 12);
	assert(findNumByChineseRemainder({7, 5}, {5, 2}) == 12);
	assert(findNumByChineseRemainder({4, 9}, {0, 3}) == 12);


	cout << "Program exited successfully..." << endl;
	return 0; 
} 
