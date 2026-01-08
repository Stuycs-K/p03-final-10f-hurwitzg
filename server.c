#include "serverHelp.h"
#include "tictactoe.h"
static void sighandler(int signo) {
    if (signo == 2){
      exit(0);
    }
  }
int r(){
  int x = (rand()%2);
  return x;
}
void subserver_logic(int client_socket1, int client_socket2){
  char ** board = calloc(sizeof(char*),3);
  board = boardSetup();
  char * pBoard = calloc(20,1);
  int bytes_read;
  int bytes_sent;
	while(1){
    pBoard = printBoard(board);
    char * buff = calloc(BUFFER_SIZE,1);
    bytes_read = recv(client_socket1, buff, BUFFER_SIZE, 0);
    if (!translateInput(buff))buff[1] = 15;bytes_sent = send(client_socket1, pBoard, 20, 0);continue;
    if (bytes_read == 0)exit(0);
    if (boardChange(board, buff,'X')){
      pBoard = printBoard(board);
      if (evaluate(board) == 'C'){
        bytes_sent = send(client_socket1, pBoard, 20, 0);
      }
      else if (evaluate(board) == 'T'){
        char * temp = calloc(40,1);
        strcat(temp,"You tie!\n");
        strcat(temp,pBoard);
        bytes_sent = send(client_socket1, temp, 20, 0);
        bytes_sent = send(client_socket2, temp, 20, 0);
        break;
      }
      else if (evaluate(board) == 'X'){
        char * temp = calloc(40,1);
        strcat(temp,"X wins!\n");
        strcat(temp,pBoard);
        bytes_sent = send(client_socket1, temp, 20, 0);
        bytes_sent = send(client_socket2, temp, 20, 0);
        break;
      }
      else{
        char * temp = calloc(40,1);
        strcat(temp,"O wins!\n");
        strcat(temp,pBoard);
        bytes_sent = send(client_socket1, temp, 20, 0);
        bytes_sent = send(client_socket2, temp, 20, 0);
        break;
      }
    }
    else{
      buff[1] = 15;
      bytes_sent = send(client_socket1, buff, 2, 0);
      continue;
    }
    buff = calloc(BUFFER_SIZE,1);
    bytes_read = recv(client_socket2, buff, BUFFER_SIZE, 0);
    if (bytes_read == 0)exit(0);
    if (boardChange(board, buff,'O')){
      pBoard = printBoard(board);
      if (evaluate(board) == 'C'){
        bytes_sent = send(client_socket1, pBoard, 20, 0);
      }
      else if (evaluate(board) == 'T'){
        char * temp = calloc(40,1);
        strcat(temp,"You tie!\n");
        strcat(temp,pBoard);
        bytes_sent = send(client_socket1, temp, 20, 0);
        bytes_sent = send(client_socket2, temp, 20, 0);
        break;
      }
      else if (evaluate(board) == 'X'){
        char * temp = calloc(40,1);
        strcat(temp,"X wins!\n");
        strcat(temp,pBoard);
        bytes_sent = send(client_socket1, temp, 20, 0);
        bytes_sent = send(client_socket2, temp, 20, 0);
        break;
      }
      else{
        char * temp = calloc(40,1);
        strcat(temp,"O wins!\n");
        strcat(temp,pBoard);
        bytes_sent = send(client_socket1, temp, 20, 0);
        bytes_sent = send(client_socket2, temp, 20, 0);
        break;
      }
    }
    else{
      buff[1] = 15;
      bytes_sent = send(client_socket2, buff, 2, 0);
      continue;
    }
	}
}

int main(int argc, char *argv[] ) {
  int listen_socket = server_setup();
  signal(2, sighandler);
	while(1){
    int client_socket1 = server_tcp_handshake(listen_socket);
    int client_socket2 = server_tcp_handshake(listen_socket);
    int p = fork();
		if (p < 0)er();
    if (p == 0){
        subserver_logic(client_socket1, client_socket2);
        close(client_socket1);
        close(client_socket2);
        exit(0);
		}
		else{
      close(client_socket1);
      close(client_socket2);
		}
	}

}
