#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void adquirir_viagem(list_viagens linked_list_viagens, list_clientes linked_list_clientes) {
  struct Cliente *cliente = procura_cliente(linked_list_clientes);
  struct Viagem *novaViagem = escolhe_viagem(linked_list_viagens);
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
