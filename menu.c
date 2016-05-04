#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

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
      adquirir_viagem(linked_list_viagens, linked_list_clientes);
    }
    else if (opcao == 2) {

    }
    else if (opcao == 3) {

    }
    else if (opcao == 4) {
      char *destino;
      destino = (char*) malloc((MAX_CHAR + 1) * sizeof(char));
      printf("Destino: ");
      scanf("%s", destino );
      sort_data(linked_list_viagens);
      print_list_viagens(linked_list_viagens, destino);
    }
    else if (opcao == 5) {
      print_viagens_adquiridas(linked_list_clientes);
    }
    else if (opcao == 6) {
      print_list_clientes(linked_list_clientes);
    }
    else if (opcao == 7) {
      inserir_cliente(linked_list_clientes);
    }
    else if (opcao == 8) {
      inserir_viagem(linked_list_viagens);
    }
    else if (opcao == 9) {
      //printa clientes em espera para uma viagem
      struct Viagem *viagem = escolhe_viagem(linked_list_viagens);
      print_list_clientes(viagem->clientes_espera);
    }
    else if (opcao == 10) {
      print_list_todas_viagens(linked_list_viagens);
    }
    else if (opcao == -1) {
      break;
    }
    else {
      printf("Operacao invalida. Selecione um numero de 1 a 6. [-1 para sair]\n"); //TO DO VER SE METE MESMO UM NUMERO OU NAO
    }
  }
}
