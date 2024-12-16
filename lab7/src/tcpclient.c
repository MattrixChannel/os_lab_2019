#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
/*
#define BUFSIZE 100
#define SADDR struct sockaddr
#define SIZE sizeof(struct sockaddr_in)
*/
int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Необходимые аргументы: <ip> <port> <bufsize>\n");
    exit(1);
  }

  int fd;
  int nread;
  int BUFSIZE = atoi(argv[3]); // Вынесли BUFSIZE в аргумент
  char buf[BUFSIZE];
  struct sockaddr_in servaddr;

  if ((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket creating");
    exit(1);
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;

  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) { // Вынесли IP
    perror("bad address");
    exit(1);
  }

  servaddr.sin_port = htons(atoi(argv[2])); // Вынесли порт

  if (connect(fd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("connect");
    exit(1);
  }

  write(1, "Введите сообщение для отправки\n", 59);
  while ((nread = read(0, buf, BUFSIZE)) > 0) {
    if (write(fd, buf, nread) < 0) {
      perror("write");
      exit(1);
    }
  }

  close(fd);
  exit(0);
}