#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//derp
int main (void) {
  srand(time(NULL)/2);
  int game[9][9];
  printf("Hello world %d\n", game[0][0]);
  int test_rand = rand() % 9 + 1;
  printf("Rand test %d\n", test_rand);
  return 0;
}
