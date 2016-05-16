#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void ficheiro_viagens(list_viagens linked_list_viagens) {
  FILE *file = fopen("ficheiro_viagens.txt", "r");
  struct Viagem novaViagem;
  char *destino = (char *) malloc(MAX_CHAR * sizeof(char));
  char *dia = (char *) malloc(MAX_CHAR * sizeof(char));
  char *mes = (char *) malloc(MAX_CHAR * sizeof(char));
  char *ano = (char *) malloc(MAX_CHAR * sizeof(char));
  char *numero_maximo_de_clientes= (char *) malloc(MAX_CHAR * sizeof(char));
  int soma_data;
  struct Data data;
  while (fscanf(file, "%[^,\n]", destino) != EOF) {
    fscanf(file, "%[^,\n]", destino);
    novaViagem.destino = malloc((MAX_CHAR + 1) * sizeof(char));
    strcpy(novaViagem.destino, destino);
    fseek(file, 1, SEEK_CUR);
    fscanf(file, "%[^,\n]", dia);
    fseek(file, 1, SEEK_CUR);
    fscanf(file, "%[^,\n]", mes);
    fseek(file, 1, SEEK_CUR);
    fscanf(file, "%[^,\n]", ano);
    data.dia = atoi(dia);
    data.mes = atoi(mes);
    data.ano = atoi(ano);
    novaViagem.data = data;
    soma_data = atoi(ano) * 10000 + atoi(mes) * 100 + atoi(dia);
    novaViagem.soma_data = soma_data;
    fseek(file, 1, SEEK_CUR);
    fscanf(file, "%[^,\n]", numero_maximo_de_clientes);
    fseek(file, 1, SEEK_CUR);
    novaViagem.numero_maximo_de_clientes = atoi(numero_maximo_de_clientes);
    novaViagem.numero_de_clientes = 0;
    novaViagem.clientes_espera = create_list_clientes();
    inserir_viagem_ficheiro(linked_list_viagens, novaViagem);
  }
  fclose(file);
}

void inserir_viagem_ficheiro(list_viagens linked_list_viagens, struct Viagem novaViagem) {
  list_viagens aux;
  aux = linked_list_viagens;
  while (aux->next != NULL) {
    aux = aux->next;
  }
  aux->next = (list_viagens) malloc(sizeof(list_node2));
  aux = aux->next;
  aux->viagem = novaViagem;
  aux->next = NULL;
}

void ficheiro_clientes(list_clientes linked_list_clientes) {
  FILE *file = fopen("ficheiro_clientes.txt", "r");
  struct Cliente novoCliente;
  char *nome = (char *) malloc(MAX_CHAR * sizeof(char));
  char *numero = (char *) malloc(MAX_CHAR * sizeof(char));
  while (fscanf(file, "%[^,\n]", nome) != EOF) {
    fscanf(file, "%[^,\n]", nome);
    novoCliente.nome = malloc((MAX_CHAR + 1) * sizeof(char));
    strcpy(novoCliente.nome, nome);
    fseek(file, 1, SEEK_CUR);
    fscanf(file, "%[^,\n]", numero);
    fseek(file, 1, SEEK_CUR);
    novoCliente.numero = atoi(numero);
    novoCliente.viagens_adquiridas = create_list_viagens();
    inserir_cliente_ficheiro(linked_list_clientes, novoCliente);
  }
  fclose(file);
}

void inserir_cliente_ficheiro(list_clientes linked_list_clientes, struct Cliente novoCliente) {
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

void ficheiro_compras(list_viagens linked_list_viagens, list_clientes linked_list_clientes) {
  FILE *file = fopen("ficheiro_compras.txt", "r");
  char *nome, *numero, *destino, *soma_data;
  nome = (char*) malloc((MAX_CHAR + 1)*sizeof(char));
  numero = (char*) malloc((MAX_CHAR + 1)*sizeof(char));
  destino = (char*) malloc((MAX_CHAR + 1)*sizeof(char));
  soma_data = (char*) malloc((MAX_CHAR + 1)*sizeof(char));
  while (fscanf(file, "%[^,\n]", nome) != EOF) {
    fscanf(file, "%[^,\n]", nome);
    fseek(file, 1, SEEK_CUR);
    fscanf(file, "%[^,\n]", numero);
    fseek(file, 1, SEEK_CUR);
    fscanf(file, "%[^,\n]", destino);
    fseek(file, 1, SEEK_CUR);
    fscanf(file, "%[^,\n]", soma_data);
    fseek(file, 1, SEEK_CUR);

    struct Cliente *cliente;
    list_clientes aux;
    aux = linked_list_clientes;
    while (aux->next != NULL) {
      if (strcmp(nome, aux->next->cliente.nome) == 0 && aux->next->cliente.numero == atoi(numero)) {
        cliente = &aux->next->cliente;
        break;
      }
      else {
        aux = aux->next;
      }
    }

    struct Viagem *viagem;
    list_viagens aux_viagens;
    aux_viagens = linked_list_viagens;
    while (aux_viagens->next != NULL) {
      if (strcmp(destino, aux_viagens->next->viagem.destino) == 0 && aux_viagens->next->viagem.soma_data == atoi(soma_data)) {
        viagem = &aux_viagens->next->viagem;
        break;
      }
      else {
        aux_viagens = aux_viagens->next;
      }
    }
    inserir_viagem_em_cliente_ficheiro(&cliente->viagens_adquiridas, *cliente, viagem);
  }
  fclose(file);
}

void inserir_viagem_em_cliente_ficheiro(list_viagens *viagens_adquiridas, struct Cliente cliente, struct Viagem *novaViagem) {
  if (novaViagem->numero_de_clientes == novaViagem->numero_maximo_de_clientes) { //se estiver cheio colocar em lista de espera
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
}

void escreve_cliente_ficheiro(struct Cliente novoCliente) {
  FILE *file = fopen("ficheiro_clientes.txt", "a");
  fprintf(file, "%s,", novoCliente.nome );
  fprintf(file, "%d\n", novoCliente.numero );
  fclose(file);
}

void escreve_viagem_ficheiro(struct Viagem novaViagem) {
  FILE *file = fopen("ficheiro_viagens.txt", "a");
  fprintf(file, "%s,", novaViagem.destino );
  fprintf(file, "%d,", novaViagem.data.dia );
  fprintf(file, "%d,", novaViagem.data.mes);
  fprintf(file, "%d,", novaViagem.data.ano);
  fprintf(file, "%d\n", novaViagem.numero_maximo_de_clientes);
  fclose(file);
}

void escreve_compras_ficheiro(struct Viagem viagem, struct Cliente cliente) {
  FILE *file = fopen("ficheiro_compras.txt", "a");
  fprintf(file, "%s,", cliente.nome );
  fprintf(file, "%d,", cliente.numero );
  fprintf(file, "%s,", viagem.destino );
  fprintf(file, "%d\n", viagem.soma_data );
  fclose(file);
}
