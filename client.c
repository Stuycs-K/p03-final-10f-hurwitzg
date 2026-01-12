
#include "serverHelp.h"

void clientLogic(int server_socket){
  int bytes_read;
  char * buff = calloc(BUFFER_SIZE,1);
  printf("%s\n",buff);
  while(1){
    int * works;
    while(1){
      buff = calloc(22,1);
      works = calloc(20,1);
      printf("Make a move: ");
      fflush(stdin);
      if(!fgets(buff,4,stdin)) er();
      buff[2] = '\0';
      works = translateInput(buff);
      if(works){
        break;
      }
    }
      int len, bytes_sent;
      len = strlen(buff);
      bytes_sent = send(server_socket, buff, len, 0);
      if (bytes_sent == 0) er();
      bytes_read = recv(server_socket, buff, 22, 0);
      printf("%s\n",buff);
      if (bytes_read == 0) er();
      if (buff[1] == 4)printf("Invalid position; Please input a valid square\n");continue;
      printf("%s\n",buff);
    }
  }

int main(int argc, char *argv[] ) {
    char* IP = "127.0.0.1";
    if(argc>1){
      IP=argv[1];
    }
    int server_socket = client_tcp_handshake(IP);
    int bytes_read;
    char * buff = calloc(BUFFER_SIZE,1);
    bytes_read = recv(server_socket, buff, BUFFER_SIZE, 0);
    while(1){
      if (!strcmp(buff,"initial"))break;
    }
    printf("client connected.\n");
    clientLogic(server_socket);
}
