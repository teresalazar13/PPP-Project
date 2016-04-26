projeto: main.o menu.o listas.o prints.o header.h
	gcc -o projeto main.o menu.o listas.o prints.o
main.o: main.c header.h
	gcc -c main.c
menu.o : menu.c header.h
	gcc -c menu.c
listas.o : listas.c header.h
	gcc -c listas.c
prints.o : prints.c header.h
	gcc -c prints.c
