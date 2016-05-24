#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

struct Cliente *procura_cliente(list_clientes linked_list_clientes) {
  char *nome;
  int numero;
  printf("Nome do cliente: ");
  nome = prot_string();
  printf("Numero de cartao de cidadao: ");
  numero = prot_int();
  list_clientes aux;
  aux = linked_list_clientes;
  while (aux->next != NULL) {
    if (strcmp(nome, aux->next->cliente.nome) == 0 && aux->next->cliente.numero == numero) {
      return &aux->next->cliente;
    }
    else {
      aux = aux->next;
    }
  }
  printf("Cliente nao existente.\n");
  return procura_cliente(linked_list_clientes);
}

struct Viagem *escolhe_viagem(list_viagens linked_list_viagens) {
  list_viagens aux;
  aux = linked_list_viagens->next;
  int i = 1;
  int j = 1;
  while (aux != NULL) {
    printf("Viagem %d\n", i);
    printf("Destino: %s\n",aux->viagem.destino);
    printf("Data: %d/%d/%d\n",aux->viagem.data.dia, aux->viagem.data.mes, aux->viagem.data.ano );
    aux = aux->next;
    i++;
    j++;
  }
  int opcao;
  printf("Numero da viagem que pretende: ");
  opcao = prot_int();
  aux = linked_list_viagens->next;
  i = 1;
  while (aux != NULL && i != opcao ) {
    aux = aux->next;
    i++;
  }
  if (i == opcao && opcao != j) {
    return &aux->viagem;
  }
  else {
    printf("Operacao invalida. Tente de novo.\n");
    return escolhe_viagem(linked_list_viagens);
  }
}
