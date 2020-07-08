#include <bits/stdc++.h>

using namespace std;



bool charToBoolean(char a){
  if(a == 'T' || a == 't') return true;
  return false;
}
bool evaluate(bool a, bool b, char op){
  switch (op) {
    case '^':
      return a ^ b;
    case '&':
      return a & b;
    case '|':
      return a | b;
    default:
      return false;;
  }
  return false;
}
struct TSol{
  int T, N;
  vector<string> expressions;
  TSol(): T(0), N(0), expressions(*new vector<string>()){}
};
TSol solve(char *syms, char *ops, int n, int start, int end){
  
  if(start == end) {
    TSol res = *new TSol();
    res.T = charToBoolean(syms[start]) ? 1 : 0;
    res.N = 1 - res.T;
    res.expressions.push_back(*new string(1, syms[start]));
    return res;
  }


  TSol sol = *new TSol();
  for(int i = start ; i < end ; i++){
    TSol r1 = solve(syms, ops, n, start, i);
    TSol r2 = solve(syms, ops, n, i + 1, end);

    sol.T += evaluate(1, 1, ops[i]) ? r1.T * r2.T : 0;
    sol.T += evaluate(1, 0, ops[i]) ? r1.T * r2.N : 0;
    sol.T += evaluate(0, 1, ops[i]) ? r1.N * r2.T : 0;
    sol.T += evaluate(0, 0, ops[i]) ? r1.N * r2.N : 0;

    sol.N += evaluate(1, 1, ops[i]) ? 0 : r1.T * r2.T;
    sol.N += evaluate(1, 0, ops[i]) ? 0 : r1.T * r2.N;
    sol.N += evaluate(0, 1, ops[i]) ? 0 : r1.N * r2.T;
    sol.N += evaluate(0, 0, ops[i]) ? 0 : r1.N * r2.N;

  }
  return sol;
}



int solveParenthesis(char *syms, char *ops, int n){

  int sols = 0;

  TSol res = solve(syms, ops, n, 0, n - 1);

  return res.T;
}















struct TDPItem{
  int T, N, All;
  TDPItem(): T(0), N(0), All(0){}
};
struct TString{
  vector<string> T, N;
  TString(): T(*new vector<string>()), N(*new vector<string>()){}
};
void crossStrings(TString& tmp, TString r1, TString r2, char op){

  if(evaluate(1, 1, op)){
    for(vector<string>::iterator j = r1.T.begin() ; j != r1.T.end() ; ++j)
      for(vector<string>::iterator k = r2.T.begin() ; k != r2.T.end() ; ++k)
        tmp.T.push_back("(" + *j + " " + op + " " + *k + ")");
  } else {
    for(vector<string>::iterator j = r1.T.begin() ; j != r1.T.end() ; ++j)
      for(vector<string>::iterator k = r2.T.begin() ; k != r2.T.end() ; ++k)
        tmp.N.push_back("(" + *j + " " + op + " " + *k + ")");
  }

  if(evaluate(1, 0, op)){
    for(vector<string>::iterator j = r1.T.begin() ; j != r1.T.end() ; ++j)
      for(vector<string>::iterator k = r2.N.begin() ; k != r2.N.end() ; ++k)
        tmp.T.push_back("(" + *j + " " + op + " " + *k + ")");
  } else {
    for(vector<string>::iterator j = r1.T.begin() ; j != r1.T.end() ; ++j)
      for(vector<string>::iterator k = r2.N.begin() ; k != r2.N.end() ; ++k)
        tmp.N.push_back("(" + *j + " " + op + " " + *k + ")");
  }
   
  if(evaluate(0, 1, op)){
    for(vector<string>::iterator j = r1.N.begin() ; j != r1.N.end() ; ++j)
      for(vector<string>::iterator k = r2.T.begin() ; k != r2.T.end() ; ++k)
        tmp.T.push_back("(" + *j + " " + op + " " + *k + ")");
  } else {
    for(vector<string>::iterator j = r1.N.begin() ; j != r1.N.end() ; ++j)
      for(vector<string>::iterator k = r2.T.begin() ; k != r2.T.end() ; ++k)
        tmp.N.push_back("(" + *j + " " + op + " " + *k + ")");
  }

  if(evaluate(0, 0, op)){
    for(vector<string>::iterator j = r1.N.begin() ; j != r1.N.end() ; ++j)
      for(vector<string>::iterator k = r2.N.begin() ; k != r2.N.end() ; ++k)
        tmp.T.push_back("(" + *j + " " + op + " " + *k + ")");
  } else {
    for(vector<string>::iterator j = r1.N.begin() ; j != r1.N.end() ; ++j)
      for(vector<string>::iterator k = r2.N.begin() ; k != r2.N.end() ; ++k)
        tmp.N.push_back("(" + *j + " " + op + " " + *k + ")");
  }

}
TString getStrings(char *syms, char *ops, int n, TDPItem **dp, int row, int col){

  if(row == col){
    TString res = *new TString();
    if(charToBoolean(syms[row])) 
      res.T.push_back(*new string(1, syms[row]));
    else 
      res.N.push_back(*new string(1, syms[row]));
    return res;
  }


  TString tmp = *new TString();
  for(int i = row ; i < col ; i++){

    TString r1 = getStrings(syms, ops, n, dp, row, i);
    TString r2 = getStrings(syms, ops, n, dp, i + 1, col);

    crossStrings(tmp, r1, r2, ops[i]);
  }
  return tmp;
}




