#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void sort_data(list_viagens a) {
  int n = 0;
  struct Viagem temp;
  list_viagens aux, aux2;
  aux = a->next;
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
