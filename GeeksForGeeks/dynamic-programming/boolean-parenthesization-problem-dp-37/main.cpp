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
  TSol(): T(0), N(0){}
};
TSol solve(char *syms, char *ops, int n, int start, int end){
  
  if(start == end) {
    TSol res = *new TSol();
    res.T = charToBoolean(syms[start]) ? 1 : 0;
    res.N = 1 - res.T;
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

  int solLength = n + (n - 1) + 2*(n - 1);
  char *solString = new char[solLength];
  memset(solString, 0, sizeof(char) * solLength);

  TSol res = solve(syms, ops, n, 0, n - 1);

  return res.T;
}






    // string s1, s2;
    // bool res = evaluate(ops, solve(syms, n, 0, i, s1), solve(syms, n, i + 1, n - 1, s2), i);
    // if(res){
    //   sols++;
    //   cout << "(" << s1 << " " << ops[i] << " " << s2 << ")" << endl;
    // }







// https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/
int main(int argc, char **argv, char **envp){

  int n, exp;
  char *syms, *ops;


  n = 3, syms = new char[n]{'T', 'F', 'T'}, ops = new char[n - 1]{'^', '&'}, exp = 2;
  assert(solveParenthesis(syms, ops, n) == exp);


  n = 3, syms = new char[n]{'T', 'F', 'F'}, ops = new char[n - 1]{'^', '|'}, exp = 2;
  assert(solveParenthesis(syms, ops, n) == exp);


  n = 4, syms = new char[n]{'T', 'T', 'F', 'T'}, ops = new char[n - 1]{'|', '&', '^', }, exp = 4;
  assert(solveParenthesis(syms, ops, n) == exp);



  cout << "\nProgram Exited successfully";
  return 0;
}