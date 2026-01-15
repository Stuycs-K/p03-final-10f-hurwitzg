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
  char p1,p2;
  if (r()){
    p1 = 'X';
    p2 = 'O';
  }
  else{
    p2 = 'X';
    p1 = 'O';
  }
  char turn = 0;

	while(1){
    int current = !turn ? client_socket1 : client_socket2;
    int other   = !turn ? client_socket2 : client_socket1;
    char piece  = !turn ? p1 : p2;
    FD_ZERO(&fds);
    FD_SET(client_socket1, &fds);
    FD_SET(client_socket2, &fds);
    int maxfd = max(client_socket1,client_socket2) + 1;
    int i = select(maxfd,&fds,NULL,NULL,NULL);
    if (FD_ISSET(current,&fds)){
      bytes_read = recv(current, buff, BUFFER_SIZE, 0);
      if (bytes_read == 0)exit(0);
      if (!boardChange(board, buff, piece)) {
        bytes_sent = send(current, "Invalid move. Try again.\n", 26, 0);
        continue;
      }
      pBoard = printBoard(board);
      if (evaluate(board) == 'C'){
        bytes_sent = send(other, pBoard, 22, 0);
        turn = 1 - turn;
      }
      else if (evaluate(board) == 'T'){
        char * temp = "You tie!\n";
        strcat(temp,pBoard);
        bytes_sent = send(client_socket1, temp, 40, 0);
        bytes_sent = send(client_socket2, temp, 40, 0);
        break;
      }
      else if (evaluate(board) == 'X'){
        char * temp = "X Wins!\n";
        strcat(temp,pBoard);
        bytes_sent = send(client_socket1, temp, 40, 0);
        bytes_sent = send(client_socket2, temp, 40, 0);
        break;
      }
      else{
        char * temp = "O Wins!\n";
        strcat(temp,pBoard);
        bytes_sent = send(client_socket1, temp, 40, 0);
        bytes_sent = send(client_socket2, temp, 40, 0);
        break;
      }
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
    char * temp1 = "initial1";
    char * temp2 = "initial2";
    int bytes_sent;
    bytes_sent = send(client_socket1, temp1, 20, 0);
    bytes_sent = send(client_socket2, temp2, 20, 0);
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
