#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

static int game[9][9];

typedef struct {
  int value;
  int row;
  int col;
  int section;
} cell;

bool check_row (cell to_check) {
  for (int i = 0; i < 9; i++) {
    if (i == to_check.col) continue;
    if (game[i][to_check.row] == to_check.value) {
      return false;
    }
  }
  return true;
}

bool check_column (cell to_check) {
  for (int i = 0; i < 9; i++) {
    if (i == to_check.row) continue;
    if (game[to_check.col][i] == to_check.value) {
      return false;
    }
  }
  return true;
}

bool check_section (cell to_check) {
  return false;
}

int main (void) {
  srand(time(NULL)/2);
  for (int i = 0; i < 9; i++) {
    bool used[9] = {false, false, false,
                    false, false, false,
                    false, false, false};
    for (int j = 0; j < 9; j++) {
      int new_rand = rand() % 9 + 1;
      while (used[new_rand - 1]) {
        printf("new_rand %d\n", new_rand);
        new_rand = rand() % 9 + 1;
      }
      game[i][j] = new_rand;
      used[game[i][j] - 1] = true;
    }
    printf("%d used after:\n", i);
    for (int k = 0; k < 9; k++) {
      printf("%s ", used[k] ? "true" : "false");
    }
    printf("\n");
  }
  for (int j = 0; j < 9; j++) {
    for (int i = 0; i < 9; i++) {
      printf("|%d", game[i][j]);
    }
    printf("|\n");
  }
}
