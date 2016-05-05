#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void print_list_clientes(list_clientes linked_list_clientes) {
  list_clientes aux;
  aux = linked_list_clientes->next;
  while (aux != NULL) {
    printf("Nome: ");
    printf("%s \n",aux->cliente.nome);
    printf("Numero: ");
    printf("%d \n",aux->cliente.numero);
    aux = aux->next;
  }
}

void print_list_viagens(list_viagens linked_list_viagens, char *destino) {
  list_viagens aux;
  aux = linked_list_viagens->next;
  while (aux != NULL) {
    if (strcmp(aux->viagem.destino, destino) == 0) {
      printf("Destino: ");
      printf("%s \n",aux->viagem.destino);
      printf("Data: ");
      printf("%d/%d/%d \n",aux->viagem.data.dia, aux->viagem.data.mes, aux->viagem.data.ano );
      printf("Numero de clientes: %d\n",aux->viagem.numero_de_clientes );
      printf("Numero maximo de clientes: %d\n", aux->viagem.numero_maximo_de_clientes );
    }
    aux = aux->next;
  }
}

void print_list_todas_viagens(list_viagens linked_list_viagens) {
  list_viagens aux;
  aux = linked_list_viagens->next;
  while (aux != NULL) {
    printf("Destino: ");
    printf("%s \n",aux->viagem.destino);
    printf("Data: ");
    printf("%d/%d/%d \n",aux->viagem.data.dia, aux->viagem.data.mes, aux->viagem.data.ano );
    printf("Numero de clientes: %d\n",aux->viagem.numero_de_clientes );
    printf("Numero maximo de clientes: %d\n", aux->viagem.numero_maximo_de_clientes );
    aux = aux->next;
  }
}

void print_viagens_adquiridas(list_clientes linked_list_clientes) {
  struct Cliente *cliente = procura_cliente(linked_list_clientes);
  sort_data_recente_primeiro(cliente->viagens_adquiridas);
  list_viagens viagens_adquiridas_cliente = cliente->viagens_adquiridas;
  list_viagens aux;
  aux = viagens_adquiridas_cliente->next;
  while (aux != NULL) {
    printf("Destino: ");
    printf("%s \n",aux->viagem.destino);
    printf("Data: ");
    printf("%d/%d/%d \n",aux->viagem.data.dia, aux->viagem.data.mes, aux->viagem.data.ano );
    aux = aux->next;
  }
}
