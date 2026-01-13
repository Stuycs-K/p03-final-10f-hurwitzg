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
int max(int a, int b){
  if (a > b){return a;}
  else {return b;}
}
void subserver_logic(int client_socket1, int client_socket2){
  fd_set fds;
  char * buff = calloc(BUFFER_SIZE,1);
  char ** board = calloc(sizeof(char*),3);
  board = boardSetup();
  char * pBoard = calloc(20,1);
  int bytes_read;
  int bytes_sent;
  pBoard = printBoard(board);
  bytes_sent = send(client_socket1, pBoard, 22, 0);
  char t2 = 0;
	while(1){
    FD_ZERO(&fds);
    FD_SET(client_socket1, &fds);
    int i = select(client_socket1+1,&fds,NULL,NULL,NULL);
    if (FD_ISSET(client_socket1,&fds) && !t2){
      bytes_read = recv(client_socket1, buff, BUFFER_SIZE, 0);
      if (bytes_read == 0)exit(0);
      if (board = boardChange(board, buff,'X')){
        pBoard = printBoard(board);
        if (evaluate(board) == 'C'){
          t2 = 1;
          bytes_sent = send(client_socket2, pBoard, 22, 0);
        }
        else if (evaluate(board) == 'T'){
          char * temp = calloc(40,1);
          strcat(temp,"You tie!\n");
          strcat(temp,pBoard);
          bytes_sent = send(client_socket1, temp, 40, 0);
          bytes_sent = send(client_socket2, temp, 40, 0);
          break;
        }
        else if (evaluate(board) == 'X'){
          char * temp = calloc(40,1);
          strcat(temp,"X wins!\n");
          strcat(temp,pBoard);
          bytes_sent = send(client_socket1, temp, 40, 0);
          bytes_sent = send(client_socket2, temp, 40, 0);
          break;
        }
        else{
          char * temp = calloc(40,1);
          strcat(temp,"O wins!\n");
          strcat(temp,pBoard);
          bytes_sent = send(client_socket1, temp, 40, 0);
          bytes_sent = send(client_socket2, temp, 40, 0);
          break;
        }
      }
      else{
        buff[1] = 4;
        bytes_sent = send(client_socket1, buff, 22, 0);
        continue;
      }
    }
    else if(t2){}
    else{
      continue;
    }
    buff = calloc(BUFFER_SIZE,1);
    FD_ZERO(&fds);
    FD_SET(client_socket2, &fds);
    i = select(client_socket2+1,&fds,NULL,NULL,NULL);
    if (FD_ISSET(client_socket2,&fds) && t2){
      bytes_read = recv(client_socket2, buff, BUFFER_SIZE, 0);
      if (bytes_read == 0)exit(0);
      if (board = boardChange(board, buff,'O')){
        pBoard = printBoard(board);
        if (evaluate(board) == 'C'){
          t2 = 0;
          bytes_sent = send(client_socket1, pBoard, 22, 0);
        }
        else if (evaluate(board) == 'T'){
          char * temp = calloc(40,1);
          strcat(temp,"You tie!\n");
          strcat(temp,pBoard);
          bytes_sent = send(client_socket1, temp, 40, 0);
          bytes_sent = send(client_socket2, temp, 40, 0);
          break;
        }
        else if (evaluate(board) == 'X'){
          char * temp = calloc(40,1);
          strcat(temp,"X wins!\n");
          strcat(temp,pBoard);
          bytes_sent = send(client_socket1, temp, 40, 0);
          bytes_sent = send(client_socket2, temp, 40, 0);
          break;
        }
        else{
          char * temp = calloc(40,1);
          strcat(temp,"O wins!\n");
          strcat(temp,pBoard);
          bytes_sent = send(client_socket1, temp, 40, 0);
          bytes_sent = send(client_socket2, temp, 40, 0);
          break;
        }
      }
      else{
        buff[1] = 4;
        bytes_sent = send(client_socket2, buff, 3, 0);
        continue;
      }
  	}
    else{
      continue;
    }
  }
}

int main(int argc, char *argv[] ) {
  int listen_socket = server_setup();
  signal(2, sighandler);
	while(1){
    int client_socket1 = server_tcp_handshake(listen_socket);
    printf("client connected.\n");
    int client_socket2 = server_tcp_handshake(listen_socket);
    printf("client connected.\n");
    char * temp = "initial";
    int bytes_sent;
    bytes_sent = send(client_socket1, temp, 20, 0);
    bytes_sent = send(client_socket2, temp, 20, 0);
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
