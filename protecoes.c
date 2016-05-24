#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int prot_menu() {
  char str[MAX_CHAR];
  while (scanf(" %[^\n]", str) ) {
    int i = 0;
    int len = strlen(str);
    while (i < len) {
      if (str[i] < '0' || str[i] > '9' || i > 0) {
        printf("Operacao invalida. Selecione um numero de 1 a 9. [0 para sair]: ");
        return prot_menu();
      }
      i++;
    }
    break;
  }
  return atoi(str);
}

char *prot_string() {
  char *str = (char *) malloc(MAX_CHAR * sizeof(char));
  while (scanf(" %[^\n]", str) ) {
    int i = 0;
    int len = strlen(str);
    while (i < len) {
      if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && str[i] != 32) {
        printf("Nao pode introduzir numeros ou simbolos.\n");
        printf("Tente de novo: ");
        free(str);
        return prot_string();
      }
      i++;
    }
    break;
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
        printf("Nao pode introduzir letras ou simbolos.\n");
        printf("Tente de novo: ");
        free(inteiro);
        return prot_int();
      }
      i++;
    }
    break;
  }
  return atoi(inteiro);
}

int prot_int_bi() {
  char *inteiro = (char *) malloc(MAX_CHAR * sizeof(char));
  while (scanf(" %[^\n]", inteiro) ) {
    int i = 0;
    int len = strlen(inteiro);
    while (i < len) {
      if (inteiro[i] < '0' || inteiro[i] > '9') {
        printf("Nao pode introduzir letras ou simbolos.\n");
        printf("Tente de novo: ");
        free(inteiro);
        return prot_int_bi();
      }
      i++;
    }
    break;
  }
  if (strlen(inteiro) != 8) {
    printf("Numero tem que ter 8 digitos.\n");
    printf("Tente de novo: ");
    free(inteiro);
    return prot_int_bi();
  }
  return atoi(inteiro);
}

struct Data prot_data() {
  struct Data data;
  int dia, mes, ano;
  printf("Data Ano: ");
  ano = prot_int();
  while (ano <= 0) {
    printf("Ano invalido.\nData ano: ");
    ano = prot_int();
  }
  printf("Data Mes: ");
  mes = prot_int();
  while (mes <= 0 || mes > 12) {
    printf("Mes invalido.\nData mes: ");
    mes = prot_int();
  }
  printf("Data Dia: ");
  dia = prot_int();
  while (dia <= 0 || dia > 31 || (dia == 31 && mes == 2) || (dia == 31 && mes == 4) || (dia == 31 && mes == 6) || (dia == 31 && mes == 9) || (dia == 31 && mes == 11) || (dia == 30 && mes == 2)) {
    printf("Dia invalido.\nData dia: ");
    dia = prot_int();
  }
  data.dia = dia;
  data.mes = mes;
  data.ano = ano;
  return data;
}
