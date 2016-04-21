#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
  char **viagens;
  viagens = (char **) malloc(3 * sizeof(char*));
  char *viagem1;
  viagem1 = (char*) malloc(10 * sizeof(char));
  scanf("%s",viagem1 );
  viagens[0] = viagem1;
  printf("%s\n",*viagens );
  return 0;
}
