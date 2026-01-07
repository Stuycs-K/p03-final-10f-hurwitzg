#include "serverHelp.h"

void clientLogic(int server_socket){
  while(1){
      printf("Make a move: ");
      char * buff = calloc(BUFFER_SIZE,1);
      if(!fgets(buff,BUFFER_SIZE,stdin)) exit(0);
      int len, bytes_sent;
      len = strlen(buff);
      bytes_sent = send(server_socket, buff, len, 0);
      if (bytes_sent == 0)exit(0);
      int bytes_read;
      bytes_read = recv(server_socket, buff, BUFFER_SIZE, 0);
      if (bytes_read == 0)exit(0);
      printf("Recieved %s\n",buff);
    }
  }

int main(int argc, char *argv[] ) {
    char* IP = "127.0.0.1";
    if(argc>1){
      IP=argv[1];
    }
    int server_socket = client_tcp_handshake(IP);
    printf("client connected.\n");
    clientLogic(server_socket);

}
