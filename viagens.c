#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void adquirir_viagem(list_viagens linked_list_viagens, list_clientes linked_list_clientes) {
  struct Cliente *cliente = procura_cliente(linked_list_clientes);
  if (cliente == 0) {
    printf("Cliente nao encontrado.\n");
    return;
  }
  inserir_viagem_em_cliente(&cliente->viagens_adquiridas, linked_list_viagens, *cliente);
}

struct Cliente *procura_cliente(list_clientes linked_list_clientes) {
  char *nome;
  int numero;
  nome = (char*) malloc((MAX_CHAR + 1)*sizeof(char));
  printf("Nome do cliente: ");
  scanf("%s", nome );
  printf("Numero de cartao de cidadao: ");
  scanf("%d", &numero );
  list_clientes aux;
  aux = linked_list_clientes;
  while (aux->next != NULL) {
    if (strcmp(nome, aux->next->cliente.nome) == 0 && aux->next->cliente.numero == numero) {
      printf("Cliente: %s Numero: %d\n",aux->next->cliente.nome, aux->next->cliente.numero );
      return &aux->next->cliente;
    }
    else {
      aux = aux->next;
    }
  }
  return 0;
}

void inserir_viagem_em_cliente(list_viagens *linked_list, list_viagens linked_list_viagens, struct Cliente cliente) {
  struct Viagem *novaViagem = escolhe_viagem(linked_list_viagens);
  if (novaViagem->numero_de_clientes == novaViagem->numero_maximo_de_clientes) {
    printf("Viagem cheia. Sera colocado em lista de espera.\n");
    list_clientes aux2;
    aux2 = novaViagem->clientes_espera;
    while (aux2->next != NULL) {
      aux2 = aux2->next;
    }
    aux2->next = (list_clientes) malloc(sizeof(list_node));
    aux2 = aux2->next;
    aux2->cliente = cliente;
    aux2->next = NULL;
  }
  else {
    novaViagem->numero_de_clientes++; //incrementar o numero de clientes da viagem
    list_viagens aux;
    aux = *linked_list;
    while (aux->next != NULL) {
      aux = aux->next;
    }
    aux->next = (list_viagens) malloc(sizeof(list_node2));
    aux = aux->next;
    aux->viagem = *novaViagem;
    aux->next = NULL;
  }
}

struct Viagem *escolhe_viagem(list_viagens pointer) {
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
  return &aux->viagem;
}
