#include <bits/stdc++.h>
using namespace std;




vector<int> getPrimesBelow(int N){
  vector<int> primes;
  
  vector<bool> sieve;
  for(int i = 0; i <= N; i++){
    sieve.push_back(true);
  }

  for(int i = 2; i <= N; i++){
    if(sieve[i]){
      primes.push_back(i);
      for(int j = i*i; j <= N; j = j + i){
        sieve[j] = false;
      }
    }
  }

  return primes;
}



int main(){

  int N = 100;
  vector<int> primes = getPrimesBelow(N);

  for(int i = 0; i < primes.size(); i++){
    cout << primes[i] << " ";
  }

  cout << "\n\nProgram Exited successfully..." << endl;
  return 0;
}