CC=gcc
CFLAGS=-I.

parallel_min_max : utils.o find_min_max.o utils.h find_min_max.h
	$(CC) -o parallel_min_max utils.o find_min_max.o parallel_min_max.c $(CFLAGS)

parallel_min_maxV2 : utils.o find_min_max.o utils.h find_min_max.h
	$(CC) -o parallel_min_maxV2 utils.o find_min_max.o parallel_min_maxV2.c $(CFLAGS)

utils.o : utils.h
	$(CC) -o utils.o -c utils.c $(CFLAGS)

find_min_max.o : utils.h find_min_max.h
	$(CC) -o find_min_max.o -c find_min_max.c $(CFLAGS)

zombie :
	$(CC) -o zombie zombie.c $(CFLAGS)

clean : rmRes
	rm utils.o find_min_max.o parallel_min_maxV2 parallel_min_max zombie 

rmRes :
	rm result_0.txt result_1.txt result_2.txt result_3.txt result_4.txt result_5.txt result_6.txt result_7.txt result_8.txt result_9.txt

all : parallel_min_max parallel_min_maxV2 zombie
