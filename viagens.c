#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void adquirir_viagem(list_viagens linked_list_viagens, list_clientes linked_list_clientes) {
  char *nome;
  int numero;
  nome = (char*) malloc(20*sizeof(char));
  printf("Nome do cliente: ");
  scanf("%s", nome );
  printf("Numero de cartao de cidadao: ");
  scanf("%d", &numero );
  list_clientes aux;
  aux = linked_list_clientes;
  while (aux->next != NULL && strcmp(nome, aux->next->cliente.nome) != 0) {
    aux = aux->next;
    printf("Nome do cliente: %s\n",aux->cliente.nome );
    printf("Nao e este cliente\n");
  }
  printf("E este cliente\n");
  aux = aux->next;
  printf("%s\n",aux->cliente.nome );
  list_viagens viagens_adquiridas_cliente;
  viagens_adquiridas_cliente = aux->cliente.viagens_adquiridas;
  //inserir_viagem_em_cliente(viagens_adquiridas_cliente);
}
