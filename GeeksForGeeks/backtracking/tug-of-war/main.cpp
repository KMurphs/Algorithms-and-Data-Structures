#include <bits/stdc++.h>
using namespace std;


void partitionSubsets(int arr[], int arrSize, int *accountant, int counter, int *diff, int last_choice, int *solPartition){

  if(counter == 0){
    int sum1 = 0, sum2 = 0;
    // string part1 = "", part2 = "";
    for(int i = 0 ; i < arrSize ; i++){
      if(accountant[i] == 1){
        sum1 = sum1 + arr[i];
        // part1 = part1 + to_string(arr[i]) + " - ";
      }else{
        sum2 = sum2 + arr[i];
        // part2 = part2 + to_string(arr[i]) + " - ";
      }
    }
    int tmpDiff = sum1 - sum2;
    tmpDiff = tmpDiff < 0 ? 0 - tmpDiff : tmpDiff;
    if(tmpDiff < *diff){
      *diff = tmpDiff;
      // std::copy(std::begin(src), std::end(src), std::begin(dest));
      std::copy(accountant, accountant + arrSize, solPartition);
      // cout << "1: " << part1 << "(" << sum1 << ")" << endl;
      // cout << "2: " << part2 << "(" << sum2 << ")" << endl;
    }
    return;
  }


  if(counter >= 0){
    for(int i = last_choice + 1 ; i < arrSize ; i++){
      if(accountant[i] == 0){
        accountant[i] = 1;
        partitionSubsets(arr, arrSize, accountant, counter - 1, diff, i, solPartition);
        accountant[i] = 0;
      }
    }
  }

}





int tugOfWar(int arr[], int arrSize){

  sort(arr, arr + arrSize);

  int diff = INT_MAX;
  int *accountant = new int[arrSize];
  memset(accountant, 0, sizeof(int) * arrSize);
  int *solPartition = new int[arrSize];
  memset(solPartition, 0, sizeof(int) * arrSize);

  partitionSubsets(arr, arrSize, accountant, arrSize/2, &diff, -1, solPartition);

  cout << "Minimum difference After Partitions is: " << diff << endl;
  
  


  int sum1 = 0, sum2 = 0;
  string part1 = "", part2 = "";
  for(int i = 0 ; i < arrSize ; i++){
    if(solPartition[i] == 1){
      sum1 = sum1 + arr[i];
      part1 = part1 + to_string(arr[i]) + " - ";
    }else{
      sum2 = sum2 + arr[i];
      part2 = part2 + to_string(arr[i]) + " - ";
    }
  }

  cout << "1: " << part1 << "(" << sum1 << ")" << endl;
  cout << "2: " << part2 << "(" << sum2 << ")" << endl;
  return diff;
}



// https://www.geeksforgeeks.org/tug-of-war/
int main(){

    int *arr, n;

    #define ARRAY_SIZE(arr) ((sizeof(arr))/(sizeof(arr[0])))
    
    n = 11, arr = new int[n]{23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4}; 
    assert(tugOfWar(arr, n) == 1);

    n = 10, arr = new int[n]{3, 4, 5, -3, 100, 1, 89, 54, 23, 20}; 
    assert(tugOfWar(arr, n) == 0);

    cout << "Program is exiting..." << endl; 
    return 0; 
}