CC=gcc
CFLAGS=-I.

tcpclient : 
	$(CC) -o tcpclient tcpclient.c $(CFLAGS)

tcpserver : 
	$(CC) -o tcpserver tcpserver.c $(CFLAGS)

udpclient : 
	$(CC) -o udpclient udpclient.c $(CFLAGS)

udpserver : 
	$(CC) -o udpserver udpserver.c $(CFLAGS)

zombie :
	$(CC) -o zombie zombie.c $(CFLAGS)

clean : 
	rm tcpclient tcpserver udpclient udpserver

all : tcpclient tcpserver udpclient udpserver
