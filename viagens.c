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
  /*
  struct Cliente cliente = *procura_cliente(linked_list_clientes);
  struct Viagem viagem = *escolhe_viagem(cliente.viagens_adquiridas);
  list_viagens aux;
  aux = cliente->next;
  while (aux != NULL) {
    printf("%s\n", aux->viagem.destino);
    printf("%s\n", viagem.destino);
    printf("%d\n", aux->viagem.soma_data);
    printf("%d\n", viagem.soma_data);
    if (strcmp(aux->viagem.destino, viagem.destino) == 0 && aux->viagem.soma_data == viagem.soma_data) {
      list_viagens n;
      //Copy the data of next node to head
      aux->viagem = aux->next->viagem;
      //store address of next node
      n = aux->next;
      //Remove the link of next node
      aux->next = aux->next->next;
      //free memory
      free(n);
    }
    else {
      aux = aux->next;
    }
  }
  */
}

void cancelar_pedido_fila_de_espera(list_clientes linked_list_clientes) {

}
