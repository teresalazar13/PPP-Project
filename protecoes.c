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
        return 30; //vai para default
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
      if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')) {
        printf("Não pode introduzir números ou símbolos \n");
        return 0;
      }
      i++;
    }
    return str;
  }
  return 0;
}
