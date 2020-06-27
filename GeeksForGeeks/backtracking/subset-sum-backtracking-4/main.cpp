#include <bits/stdc++.h>

using namespace std;







int explore(int arr[], int arrSize, int target, int pos, int accum, vector<int> currSubset){
  
  if(accum > target)
    return 0;
  if(accum == target){
    for(vector<int>::iterator it = currSubset.begin() ; it != currSubset.end() ; ++it)
      cout << *it << "  ";
    cout << endl;
    return 1;
  }
    


  int subsets = 0;
  for(int i = pos ; i < arrSize ; i++){
    currSubset.push_back(arr[i]);
    if(explore(arr, arrSize, target, i + 1, accum + arr[i], currSubset) == 1)
      subsets++;
    currSubset.pop_back();
  }
  return subsets;

}





int findSubsetsToSum(int arr[], int arrSize, int target){

  sort(arr, arr + arrSize);
  for(int i = 0 ; i < arrSize ; i++)
    cout << arr[i] << "  ";
  cout << endl;

  vector<int> currSubset = *new vector<int>();
  
  return explore(arr, arrSize, target, 0, 0, currSubset);
}




// https://www.geeksforgeeks.org/subset-sum-backtracking-4/
int main(int argc, char **argv, char **envp){

  #define ARRAYSIZE(a) (sizeof(a))/(sizeof(a[0])) 

  int arr[] = {10, 7, 5, 18, 12, 20, 15}; 
  int arrSize = ARRAYSIZE(arr), target = 53; 

  assert(findSubsetsToSum(arr, arrSize, target) == 2);
  

  cout << "Program Exited Successfully";
  return 0;
}