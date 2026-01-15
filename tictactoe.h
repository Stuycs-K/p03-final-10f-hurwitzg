#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>


#ifndef TICTACTOE_H
#define TICTACTOE_H
int er();
char ** boardSetup();
int * translateInput(char * str);
char boardChange(char ** board, char * input, char XorO);
char * printBoard(char ** board);
char evaluate(char ** board);
#endif
