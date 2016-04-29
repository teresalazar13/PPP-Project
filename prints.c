#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void print_list_clientes(list_clientes pointer) {
  list_clientes aux;
  aux = pointer->next;
  while (aux != NULL) {
    printf("Nome: ");
    printf("%s \n",aux->cliente.nome);
    printf("Numero: ");
    printf("%d \n",aux->cliente.numero);
    aux = aux->next;
  }
}

void print_list_viagens(list_viagens pointer, char *destino) {
  list_viagens aux;
  aux = pointer->next;
  while (aux != NULL) {
    if (strcmp(aux->viagem.destino, destino) == 0) {
      printf("Destino: ");
      printf("%s \n",aux->viagem.destino);
      printf("Data: ");
      printf("%d/%d/%d \n",aux->viagem.data.dia, aux->viagem.data.mes, aux->viagem.data.ano );
      printf("Soma Data: ");
      printf("%d \n",aux->viagem.soma_data);
      printf("\n");
    }
    aux = aux->next;
  }
}
