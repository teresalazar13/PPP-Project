projeto: main.o menu.o listas.o prints.o sort.o viagens.o header.h
	gcc -o projeto main.o menu.o listas.o prints.o sort.o viagens.o
main.o: main.c header.h
	gcc -c main.c
menu.o : menu.c header.h
	gcc -c menu.c
listas.o : listas.c header.h
	gcc -c listas.c
prints.o : prints.c header.h
	gcc -c prints.c
sort.o : sort.c header.h
	gcc -c sort.c
viagens.o : viagens.c header.h
	gcc -c viagens.c
