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
    printf("[0 para sair] \n");
    opcao = prot_menu();
    switch (opcao) {
      case 1:
        adquirir_viagem(linked_list_viagens, linked_list_clientes);
      case 2:
        cancelar_viagem(linked_list_clientes);
      case 3:

      case 4: {
        char *destino;
        destino = (char*) malloc((MAX_CHAR + 1) * sizeof(char));
        printf("Destino: ");
        scanf("%s", destino );
        sort_data_antigo_primeiro(linked_list_viagens);
        print_list_viagens(linked_list_viagens, destino); }
      case 5:
        print_viagens_adquiridas(linked_list_clientes);
      case 6:
        print_list_clientes(linked_list_clientes);
      case 7:
        inserir_cliente(linked_list_clientes);
      case 8:
        inserir_viagem(linked_list_viagens);
      case 9: {
        //printa clientes em espera para uma viagem
        struct Viagem *viagem = escolhe_viagem(linked_list_viagens);
        print_list_clientes(viagem->clientes_espera); }
      case 10:
        print_list_todas_viagens(linked_list_viagens);
      case 0:
        return;
      default:
        printf("Operacao invalida. Selecione um numero de 1 a 6. [0 para sair]\n");
    }
  }
}
