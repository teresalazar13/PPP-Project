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
