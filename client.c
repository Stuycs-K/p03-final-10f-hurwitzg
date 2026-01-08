#include "serverHelp.h"

void clientLogic(int server_socket){
  while(1){
    char * buff;
    int * works;
    while(1){
      buff = calloc(8,1);
      works = calloc(8,1);
      printf("Make a move: ");
      fflush(stdin);
      if(!fgets(buff,4,stdin)) er();
      buff[2] = '\0';
      printf("%s\n",buff);
      works = translateInput(buff);
      printf("%s\n",buff);
      if(works){
        break;
      }
      else{
        printf("Invalid position; Please input a valid square\n");
      }
    }
      int len, bytes_sent;
      len = strlen(buff);
      bytes_sent = send(server_socket, buff, len, 0);
      if (bytes_sent == 0) er();
      int bytes_read = -1;
      while(1){
        bytes_read = recv(server_socket, buff, BUFFER_SIZE, 0);
        if (bytes_read > 0)break;
      }
      if (bytes_read == 0) er();
      if (buff[1] == -15)printf("Invalid position; Please input a valid square\n");continue;
      printf("Recieved %s\n",buff);
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
