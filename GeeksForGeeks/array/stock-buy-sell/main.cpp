#include <bits/stdc++.h>

using namespace std;




int tradeForMaxProfit(int *arr, int arraySize){

  vector<int> trades;
  int profit = 0;

  int prev, curr, next;
  for(int i = 0 ; i < arraySize ; i++){
    prev = i > 0 ? arr[i - 1] : INT_MAX;
    curr = arr[i];
    next = i < arraySize - 1 ? arr[i + 1] : INT_MIN;

    if(curr < prev && curr <= next){
      trades.push_back(i);
      profit = profit - arr[i];
    }
    if(curr > prev && curr >= next){
      trades.push_back(i);
      profit = profit + arr[i];
    }   
    
  }


  int tmpProfit = arr[trades[0]];
  for(int i = 0 ; i < trades.size() ; i++){
    if(i % 2 == 0) {
      tmpProfit = tmpProfit - arr[trades[i]];
      cout << "Buy  at day '" << trades[i] << "'. Profit: " << tmpProfit << endl; 
    }else{
      tmpProfit = tmpProfit + arr[trades[i]];
      cout << "Sell at day '" << trades[i] << "'. Profit: " << tmpProfit << endl; 
    }
  }

  return profit;
}







// https://www.geeksforgeeks.org/stock-buy-sell/
int main(int argc, char **argv, char **envp){

  
  int arrSize, *arr, exp;
  

  arrSize = 7, arr = new int[arrSize]{100, 180, 260, 310, 40, 535, 695}, exp = 865;
  assert(tradeForMaxProfit(arr, arrSize) == exp);


  cout << "Program Exited Successfully";
  return 0;
}