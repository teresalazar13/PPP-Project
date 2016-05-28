#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void cancelar_viagem(list_clientes linked_list_clientes, list_viagens linked_list_viagens) {
  printf("Introduza dados do cliente.\n");
  struct Cliente *cliente = procura_cliente(linked_list_clientes);
  printf("Selecione viagem que pretende cancelar.\n");
  struct Viagem *viagem = escolhe_viagem(cliente->viagens_adquiridas);
  if (viagem == 0) {
    return;
  }
  apaga_compra(*cliente, *viagem);
  if (viagem->clientes_espera->next != NULL) { /*se houver clientes em espera, promover cliente no topo*/
    promover_cliente(viagem, linked_list_clientes);
  }
  else { /*se nao houver clientes em espera, diminuir o numero de clientes que adquiriram a viagem*/
    diminui_numero_clientes(linked_list_viagens, *viagem); /*encontrar a viagem na lista de viagens e diminuir o n de clientes*/
  }
  list_viagens aux, aux_anterior; /*cancelar viagem*/
  aux = cliente->viagens_adquiridas->next;
  aux_anterior = cliente->viagens_adquiridas;
  while (aux != NULL) {
    if (strcmp(aux->viagem.destino, viagem->destino) == 0 && aux->viagem.soma_data == viagem->soma_data) {
      aux_anterior->next = aux->next;
      free(aux);
      break;
    }
    aux = aux->next;
    aux_anterior = aux_anterior->next;
  }
}

void promover_cliente(struct Viagem *viagem, list_clientes linked_list_clientes) {
  list_clientes aux, aux_anterior; /*remover cliente_promover de lista de espera*/
  struct Cliente cliente_promovido = viagem->clientes_espera->next->cliente;
  aux = viagem->clientes_espera->next;
  aux_anterior = viagem->clientes_espera;
  aux_anterior->next = aux->next;
  free(aux);
  list_viagens aux_viagens; /*adicionar viagem a cliente no topo da lista de espera*/
  aux_viagens = cliente_promovido.viagens_adquiridas;
  while (aux_viagens->next != NULL) {
    aux_viagens = aux_viagens->next;
  }
  aux_viagens->next = (list_viagens) malloc(sizeof(list_node_viagens));
  aux_viagens = aux_viagens->next;
  aux_viagens->viagem = *viagem;
  aux_viagens->next = NULL;
  printf("O cliente %s foi promovido.\n",cliente_promovido.nome );
}

void diminui_numero_clientes(list_viagens linked_list_viagens, struct Viagem viagem) {
  list_viagens aux;
  aux = linked_list_viagens->next;
  while (aux != NULL) {
    if (strcmp(aux->viagem.destino, viagem.destino) == 0 && aux->viagem.soma_data == viagem.soma_data) {
      aux->viagem.numero_de_clientes--;
    }
    aux = aux->next;
  }
}

void cancelar_pedido_fila_de_espera(list_viagens linked_list_viagens) {
  printf("Selecione viagem da qual quer cancelar pedido em fila de espera.\n");
  struct Viagem *viagem = escolhe_viagem(linked_list_viagens);
  printf("Introduza dados do cliente em fila de espera para a viagem.\n");
  struct Cliente *cliente = procura_cliente(viagem->clientes_espera);
  if (cliente == 0) {
    return;
  }
  list_clientes aux, aux_anterior;
  aux = viagem->clientes_espera->next;
  aux_anterior = viagem->clientes_espera;
  while (aux != NULL) {
    if (strcmp(aux->cliente.nome, cliente->nome) == 0 && aux->cliente.numero == cliente->numero) {
      aux_anterior->next = aux->next;
      free(aux);
      break;
    }
    aux = aux->next;
    aux_anterior = aux_anterior->next;
  }
  apaga_compra(*cliente, *viagem);
}
