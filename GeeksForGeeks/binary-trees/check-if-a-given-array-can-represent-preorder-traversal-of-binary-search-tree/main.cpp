#include <bits/stdc++.h>

using namespace std;




bool isPreOrderTraversalOfBST(int possiblePreOrderTraversal[], int l, int r){

  if(l >= r) return true;

  int root = possiblePreOrderTraversal[l];
  int pivot = l;

  int runner = l + 1;
  while(runner <= r && possiblePreOrderTraversal[runner] < root)
    runner++;

  pivot = runner, runner = runner + 1;
  while(runner <= r && possiblePreOrderTraversal[runner] > root)
    runner++;

  if(runner <= r && possiblePreOrderTraversal[runner] <= root)
    return false;


  return isPreOrderTraversalOfBST(possiblePreOrderTraversal, l + 1, pivot - 1) && isPreOrderTraversalOfBST(possiblePreOrderTraversal, pivot, r);
}




// https://www.geeksforgeeks.org/check-if-a-given-array-can-represent-preorder-traversal-of-binary-search-tree/
int main(int argc, char **argv, char **envp){
  
  int *arr = new int[3] { 2, 4, 3 };

  bool res = isPreOrderTraversalOfBST(arr, 0, 2);
  cout << "Given Array is " << (res ? "" : "NOT ") << "Pre Order Traversal of Binary Search Tree " << endl;

  assert(isPreOrderTraversalOfBST(arr, 0, 2) == true);

  arr = new int[3] {2, 4, 1};
  assert(isPreOrderTraversalOfBST(arr, 0, 2) == false);
  
  arr = new int[5] {40, 30, 35, 80, 100};
  assert(isPreOrderTraversalOfBST(arr, 0, 4) == true);

  cout << "Program Exited Successfully...";
  return 0;
}