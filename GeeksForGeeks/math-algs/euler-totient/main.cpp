#include <bits/stdc++.h>

using namespace std;

// Totient Function of N
// count of number n:
// 1. n < N
// 2. (n, N) are coprime i.e. gcd(n, N) = 1

// Brute force approach would be to iterate through everything below N,
// and check gcd of i and N
// if gcd is 1, increment res (which will eventually become the totient value for N)

// Euler's Formula
// phi(N) = N * PI((p - 1)/p)
// where p are all the primes that divide N

vector<int> getPrimeFactors(int N){
  vector<int> primeFactors;

  if(N % 2 == 0){
    while(N % 2 == 0) N /= 2;
    primeFactors.push_back(2);
  }

  for(int i = 3; i <= sqrt(N); i = i + 2){
    if(N % i == 0){
      while(N % i == 0) N /= i;
      primeFactors.push_back(i);
    }
  }

  if(N != 1){
    primeFactors.push_back(N);
  }

  return primeFactors;
}

int totient(int N){
  vector<int> factors = getPrimeFactors(N);
  int res = N;
  for(int i = 0 ; i < factors.size(); i++){
    res *= (factors[i] - 1)/((float)factors[i]);
  }
  return res;
}

int main(){

  vector<int> factors = getPrimeFactors(10);
  assert(factors.size() == 2); 
  assert(factors[0] == 2); 
  assert(factors[1] == 5); 

  assert(totient(10) == 4); // 1 3 7 9

  cout << "\n\nProgram Exited Sucessfully..." << endl;
  return 0;
}