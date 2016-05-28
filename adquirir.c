#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void adquirir_viagem(list_viagens linked_list_viagens, list_clientes linked_list_clientes) {
  struct Cliente *cliente = procura_cliente(linked_list_clientes);
  struct Viagem *novaViagem = escolhe_viagem(linked_list_viagens);
  int verifica_adquiriu = verifica_adquiriu_viagem(*cliente, *novaViagem);
  int verifica_espera = verifica_espera_viagem(*cliente, *novaViagem);
  if (verifica_adquiriu == 1) {
    printf("Cliente ja adquiriu viagem.\n");
    return;
  }
  if (verifica_espera == 1) {
    printf("Cliente ja esta em lista de espera para viagem.\n");
    return;
  }
  if (novaViagem->numero_de_clientes == novaViagem->numero_maximo_de_clientes) { /*se estiver cheio colocar em lista de espera*/
    printf("Viagem cheia. Sera colocado em lista de espera.\n");
    list_clientes aux_clientes;
    aux_clientes = novaViagem->clientes_espera;
    while (aux_clientes->next != NULL) {
      aux_clientes = aux_clientes->next;
    }
    aux_clientes->next = (list_clientes) malloc(sizeof(list_node));
    aux_clientes = aux_clientes->next;
    aux_clientes->cliente = *cliente;
    aux_clientes->next = NULL;
  }
  else {
    novaViagem->numero_de_clientes++; /*incrementar o numero de clientes da viagem*/
    list_viagens aux;
    aux = cliente->viagens_adquiridas;
    while (aux->next != NULL) {
      aux = aux->next;
    }
    aux->next = (list_viagens) malloc(sizeof(list_node_viagens));
    aux = aux->next;
    aux->viagem = *novaViagem;
    aux->next = NULL;
  }
  escreve_compras_ficheiro(*novaViagem, *cliente);
}

int verifica_adquiriu_viagem(struct Cliente cliente, struct Viagem viagem) {
  list_viagens aux;
  aux = cliente.viagens_adquiridas->next;
  while(aux != NULL) {
    if (aux->viagem.destino == viagem.destino) {
      return 1;
    }
    aux = aux->next;
  }
  return 0;
}

int verifica_espera_viagem(struct Cliente cliente, struct Viagem viagem) {
  list_clientes aux;
  aux = viagem.clientes_espera->next;
  while(aux != NULL) {
    if (aux->cliente.nome == cliente.nome && aux->cliente.numero == cliente.numero) {
      return 1;
    }
    aux = aux->next;
  }
  return 0;
}
