typedef struct node *list_clientes;
typedef struct node2 *list_viagens;

#define MAX_CHAR 32

struct Cliente {
  char *nome;
  int numero;
  list_viagens viagens_adquiridas;
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
void inserir_cliente(list_clientes linked_list_clientes);
struct Cliente inserir_dados_cliente();
void inserir_viagem(list_viagens linked_list_viagens);
struct Viagem inserir_dados_viagem();
void print_list_clientes(list_clientes linked_list_clientes);
void print_list_viagens(list_viagens linked_list_viagens);
void print_viagens_adquiridas(list_clientes linked_list_clientes);
void print_list_todas_viagens(list_viagens linked_list_viagens);
void sort_data_antigo_primeiro(list_viagens linked_list_viagens);
void sort_data_recente_primeiro(list_viagens linked_list_viagens);
void adquirir_viagem(list_viagens linked_list_viagens, list_clientes linked_list_clientes);
struct Cliente *procura_cliente(list_clientes linked_list_clientes);
void inserir_viagem_em_cliente(list_viagens *linked_list, list_viagens linked_list_viagens, struct Cliente cliente);
struct Viagem *escolhe_viagem(list_viagens linked_list_viagens);
void cancelar_viagem(list_clientes linked_list_clientes, list_viagens linked_list_viagens);
void cancelar_pedido_fila_de_espera(list_viagens linked_list_viagens);
void diminui_numero_clientes(list_viagens linked_list_viagens, struct Viagem viagem);
void promover_cliente(struct Viagem *viagem, list_clientes linked_list_clientes);
int prot_menu();
char *prot_string();

void ficheiro_viagens(list_viagens linked_list_viagens);
void inserir_viagem_ficheiro(list_viagens linked_list_viagens, struct Viagem novaViagem);
void ficheiro_clientes(list_clientes linked_list_clientes);
void inserir_cliente_ficheiro(list_clientes linked_list_clientes, struct Cliente novoCliente);
void ficheiro_compras(list_viagens linked_list_viagens, list_clientes linked_list_clientes);
void inserir_viagem_em_cliente_ficheiro(list_viagens *viagens_adquiridas, struct Cliente cliente, struct Viagem *novaViagem);
void escreve_cliente_ficheiro(struct Cliente novoCliente);
void escreve_viagem_ficheiro(struct Viagem novaViagem);
void escreve_compras_ficheiro(struct Viagem viagem, struct Cliente cliente);
void apaga_compra(struct Cliente cliente, struct Viagem viagem);
