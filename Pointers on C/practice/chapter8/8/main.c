#include <stdio.h>

#define SIZE 8

unsigned num_answer = 0;

unsigned check_queen(unsigned board[][SIZE], unsigned row, unsigned col) {
  unsigned flag = 0;
  unsigned j;
  for (unsigned i = 0; i < SIZE; i++) {
    flag += board[i][col];
    j = col - row + i;
    if (j >= 0 && j < SIZE) {
      flag += board[i][j];
    }
    j = col + row - i;
    if (j >= 0 && j < SIZE) {
      flag += board[i][j];
    }
  }

  return flag;
}

void print_board(unsigned board[][SIZE], unsigned num_answer) {
  printf("No.%d Answer\n", num_answer);
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      printf("%c", board[i][j] ? 'Q' : '+');
    }
    printf("\n");
  }
  printf("\n");
}

void place_queen(unsigned board[][SIZE], unsigned row) {
  if (row == SIZE) {
    num_answer++;
    print_board(board, num_answer);
    return;
  }

  for (unsigned col = 0; col < SIZE; col++) {
    if (!check_queen(board, row, col)) {
      board[row][col] = 1;
      place_queen(board, row + 1);
      board[row][col] = 0;
    }
  }
}

int main(int argc, char *argv[]) {
  unsigned board[SIZE][SIZE] = {0};
  place_queen(board, 0);
  return 0;
}
