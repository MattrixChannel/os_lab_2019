#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
/*
#define SERV_PORT 20001
#define BUFSIZE 1024
#define SADDR struct sockaddr
#define SLEN sizeof(struct sockaddr_in)
*/
int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Необходимые аргументы: <port> <bufsize>\n");
    exit(1);
  }

  int sockfd, n;
  int BUFSIZE = atoi(argv[2]); // Вынесли bufsize
  char mesg[BUFSIZE], ipadr[16];
  struct sockaddr_in servaddr;
  struct sockaddr_in cliaddr;

  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    perror("socket problem");
    exit(1);
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(atoi(argv[1])); // Вынесли порт

  if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("bind problem");
    exit(1);
  }
  printf("Сервер запущен\n");

  while (1) {
    unsigned int len = sizeof(cliaddr);

    if ((n = recvfrom(sockfd, mesg, BUFSIZE, 0, (struct sockaddr *)&cliaddr, &len)) < 0) {
      perror("recvfrom");
      exit(1);
    }
    mesg[n] = 0;

    printf("(С) Запрос: %s      от %s : %d\n", mesg,
           inet_ntop(AF_INET, (void *)&cliaddr.sin_addr.s_addr, ipadr, 16),
           ntohs(cliaddr.sin_port));

    if (sendto(sockfd, mesg, n, 0, (struct sockaddr *)&cliaddr, len) < 0) {
      perror("sendto");
      exit(1);
    }
  }
}