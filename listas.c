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
  ptr = (list_viagens) malloc(sizeof(list_node2));
  if (ptr != NULL) {
    ptr->next = NULL;
  }
  return ptr;
}

void inserir_cliente(list_clientes linked_list) {
  struct Cliente novoCliente = inserir_dados_cliente();
  list_clientes aux;
  aux = linked_list;
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
  novoCliente.nome = malloc(20 * sizeof(char));
  char nome[20];
  printf("Nome: ");
  scanf("%s", nome);
  strcpy(novoCliente.nome, nome);
  printf("Numero: ");
  scanf("%d",&numero );
  novoCliente.numero = numero;
  novoCliente.viagens_adquiridas = create_list_viagens();
  novoCliente.viagens_espera = create_list_viagens();
  return novoCliente;
}

void inserir_viagem(list_viagens linked_list) {
  struct Viagem novaViagem = inserir_dados_viagem();
  list_viagens aux;
  aux = linked_list;
  while (aux->next != NULL) {
    aux = aux->next;
  }
  aux->next = (list_viagens) malloc(sizeof(list_node2));
  aux = aux->next;
  aux->viagem = novaViagem;
  aux->next = NULL;
}

struct Viagem inserir_dados_viagem() {
  struct Viagem novaViagem;
  novaViagem.destino = malloc(20 * sizeof(char));
  char destino[20];
  struct Data data;
  int dia, mes, ano, soma_data;
  printf("Destino: ");
  scanf("%s", destino);
  strcpy(novaViagem.destino, destino);
  printf("Data Dia/Mes/Ano: ");
  scanf("%d/%d/%d",&dia, &mes, &ano );
  data.dia = dia;
  data.mes = mes;
  data.ano = ano;
  novaViagem.data = data;
  soma_data = ano * 10000 + mes * 100 + dia;
  novaViagem.soma_data = soma_data;
  novaViagem.clientes = create_list_clientes();
  novaViagem.clientes_espera = create_list_clientes();
  return novaViagem;
}
