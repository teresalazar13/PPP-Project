#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void adquirir_viagem(list_viagens linked_list_viagens, list_clientes linked_list_clientes) {
  struct Cliente *cliente = procura_cliente(linked_list_clientes);
  inserir_viagem_em_cliente(&cliente->viagens_adquiridas); //recebe a lista de viagens adquiridas do cliente
}

struct Cliente *procura_cliente(list_clientes linked_list_clientes) {
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
  }
  aux = aux->next;
  printf("Cliente: %s\n",aux->cliente.nome );
  return &aux->cliente;
}

void inserir_viagem_em_cliente(list_viagens *linked_list) {
  struct Viagem novaViagem = inserir_dados_viagem();
  list_viagens aux;
  aux = *linked_list;
  while (aux->next != NULL) {
    aux = aux->next;
  }
  aux->next = (list_viagens) malloc(sizeof(list_node2));
  aux = aux->next;
  aux->viagem = novaViagem;
  aux->next = NULL;
}
