#include <stdio.h>
#include <stdlib.h>

typedef struct node *list_clientes;
typedef struct node *list_viagens;

struct Cliente {
  char *nome;
  int numero;
  list_viagens viagens_adquiridas;
  list_viagens viagens_espera;
};

struct Data {
  int dia, mes, ano;
};

struct Viagem {
  char *destino;
  struct Data data;
  list_clientes clientes;
  list_clientes clientes_espera;
};

typedef struct node {
  struct Cliente cliente;
  list_clientes next;
}list_node;

typedef struct node2 {
  struct Viagem viagem;
  list_viagens next;
}list_node2;

void menu();
list_clientes create_list_clientes();
list_viagens create_list_viagens();

int main(int argc, char const *argv[]) {
  menu();
  return 0;
}

void menu() {
  list_clientes linked_list_clientes;
  linked_list_clientes = create_list_clientes();
  list_viagens linked_list_viagens;
  linked_list_viagens = create_list_viagens();
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
