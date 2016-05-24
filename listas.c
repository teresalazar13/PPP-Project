#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

list_clientes create_list_clientes() {
  list_clientes ptr;
  ptr = (list_clientes) malloc(sizeof(list_node));
  if (ptr != NULL) {
    ptr->next = NULL;
  }
  return ptr;
}

list_viagens create_list_viagens() {
  list_viagens ptr;
  ptr = (list_viagens) malloc(sizeof(list_node_viagens));
  if (ptr != NULL) {
    ptr->next = NULL;
  }
  return ptr;
}

void inserir_cliente(list_clientes linked_list_clientes) {
  struct Cliente novoCliente = inserir_dados_cliente();
  escreve_cliente_ficheiro(novoCliente);
  list_clientes aux;
  aux = linked_list_clientes;
  while (aux->next != NULL) {
    aux = aux->next;
  }
  aux->next = (list_clientes) malloc(sizeof(list_node));
  aux = aux->next;
  aux->cliente = novoCliente;
  aux->next = NULL;
}

struct Cliente inserir_dados_cliente() {
  int numero;
  struct Cliente novoCliente;
  novoCliente.nome = malloc((MAX_CHAR + 1) * sizeof(char));
  char *nome;
  printf("Nome: ");
  nome = prot_string();
  strcpy(novoCliente.nome, nome);
  printf("Numero: ");
  numero = prot_int_bi();
  novoCliente.numero = numero;
  novoCliente.viagens_adquiridas = create_list_viagens();
  return novoCliente;
}

void inserir_viagem(list_viagens linked_list_viagens) {
  struct Viagem novaViagem = inserir_dados_viagem();
  escreve_viagem_ficheiro(novaViagem);
  list_viagens aux;
  aux = linked_list_viagens;
  while (aux->next != NULL) {
    aux = aux->next;
  }
  aux->next = (list_viagens) malloc(sizeof(list_node_viagens));
  aux = aux->next;
  aux->viagem = novaViagem;
  aux->next = NULL;
}

struct Viagem inserir_dados_viagem() {
  struct Viagem novaViagem;
  struct Data data;
  int soma_data, numero_maximo;
  char *destino;
  printf("Destino: ");
  destino = prot_string();
  novaViagem.destino = malloc((MAX_CHAR + 1) * sizeof(char));
  strcpy(novaViagem.destino, destino);
  data = prot_data();
  novaViagem.data = data;
  soma_data = data.ano * 10000 + data.mes * 100 + data.dia;
  novaViagem.soma_data = soma_data;
  printf("Numero maximo de clientes: ");
  numero_maximo = prot_int();
  novaViagem.numero_maximo_de_clientes = numero_maximo;
  novaViagem.numero_de_clientes = 0;
  novaViagem.clientes_espera = create_list_clientes();
  return novaViagem;
}
