#include <stdio.h>

int main(void){
  #define sz 100
  int a[sz];

  for(int i = 0; i < sz; ++i){
    a[i] = i;
  }

  printf("bye...\n");
}