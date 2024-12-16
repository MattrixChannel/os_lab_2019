CC = gcc
CFLAGS = -pthread

all: server client

server: server.o libcommon.a
	$(CC) $(CFLAGS) -o $@ server.o -L. -lcommon

client: client.o libcommon.a
	$(CC) $(CFLAGS) -o $@ client.o -L. -lcommon

libcommon.a: common.o
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f server.o client.o common.o server client libcommon.a

rebuild: clean all