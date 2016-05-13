#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

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
      return &aux->next->cliente;
    }
    else {
      aux = aux->next;
    }
  }
  return 0;
}

struct Viagem *escolhe_viagem(list_viagens linked_list_viagens) {
  list_viagens aux;
  aux = linked_list_viagens->next;
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
  aux = linked_list_viagens->next;
  i = 1;
  while (aux != NULL && i != opcao ) {
    aux = aux->next;
    i++;
  }
  if (i == opcao) {
    return &aux->viagem;
  }
  else {
    return 0;
  }
}
