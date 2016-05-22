#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int prot_menu() {
  int check;
  char str[MAX_CHAR];
  while (scanf(" %[^\n]", str) ) {
    int i = 0;
    int len = strlen(str);
    while (i < len) {
      if (str[i] < '0' || str[i] > '9') {
        return 30; /*vai para default*/
      }
      i++;
    }
    if (i == len) {
      check = atoi(str);
      return check;
    }
  }
  return 0;
}

char *prot_string() {
  char *str = (char *) malloc(MAX_CHAR * sizeof(char));
  while (scanf(" %[^\n]", str) ) {
    int i = 0;
    int len = strlen(str);
    while (i < len) {
      if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && str[i] != 32) {
        printf("Nao pode introduzir numeros ou simbolos. \n");
        printf("Tente de novo: ");
        return prot_string();
      }
      i++;
    }
    return str;
  }
  return str;
}

int prot_int() {
  char *inteiro = (char *) malloc(MAX_CHAR * sizeof(char));
  while (scanf(" %[^\n]", inteiro) ) {
    int i = 0;
    int len = strlen(inteiro);
    while (i < len) {
      if (inteiro[i] < '0' || inteiro[i] > '9') {
        printf("Nao pode introduzir numeros ou simbolos. \n");
        printf("Tente de novo: ");
        return prot_int();
      }
      i++;
    }
    return atoi(inteiro);
  }
  return atoi(inteiro);
}
