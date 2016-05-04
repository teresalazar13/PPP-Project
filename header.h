#define MAX 2

typedef struct node *list_clientes;
typedef struct node2 *list_viagens;

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
  int soma_data;
  int numero_de_clientes;
  int numero_maximo_de_clientes;
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
void inserir_cliente(list_clientes linked_list);
struct Cliente inserir_dados_cliente();
void inserir_viagem(list_viagens linked_list);
struct Viagem inserir_dados_viagem();
void print_list_clientes(list_clientes pointer);
void print_list_viagens(list_viagens pointer, char *destino);
void sort_data(list_viagens a);
void adquirir_viagem(list_viagens linked_list_viagens, list_clientes linked_list_clientes);
struct Cliente *procura_cliente(list_clientes linked_list_clientes);
void inserir_viagem_em_cliente(list_viagens *linked_list, list_viagens linked_list_viagens);
void print_viagens_adquiridas(list_clientes linked_list_clientes);
void sort_data_recente_primeiro(list_viagens a);
struct Viagem escolhe_viagem(list_viagens pointer);
