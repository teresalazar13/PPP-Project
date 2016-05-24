#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void sort_data_recente_primeiro(list_viagens linked_list_viagens) {
  struct Viagem temp;
  list_viagens aux, aux2;
  aux = linked_list_viagens->next;
  aux2 = aux->next;
  while(aux->next!=NULL) {
    while(aux2 != NULL) {
      if (aux->viagem.soma_data < aux2->viagem.soma_data) {
        temp = aux->viagem;
        aux->viagem = aux2->viagem;
        aux2->viagem = temp;
      }
      aux2 = aux2->next;
    }
    aux = aux->next;
    aux2 = aux->next;
  }
}

void sort_data_antigo_primeiro(list_viagens linked_list_viagens) {
  struct Viagem temp;
  list_viagens aux, aux2;
  aux = linked_list_viagens->next;
  aux2 = aux->next;
  while(aux->next!=NULL) {
    while(aux2 != NULL) {
      if (aux->viagem.soma_data > aux2->viagem.soma_data) {
        temp = aux->viagem;
        aux->viagem = aux2->viagem;
        aux2->viagem = temp;
      }
      aux2 = aux2->next;
    }
    aux = aux->next;
    aux2 = aux->next;
  }
}
