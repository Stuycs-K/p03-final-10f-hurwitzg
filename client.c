
#include "serverHelp.h"

void clientLogic(int server_socket, char turn){
  fd_set fds;
  int bytes_read;
  char * buff = calloc(BUFFER_SIZE,1);
  int len, bytes_sent;
  while(1){
    FD_ZERO(&fds);
    FD_SET(server_socket, &fds);
    int i = select(server_socket+1,&fds,NULL,NULL,NULL);
    if (FD_ISSET(server_socket, &fds)){
      bytes_read = recv(server_socket, buff, 40, 0);
      if (bytes_read == 0)exit(0);
      if (bytes_read < 0)er();
      printf("%s\n",buff);
      printf("Make a move: ");
      fflush(stdout);
      if(!fgets(buff,4,stdin)) er();
      buff[2] = '\0';
      len = strlen(buff);
      bytes_sent = send(server_socket, buff, len, 0);
      if (bytes_sent == 0) break;
    }
    else{
      fflush(stdin);
      fflush(stdout);
    }
  }
  bytes_read = recv(server_socket, buff, 40, 0);
  if (bytes_read == 0)exit(0);
  if (bytes_read < 0)er();
  printf("%s\n",buff);
}


int main(int argc, char *argv[] ) {
    char* IP = "127.0.0.1";
    char turn;
    if(argc>1){
      IP=argv[1];
    }
    int server_socket = client_tcp_handshake(IP);
    int bytes_read;
    char * buff = calloc(BUFFER_SIZE,1);
    bytes_read = recv(server_socket, buff, BUFFER_SIZE, 0);
    while(1){
      if (!strcmp(buff,"initial1")){
        turn = 1;
        break;
      }
      if (!strcmp(buff,"initial2")){
        turn = 0;
        break;
      }
    }
    printf("client connected.\n");
    clientLogic(server_socket,turn);
}