int solveParenthesisDP(char *syms, char *ops, int n){

  TDPItem **dp = new TDPItem*[n];
  for(int i = 0 ; i < n ; i++){
    dp[i] = new TDPItem[n];
    memset(dp[i], 0, sizeof(TDPItem) * n);
  }



  for(int r = 0 ; r < n ; r++){
    dp[r][r] = *new TDPItem();
    dp[r][r].All = 1;
    dp[r][r].T =  charToBoolean(syms[r]);
    dp[r][r].N = !charToBoolean(syms[r]);
  }



  for(int l = 1 ; l < n ; l++){

    for(int r = 0 ; r < n && r + l < n ; r++){
      dp[r][r + l] = *new TDPItem(); 
      
      for(int i = r ; i < r + l ; i++){
        dp[r][r + l].All += dp[r][i].All * dp[i + 1][r + l].All;

        dp[r][r + l].T += evaluate(1, 1, ops[i]) ? dp[r][i].T * dp[i + 1][r + l].T : 0;
        dp[r][r + l].T += evaluate(1, 0, ops[i]) ? dp[r][i].T * dp[i + 1][r + l].N : 0;
        dp[r][r + l].T += evaluate(0, 1, ops[i]) ? dp[r][i].N * dp[i + 1][r + l].T : 0;
        dp[r][r + l].T += evaluate(0, 0, ops[i]) ? dp[r][i].N * dp[i + 1][r + l].N : 0;

        dp[r][r + l].N += evaluate(1, 1, ops[i]) ? 0 : dp[r][i].T * dp[i + 1][r + l].T;
        dp[r][r + l].N += evaluate(1, 0, ops[i]) ? 0 : dp[r][i].T * dp[i + 1][r + l].N;
        dp[r][r + l].N += evaluate(0, 1, ops[i]) ? 0 : dp[r][i].N * dp[i + 1][r + l].T;
        dp[r][r + l].N += evaluate(0, 0, ops[i]) ? 0 : dp[r][i].N * dp[i + 1][r + l].N;
      }
    }
  }


  // Printing Solution
  TString res = getStrings(syms, ops, n, dp, 0, n - 1);

  cout << "Positive Strings (" << dp[0][n - 1].T << "/" << dp[0][n - 1].All << ")" << endl;
  for(vector<string>::iterator it = res.T.begin() ; it != res.T.end() ; ++it)
    cout << *it << endl;

  cout << "Negative Strings (" << dp[0][n - 1].N << "/" << dp[0][n - 1].All << ")" << endl;
  for(vector<string>::iterator it = res.N.begin() ; it != res.N.end() ; ++it)
    cout << *it << endl;


  return dp[0][n - 1].T;
}











// https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/
int main(int argc, char **argv, char **envp){

  int n, exp;
  char *syms, *ops;


  n = 3, syms = new char[n]{'T', 'F', 'T'}, ops = new char[n - 1]{'^', '&'}, exp = 2;
  assert(solveParenthesis(syms, ops, n) == exp);
  assert(solveParenthesisDP(syms, ops, n) == exp);


  n = 3, syms = new char[n]{'T', 'F', 'F'}, ops = new char[n - 1]{'^', '|'}, exp = 2;
  assert(solveParenthesis(syms, ops, n) == exp);
  assert(solveParenthesisDP(syms, ops, n) == exp);


  n = 4, syms = new char[n]{'T', 'T', 'F', 'T'}, ops = new char[n - 1]{'|', '&', '^', }, exp = 4;
  assert(solveParenthesis(syms, ops, n) == exp);
  assert(solveParenthesisDP(syms, ops, n) == exp);



  cout << "\nProgram Exited successfully";
  return 0;
}