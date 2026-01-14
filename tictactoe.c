
#include "tictactoe.h"
int er(){
  printf("%s\n",strerror(errno));
  exit(1);
}
char ** boardSetup(){
  char ** board = calloc(sizeof(char*),3);
  for (int i = 0; i < 3; i++){
    board[i] = calloc(3,1);
  }
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      board[i][j] = '_';
    }
  }
  return board;
}
int * translateInput(char * str){
  int * coords = calloc(sizeof(int),2);
  if (!strcmp("A1",str) || !strcmp("a1",str)){
    coords[0] = 1;
    coords[1] = 0;
  }
  else if (!strcmp("A2",str) || !strcmp("a2",str)){
    coords[0] = 1;
    coords[1] = 1;
  }
  else if (!strcmp("A3",str) || !strcmp("a3",str)){
    coords[0] = 1;
    coords[1] = 2;
  }
  else if (!strcmp("B1",str) || !strcmp("b1",str)){
    coords[0] = 2;
    coords[1] = 0;
  }
  else if (!strcmp("B2",str) || !strcmp("b2",str)){
    coords[0] = 2;
    coords[1] = 1;
  }
  else if (!strcmp("B3",str) || !strcmp("b3",str)){
    coords[0] = 2;
    coords[1] = 2;
  }
  else if (!strcmp("C1",str) || !strcmp("c1",str)){
    coords[0] = 3;
    coords[1] = 0;
  }
  else if (!strcmp("C2",str) || !strcmp("c2",str)){
    coords[0] = 3;
    coords[1] = 1;
  }
  else if (!strcmp("C3",str) || !strcmp("c3",str)){
    coords[0] = 3;
    coords[1] = 2;
  }
  else{
    printf("Invalid position; Please input a valid square\n");
    coords[0] = 4;
    return coords;
  }
  return coords;
}
char ** boardChange(char ** board, char * input, char XorO){
  int * coords = calloc(sizeof(int),2);
  coords = translateInput(input);
  if(coords[0] == 4)return NULL;
  if (XorO == 'X'){
    if (board[coords[0]-1][coords[1]] == '_'){
      board[coords[0]-1][coords[1]] = 'X';
    }
    else{
      printf("Invalid position; Please input a valid square\n");
      return NULL;
    }
  }
  else{
    if (board[coords[0]-1][coords[1]] == '_'){
      board[coords[0]-1][coords[1]] = 'O';
    }
    else{
      printf("Invalid position; Please input a valid square\n");
      return NULL;
    }
  }
  return board;
}
char * printBoard(char ** board){
  char * oneLine = calloc(20,1);
  for (int i = 0; i < 3; i++){
    strcat(oneLine,board[i]);
    strcat(oneLine,"\n");
  }
  printf("%s",oneLine);
  return oneLine;
}
char evaluate(char ** board){
  if ((board[0][0] == 'X' &&
      board[1][0] == 'X' &&
      board[2][0] == 'X') ||
      (board[0][1] == 'X' &&
       board[1][1] == 'X' &&
       board[2][1] == 'X') ||
       (board[0][2] == 'X' &&
        board[1][2] == 'X' &&
        board[2][2] == 'X') ||
        (board[0][0] == 'X' &&
          board[0][1] == 'X' &&
          board[0][2] == 'X') ||
          (board[1][0] == 'X' &&
           board[1][1] == 'X' &&
           board[1][2] == 'X') ||
           (board[2][0] == 'X' &&
            board[2][1] == 'X' &&
            board[2][2] == 'X') ||
            (board[0][0] == 'X' &&
              board[1][1] == 'X' &&
              board[2][2] == 'X') ||
               (board[0][2] == 'X' &&
                board[1][1] == 'X' &&
                board[2][0] == 'X')){
                  return 'X';
                }
    if ((board[0][0] == 'O' &&
        board[1][0] == 'O' &&
        board[2][0] == 'O') ||
        (board[0][1] == 'O' &&
         board[1][1] == 'O' &&
         board[2][1] == 'O') ||
         (board[0][2] == 'O' &&
          board[1][2] == 'O' &&
          board[2][2] == 'O') ||
          (board[0][0] == 'O' &&
            board[0][1] == 'O' &&
            board[0][2] == 'O') ||
            (board[1][0] == 'O' &&
             board[1][1] == 'O' &&
             board[1][2] == 'O') ||
             (board[2][0] == 'O' &&
              board[2][1] == 'O' &&
              board[2][2] == 'O') ||
              (board[0][0] == 'O' &&
                board[1][1] == 'O' &&
                board[2][2] == 'O') ||
                 (board[0][2] == 'O' &&
                  board[1][1] == 'O' &&
                  board[2][0] == 'O')){
                    return 'O';
                  }
                  for (int i = 0; i < 3; i++){
                    for (int j = 0; j < 3; j++){
                      if (board[i][j] != 'X' && board[i][j] != 'O'){
                        return 'C';
                      }
                    }
                  }
                  return 'T';
}
