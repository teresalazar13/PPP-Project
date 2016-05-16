#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void adquirir_viagem(list_viagens linked_list_viagens, list_clientes linked_list_clientes) {
  struct Cliente *cliente = procura_cliente(linked_list_clientes);
  if (cliente == 0) { //caso cliente nao exista
    printf("Cliente nao encontrado.\n");
    return;
  }
  inserir_viagem_em_cliente(&cliente->viagens_adquiridas, linked_list_viagens, *cliente);
}

void inserir_viagem_em_cliente(list_viagens *viagens_adquiridas, list_viagens linked_list_viagens, struct Cliente cliente) {
  struct Viagem *novaViagem = escolhe_viagem(linked_list_viagens);
  if (novaViagem == 0) { //caso viagem nao exista
    printf("Viagem nao existente\n");
    return;
  }
  if (novaViagem->numero_de_clientes == novaViagem->numero_maximo_de_clientes) { //se estiver cheio colocar em lista de espera
    printf("Viagem cheia. Sera colocado em lista de espera.\n");
    list_clientes aux_clientes;
    aux_clientes = novaViagem->clientes_espera;
    while (aux_clientes->next != NULL) {
      aux_clientes = aux_clientes->next;
    }
    aux_clientes->next = (list_clientes) malloc(sizeof(list_node));
    aux_clientes = aux_clientes->next;
    aux_clientes->cliente = cliente;
    aux_clientes->next = NULL;
  }
  else {
    novaViagem->numero_de_clientes++; //incrementar o numero de clientes da viagem
    list_viagens aux;
    aux = *viagens_adquiridas;
    while (aux->next != NULL) {
      aux = aux->next;
    }
    aux->next = (list_viagens) malloc(sizeof(list_node2));
    aux = aux->next;
    aux->viagem = *novaViagem;
    aux->next = NULL;
  }
  escreve_compras_ficheiro(*novaViagem, cliente);
}

void cancelar_viagem(list_clientes linked_list_clientes) {
  struct Cliente *cliente = procura_cliente(linked_list_clientes);
  if (cliente == 0) { //caso cliente nao exista
    printf("Cliente nao encontrado.\n");
    return;
  }
  struct Viagem *viagem = escolhe_viagem(cliente->viagens_adquiridas);
  if (viagem == 0) { //caso viagem nao exista
    printf("Viagem nao existente\n");
    return;
  }
  list_viagens aux, aux_anterior;
  aux = cliente->viagens_adquiridas->next;
  aux_anterior = cliente->viagens_adquiridas;
  while (aux != NULL && (strcmp(aux->viagem.destino, viagem->destino) != 0 || aux->viagem.soma_data != viagem->soma_data)) {
    aux = aux->next;
    aux_anterior = aux_anterior->next;
  }
  if (aux->next!=NULL) {
    list_viagens n;
    aux->viagem = aux->next->viagem;
    n = aux->next;
    aux->next = aux->next->next;
    free(n->next);
    free(n);
  }
  else {
    free(aux->next);
    free(aux);
    aux_anterior->next = NULL;
  }
}

/*
void promover_cliente() {

}
*/

void cancelar_pedido_fila_de_espera(list_viagens linked_list_viagens) {
  struct Viagem *viagem = escolhe_viagem(linked_list_viagens);
  if (viagem == 0) { //caso viagem nao exista
    printf("Viagem nao existente\n");
    return;
  }
  struct Cliente *cliente = procura_cliente(viagem->clientes_espera);
  if (cliente == 0) { //caso cliente nao exista
    printf("Cliente nao encontrado ou nao esta em lista de espera.\n");
    return;
  }
  list_clientes aux, aux_anterior;
  aux = viagem->clientes_espera->next;
  aux_anterior = viagem->clientes_espera;
  while (aux != NULL && (strcmp(aux->cliente.nome, cliente->nome) != 0 || aux->cliente.numero != cliente->numero)) {
    aux = aux->next;
    aux_anterior = aux_anterior->next;
  }
  if (aux->next!=NULL) {
    list_clientes n;
    aux->cliente = aux->next->cliente;
    n = aux->next;
    aux->next = aux->next->next;
    free(n->next);
    free(n);
  }
  else {
    free(aux->next);
    free(aux);
    aux_anterior->next = NULL;
  }
}
