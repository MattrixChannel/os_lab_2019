CC = gcc
CFLAGS = -pthread

LIB_NAME = mylib.a

all: server client

server: server.o mylib.a
	$(CC) $(CFLAGS) -o $@ server.o -L. -lcommon

client: client.o mylib.a
	$(CC) $(CFLAGS) -o $@ client.o -L. -lcommon

mylib.a: lib.o
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f server.o client.o lib.o server client mylib.a

rebuild: clean all

run_server: server
	./server --port 20001 --tnum 4

run_client: client
	./client --k 4 --mod 7 --servers servers.txt

.PHONY: all clean rebuild run_server run_client