#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void menu();
list_clientes create_list_clientes();
list_viagens create_list_viagens();
void inserir_cliente(list_clientes linked_list);
struct Cliente inserir_dados_cliente();
void inserir_viagem(list_viagens linked_list);
struct Viagem inserir_dados_viagem();

int main(int argc, char const *argv[]) {
  menu();
  return 0;
}

void menu() {
  list_clientes linked_list_clientes;
  linked_list_clientes = create_list_clientes();
  inserir_cliente(linked_list_clientes);

  list_viagens linked_list_viagens;
  linked_list_viagens = create_list_viagens();
  inserir_viagem(linked_list_viagens);

  int opcao;
  while (1) {
    printf("Pretende: \n");
    printf("1) Adquirir uma viagem \n");
    printf("2) Cancelar uma viagem \n");
    printf("3) Cancelar pedido em fila de espera \n");
    printf("4) Listar todas as viagens de um destino \n");
    printf("5) Listar todas as viagens adquiridas de um cliente \n");
    printf("6) Listar todos os clientes \n");
    printf("[-1 para sair] \n");
    scanf("%d",&opcao);
    if (opcao == 1) {

    }
    else if (opcao == 2) {

    }
    else if (opcao == 3) {

    }
    else if (opcao == 4) {

    }
    else if (opcao == 5) {

    }
    else if (opcao == 6) {

    }
    else if (opcao == -1) {
      break;
    }
    else {
      printf("Operacao invalida. Selecione um numero de 1 a 6. [-1 para sair]\n"); //TO DO VER SE METE MESMO UM NUMERO OU NAO
    }
  }
}

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
  return novaViagem;
}
