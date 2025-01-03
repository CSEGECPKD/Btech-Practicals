#include <arpa/inet.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main() {

  int socketFD, connectionFD;
  struct sockaddr_in serverAddress, clientAddress;

  socketFD = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

  if (socketFD == -1) {
    printf("\nSocket creation failed.");
    return 1;
  }

  printf("\nSocket successfully created!");

  bzero(&serverAddress, sizeof(serverAddress));

  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
  serverAddress.sin_port = htons(8080);

  if (bind(socketFD, (struct sockaddr *)&serverAddress,
           sizeof(serverAddress)) != 0) {
    printf("\nSocket binding failed.");
    return 1;
  }

  printf("\nSocket successfully bound!");

  if (listen(socketFD, 5) == -1) {
    printf("\nListening failed.");
    return 1;
  }

  printf("\nListening...");

  socklen_t len = sizeof(clientAddress);

  connectionFD = accept(socketFD, (struct sockaddr *)&clientAddress, &len);

  if (connectionFD == -1) {
    printf("\nClient accept failed.");
    return 1;
  }

  printf("\nClient accept successful.");

  char buffer[80];

  recv(connectionFD, buffer, sizeof(buffer), 0);

  printf("\n\tFrom Client: \"%s\"", buffer);

  int limit = atoi(buffer);

  char result[100];

  int first = 0, second = 1, next = 1;

  while (first < limit) {

    sprintf(result, "%s%d\t", result, first);

    first = second;
    second = next;
    next = first + second;
  }

  printf("\nTo Client: %s", result);

  send(connectionFD, result, sizeof(result), 0);

  printf("\n\n");

  close(connectionFD);
  close(socketFD);

  return 0;
}