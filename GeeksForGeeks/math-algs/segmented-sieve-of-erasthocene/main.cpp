#include <bits/stdc++.h>
using namespace std;

vector<int> sieveOfErasthocene(int N){
  vector<int> primes;

  vector<bool> sieve;
  for(int i = 0; i <= N; i++)
    sieve.push_back(true);


  for(int i = 2; i <= N; i++){
    if(sieve[i]){
      primes.push_back(i);
      for(int j = i*i; j <= N; j = j + i){
        sieve[j] = 0;
      }
    }
  }
  
  return primes;
}


vector<int> getPrimesBelow(int N){
  
  int bSize = sqrt(N);
  vector<int> orPrimes = sieveOfErasthocene(bSize);
  vector<int> primes(orPrimes.begin(), orPrimes.end());
  

  int bStart = bSize;
  int bEnd = bStart + bSize;
  while(bStart < N){
    if(bEnd > N) bEnd = N;
    vector<bool> sieve(N, true);
    
    for(int i = 0; i < orPrimes.size(); i++){
      int inRangeMult = floor(bStart / orPrimes[i]) * orPrimes[i];
      if(inRangeMult < bStart) inRangeMult += orPrimes[i];

      for(int j = inRangeMult; j <= N; j = j + orPrimes[i])
        sieve[j] = 0;
    }

    for(int i = bStart; i < bEnd; i++)
      if(sieve[i])
        primes.push_back(i);

    bStart += bSize;
    bEnd = bStart + bSize;
  }


  return primes;
}



int main(){

  assert((sieveOfErasthocene(10)).size() == 4);

  int N = 10000;
  vector<int> primes = getPrimesBelow(N);

  // for(int i = 0; i < primes.size(); i++){
  //   cout << primes[i] << " ";
  // }


  assert(primes[1 - 1] == 2);
  assert(primes[10 - 1] == 29);
  assert(primes[100 - 1] == 541);
  assert(primes[1000 - 1] == 7919);

  cout << "\n\nProgram Exited successfully..." << endl;
  return 0;
}