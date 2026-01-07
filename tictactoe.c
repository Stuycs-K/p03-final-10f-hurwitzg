#include "tictactoe.h"
int err(){
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
  if (str[0] == 'A' || str[0] == 'a'){
    coords[0] = 0;
  }
  else if (str[0] == 'B' || str[0] == 'b'){
    coords[0] = 1;
  }
  else if (str[0] == 'C' || str[0] == 'c'){
    coords[0] = 2;
  }
  else{
    printf("Invalid position; Please input a valid square\n");
    return NULL;
  }
  if (str[1] == '1'){
    coords[1] = 0;
  }
  else if (str[1] == '2'){
    coords[1] = 1;
  }
  else if (str[1] == '3'){
    coords[1] = 2;
  }
  else{
    printf("Invalid position; Please input a valid square\n");
    return NULL;
  }
  return coords;
}
char ** boardChange(char ** board, char * input, char XorO){
  int * coords = calloc(sizeof(int),2);
  if(!(coords = translateInput(input)))return board;
  if (XorO == 'X'){
    board[coords[0]][coords[1]] = 'X';
  }
  else{
    board[coords[0]][coords[1]] = 'O';
  }
  return board;
}
void printBoard(char ** board){
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      printf("%c",board[i][j]);
    }
    printf("\n");
  }
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
int main(){
  char ** board = calloc(sizeof(char*),3);
  board = boardSetup();
  printBoard(board);
  char * str1 = "A1";
  boardChange(board, str1, 'X');
  printBoard(board);
  char * str2 = "b1";
  boardChange(board, str2, 'X');
  printBoard(board);
  char * str3 = "c2";
  boardChange(board, str3, 'O');
  printBoard(board);
  char * str4 = "d4";
  boardChange(board, str4, 'X');
  printBoard(board);
}
