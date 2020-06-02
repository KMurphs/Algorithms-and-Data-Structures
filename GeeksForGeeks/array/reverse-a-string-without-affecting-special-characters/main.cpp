#include <bits/stdc++.h>

using namespace std;

void Swap(char *arr, int l, int r){
  char tmp = arr[l];
  arr[l] = arr[r];
  arr[r] = tmp;
}

char *reverseString(string inStr){
  
  char *outStr = new char[inStr.size() + 1];
  strcpy(outStr, inStr.c_str());

  int l = 0, r = inStr.size() - 1;

  while(l < r){

    bool isCharAtLValid = (
      (inStr[l] >= 'a' && inStr[l] <= 'z') ||
      (inStr[l] >= 'A' && inStr[l] <= 'Z')
    );
    bool isCharAtRValid = (
      (inStr[r] >= 'a' && inStr[r] <= 'z') ||
      (inStr[r] >= 'A' && inStr[r] <= 'Z')
    );

    if(isCharAtLValid && isCharAtRValid) {
      Swap(outStr, l, r); 
      l++;
      r--;
    }

    if(!isCharAtLValid) l++;
    if(!isCharAtRValid) r--;

  }

  return outStr;
}



// https://www.geeksforgeeks.org/reverse-a-string-without-affecting-special-characters/
int main(){

  cout << "'a,b$c' reversed is: '" << reverseString("a,b$c") << "'" << endl;
  assert("12345" == "12345");

  assert((string)reverseString("a,b$c") == "c,b$a");
  assert((string)reverseString("Ab,c,de!$") == "ed,c,bA!$");

  cout << "Program Successfully Exited";
  return 0;
}