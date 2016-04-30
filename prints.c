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

struct Viagem escolhe_viagem(list_viagens pointer) {
  list_viagens aux;
  aux = pointer->next;
  int i = 1;
  while (aux != NULL) {
    printf("Viagem %d\n", i );
    printf("Destino: ");
    printf("%s \n",aux->viagem.destino);
    printf("Data: ");
    printf("%d/%d/%d \n",aux->viagem.data.dia, aux->viagem.data.mes, aux->viagem.data.ano );
    aux = aux->next;
    i++;
  }
  int opcao;
  printf("Numero da viagem que pretende: ");
  scanf("%d",&opcao );
  aux = pointer->next;
  i = 1;
  while (aux != NULL && i != opcao ) {
    aux = aux->next;
    i++;
  }
  return aux->viagem;
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

void print_viagens_adquiridas(list_clientes linked_list_clientes) {
  struct Cliente *cliente = procura_cliente(linked_list_clientes);
  sort_data_recente_primeiro(cliente->viagens_adquiridas);
  list_viagens pointer = cliente->viagens_adquiridas;
  list_viagens aux;
  aux = pointer->next;
  while (aux != NULL) {
    printf("Destino: ");
    printf("%s \n",aux->viagem.destino);
    printf("Data: ");
    printf("%d/%d/%d \n",aux->viagem.data.dia, aux->viagem.data.mes, aux->viagem.data.ano );
    printf("Soma Data: ");
    printf("%d \n",aux->viagem.soma_data);
    printf("\n");
    aux = aux->next;
  }
}
