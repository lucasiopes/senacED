#include <stdio.h>
#include <stdlib.h>

typedef struct L {
  int x;
  struct L *prox;
} listaE;

listaE *ult, *prim;
int tam;

void iniLE(listaE *L) {
  ult = prim = NULL;
  tam = 0;
}

int vaziaLE(listaE *L) {
  if(tam == 0) {
    printf("<ERRO: lista vazia>\n");
    iniLE(L);
    return 1;
  } 
  else { 
    printf("A lista contem %d elementos\n", tam);
    return 0;
  }
}

void inserirLE(listaE *L, int valor) {
  listaE *novoitem;
  novoitem = (listaE *) malloc(sizeof(listaE));
  
  novoitem->x = valor;
  novoitem->prox = NULL;
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

listaE buscarLE(listaE *L, int chave) {
  listaE *temp = prim;
  while(temp != NULL) {
    if(temp->x == chave){
        printf("Valor encontrado\n");
        return L;
    }
    temp = temp->prox;
  }
  if(temp==NULL) printf("<ERRO: valor não encontrado>\n");
  return NULL;
}

void removerLE(listaE *L, int chave) { //incompleto
  if(vaziaLE(L)==1) {
    printf("<ERRO: lista vazia>\n");
    return;
  }
  listaE *temp = prim;
  int flag = 0;

  if(temp->x == chave) {
    prim = prim->prox;
    printf("Valor removido");
    //free(temp);
    temp = prim;
    tam--;
    flag = 1;
  }
  while(temp->prox != NULL) {
    if(temp->prox->x == chave){
      if(temp->prox == ult) {
        ult = temp;
        ult->prox = NULL;
      }
      else {
        temp->prox = temp->prox->prox;
      }
      printf("Valor removido");
      tam--;
      flag = 1;
    }
    temp->prox = temp->prox->prox;
  }
  if(flag==0) printf("<ERRO: valor não encontrado>\n");
}

void imprimirLE(listaE *L) {
  listaE *temp = prim;
  while(temp != NULL) {
    printf("%d\n", temp->x);
    temp = temp->prox;
  }
}