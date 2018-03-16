#include <stdio.h>
#include <stdlib.h>

typedef struct F {
  int x;
  struct F *prox;
} listaD;

listaD *topo;
int tam;

void iniF(listaD *L) {
  topo = NULL;
  tam = 0;
}

int vaziaF(listaD *L) {
  if(tam == 0) {
    printf("<ERRO: fila vazia>\n");
    return 1;
  } 
  else { 
    printf("A fila contem %d elementos\n", tam);
    return 0;
  }
}

void inserirF(listaD *L, int valor) {
  listaD *novoitem;
  novoitem = (listaD *) malloc(sizeof(listaD));
  novoitem->x = valor;
  novoitem->prox = NULL;
  tam++;

  if(topo==NULL) {
    topo = novoitem;
  }
  else {
    listaD *temp = topo;
    while(temp->prox != NULL){
      temp = temp->prox;
    }
    temp->prox = novoitem;
  }
}

void buscarF(listaD *L, int chave) {
  listaD *temp = topo;
  while(temp != NULL) {
    if(temp->x == chave){
        printf("Valor encontrado\n");
    }
    temp = temp->prox;
  }
  if(temp==NULL) printf("<ERRO: valor não existe>\n");
}

void removerF(listaD *L) {
  if(vaziaF(L)==1) {
    printf("<ERRO: lista vazia>\n");
    return;
  }
  listaD *temp = topo;
  topo = topo->prox;
  
  temp = NULL;
  free(temp);
}
void imprimirF(listaD *L) {
  listaD *temp = topo;
  while(temp != NULL) {
    printf("Linha: %d Coluna: %d\n",temp->x);
    temp = temp->prox;
  }
}