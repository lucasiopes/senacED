#include <stdio.h>
#include <stdlib.h>

typedef struct L {
  int x;
  struct L *ant, *prox;
} listaD;

listaD *ult, *prim;
int tam;

void iniLD(listaD *L) {
  ult = prim = NULL;
  tam = 0;
}

int ordenadoLD(listaD *L){
  listaD *temp = prim;
  while(temp->prox != NULL) {
    if(temp->x > temp->prox->x){
      return 0;
    }
    temp = temp->prox;
  }
  return 1;
}

int vaziaLD(listaD *L) {
  if(tam == 0) {
    printf("<ERRO: lista vazia>\n");
    return 1;
  } 
  else { 
    printf("A lista contem %d elementos\n", tam);
    return 0;
  }
}

void inserirLD(listaD *L, int valor) {
  listaD *novoitem;
  novoitem = (listaD *) malloc(sizeof(listaD));

  if(vaziaLD(L) == 1){ //indev
    listaD *temp = prim;
    while(temp != NULL){
      if(temp->x >= chave){
        temp->ant->prox = novoitem;
        novoitem->prox = temp;
      }
    }
  }
  
  novoitem->x = valor;
  novoitem->prox = NULL;
  novoitem->ant = ult;
  tam++;

  if(prim==NULL) {
    prim = novoitem;
    ult = novoitem;
  }
  else {
    ult->prox = novoitem;
    ult = novoitem;
  }
}

listaD buscarLD(listaD *L, int chave) {
  listaD *temp = prim;
  while(temp != NULL) {
    if(temp->x == chave){
        printf("Valor encontrado\n");
    }
    temp = temp->prox;
  }
  if(temp==NULL) printf("<ERRO: valor não existe>\n");
}

void removerLD(listaD *L, int chave) {
  if(vaziaLD(L)==1) {
    printf("<ERRO: lista vazia>\n");
    return;
  }
  listaD *temp = prim;
  int flag = 0;
  while(temp != NULL) {
    if(temp->x == chave){
      if(temp == prim && temp == ult){
        prim = ult = NULL;
      }
      else if(temp == prim) {
        prim = prim->prox;
        prim->ant = NULL;
      }
      else if(temp == ult) {
        ult = ult->ant;
        ult->prox = NULL;
      }
      else { 
      temp->ant->prox = temp->prox;
      temp->prox->ant = temp->ant;
      }
      printf("Valor removido");
      tam--;
      flag = 1;
    }
    temp = temp->prox;
  }
  if(flag==0) printf("<ERRO: valor não existe>\n");
}

void imprimirLD(listaD *L) {
  listaD *temp = prim;
  while(temp != NULL) {
    printf("Linha: %d Coluna: %d\n",temp->x);
    temp = temp->prox;
  }
}