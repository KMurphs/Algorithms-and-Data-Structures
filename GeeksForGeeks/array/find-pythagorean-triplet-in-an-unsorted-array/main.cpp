#include <bits/stdc++.h>

using namespace std;




bool isTherePythagorianTriplets(int *arr, int arrSize){

  //https://www.geeksforgeeks.org/c-qsort-vs-c-sort/
  sort(arr, arr + arrSize); // sort takes an optional comparator
  // sort(begin(arr), end(arr)); // not working, it needs: int v[2000]; std::sort(std::begin(v), std::end(v));

  int l, r, lrsqr;
  for(int h = arrSize - 1, hsqr = h*h ; h >= 2; h--){
    l = 0, r = h - 1, hsqr = arr[h]*arr[h];
    

    while(l < r){
      lrsqr = arr[l]*arr[l] + arr[r]*arr[r];
      if(lrsqr < hsqr) 
        l++;
      else if(lrsqr > hsqr) 
        r--;
      else 
        return true;
    }

    
  }

  return false;
}




// https://www.geeksforgeeks.org/find-pythagorean-triplet-in-an-unsorted-array/
int main(int argc, char **argv, char **envp){

  int arrSize, *arr;
  bool exp;
  

  arrSize = 5, arr = new int[arrSize]{3, 1, 4, 6, 5}, exp = true;
  assert(isTherePythagorianTriplets(arr, arrSize) == exp);

  arrSize = 5, arr = new int[arrSize]{10, 4, 6, 12, 5}, exp = false;
  assert(isTherePythagorianTriplets(arr, arrSize) == exp);


  cout << "Program Exited Successfully";
  return 0;
}