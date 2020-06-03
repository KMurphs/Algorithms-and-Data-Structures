#include <bits/stdc++.h>

using namespace std;



void backTracking(vector<vector<int>>& sols, vector<int>& currSol, int *arrA, int arrASize, int *arrB, int arrBSize, int threshold, int lastA, int lastB){

  // Resolve backtracking calls
  sols.push_back(currSol);


  // Choose a arrA value above current threshold
  int iA = lastA;
  while(iA < arrASize && arrA[iA] < threshold) iA++;
  for(int i = iA; i < arrASize; i++){
    currSol.push_back(arrA[i]);

    // Choose a arrB value above current arrA value chosen
    int iB = lastB;
    while(iB < arrBSize && arrB[iB] < arrA[i]) iB++;
    for(int j = iB; j < arrBSize; j++){
      currSol.push_back(arrB[j]);

      // Backtracking call with threshold set as curr arrB value chosen
      backTracking(sols, currSol, arrA, arrASize, arrB, arrBSize, arrB[j], i, j);


      // Undoing backtracking choices on arrB
      currSol.pop_back();
    }

    // Undoing backtracking choices on arrA
    currSol.pop_back();
  }
}




vector<vector<int>> generateSortedArrays(int *arrA, int arrASize, int *arrB, int arrBSize){

  vector<vector<int>> sols;
  vector<int> currSol;

  backTracking(sols, currSol, arrA, arrASize, arrB, arrBSize, INT_MIN, 0, 0);



  // Print Solution
  for(int i = 0; i < sols.size(); i++){
    cout << endl;
    for(int j = 0; j < sols[i].size(); j++){
      cout << sols[i][j] << " ";
    }
    cout << endl;
  }

  return sols;
}




// https://www.geeksforgeeks.org/convert-array-into-zig-zag-fashion/
// a < b > c < d > e < f
int main(int argc, char **argv, char **envp){

  
  int arrASize, *arrA, arrBSize, *arrB;
  


  arrASize = 3, arrA = new int[arrASize]{10, 15, 25}, arrBSize = 4, arrB = new int[arrBSize]{1, 5, 20, 30};
  generateSortedArrays(arrA, arrASize, arrB, arrBSize);
  // for(int i = 1; i < arrSize; i++){
  //   if(checkWith_LessThan) assert(arr[i - 1] < arr[i]);
  //   else assert(arr[i - 1] > arr[i]);
  //   checkWith_LessThan = !checkWith_LessThan;
  // }





  cout << "Program Exited Successfully";
  return 0;
}