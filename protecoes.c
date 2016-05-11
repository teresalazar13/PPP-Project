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
