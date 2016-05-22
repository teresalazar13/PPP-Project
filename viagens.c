#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void adquirir_viagem(list_viagens linked_list_viagens, list_clientes linked_list_clientes) {
  struct Cliente *cliente = procura_cliente(linked_list_clientes);
  if (cliente == 0) { /*caso cliente nao exista*/
    printf("Cliente nao encontrado.\n");
    return;
  }
  inserir_viagem_em_cliente(&cliente->viagens_adquiridas, linked_list_viagens, *cliente);
}

void inserir_viagem_em_cliente(list_viagens *viagens_adquiridas, list_viagens linked_list_viagens, struct Cliente cliente) {
  struct Viagem *novaViagem = escolhe_viagem(linked_list_viagens);
  if (novaViagem == 0) { /*caso viagem nao exista*/
    printf("Viagem nao existente\n");
    return;
  }
  if (novaViagem->numero_de_clientes == novaViagem->numero_maximo_de_clientes) { /*se estiver cheio colocar em lista de espera*/
    printf("Viagem cheia. Sera colocad em lista de espera.\n");
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
    novaViagem->numero_de_clientes++; /*incrementar o numero de clientes da viagem*/
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

void cancelar_viagem(list_clientes linked_list_clientes, list_viagens linked_list_viagens) {
  struct Cliente *cliente = procura_cliente(linked_list_clientes);
  if (cliente == 0) { /*caso cliente nao exista*/
    printf("Cliente nao encontrado.\n");
    return;
  }
  struct Viagem *viagem = escolhe_viagem(cliente->viagens_adquiridas);
  if (viagem == 0) { /*caso viagem nao exista*/
    printf("Viagem nao existente.\n");
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
  aux_viagens->next = (list_viagens) malloc(sizeof(list_node2));
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
  struct Viagem *viagem = escolhe_viagem(linked_list_viagens);
  if (viagem == 0) { /*caso viagem nao exista*/
    printf("Viagem nao existente\n");
    return;
  }
  struct Cliente *cliente = procura_cliente(viagem->clientes_espera);
  if (cliente == 0) { /*caso cliente nao exista*/
    printf("Cliente nao encontrado ou nao esta em lista de espera.\n");
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
