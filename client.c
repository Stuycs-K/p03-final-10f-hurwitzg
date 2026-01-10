#include "serverHelp.h"

void clientLogic(int server_socket){
  while(1){
    char * buff = calloc(BUFFER_SIZE,1);
    printf("Make a move: ");
    if(!fgets(buff,BUFFER_SIZE,stdin)) exit(0);
    int len, bytes_sent;
    len = strlen(buff);
    bytes_sent = send(server_socket, buff, len, 0);
    if (bytes_sent == 0)exit(0);
    int bytes_read;
    bytes_read = recv(server_socket, buff, BUFFER_SIZE, 0);
    if (bytes_read == 0)exit(0);
    if (buff[1] == 15)printf("Invalid position; Please input a valid square\n");continue;
    printf("Recieved %s\n",buff);
    len = strlen(buff);
    bytes_sent = send(server_socket, buff, len, 0);
    if (bytes_sent == 0)exit(0);
    bytes_read = recv(server_socket, buff, BUFFER_SIZE, 0);
    if (bytes_read == 0)exit(0);
    if (buff[1] == 15)printf("Invalid position; Please input a valid square\n");continue;
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
