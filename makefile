CC = gcc
CFLAGS = -ansi -Wall -g

projeto: main.o menu.o listas.o prints.o sort.o procura.o adquirir.o cancelar.o protecoes.o ficheiros.o header.h
	$(CC) $(CFLAGS) -o projeto main.o menu.o listas.o prints.o sort.o procura.o adquirir.o cancelar.o protecoes.o ficheiros.o
main.o: main.c header.h
	$(CC) $(CFLAGS) -c main.c
menu.o : menu.c header.h
	$(CC) $(CFLAGS) -c menu.c
listas.o : listas.c header.h
	$(CC) $(CFLAGS) -c listas.c
prints.o : prints.c header.h
	$(CC) $(CFLAGS) -c prints.c
sort.o : sort.c header.h
	$(CC) $(CFLAGS) -c sort.c
procura.o : procura.c header.h
	$(CC) $(CFLAGS) -c procura.c
adquirir.o : adquirir.c header.h
	$(CC) $(CFLAGS) -c adquirir.c
cancelar.o : cancelar.c header.h
	$(CC) $(CFLAGS) -c cancelar.c
protecoes.o : protecoes.c header.h
	$(CC) $(CFLAGS) -c protecoes.c
ficheiros.o : ficheiros.c header.h
	$(CC) $(CFLAGS) -c ficheiros.c
