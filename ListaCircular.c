#include <stdio.h>
#include <stdlib.h>

typedef struct L {
  int x,index;
  struct L *ant, *prox;
} listaD;

listaD *ult, *prim;
int tam;

void iniLC(listaD *L) {
  ult = prim = NULL;
  tam = 0;
}

int vaziaLC(listaD *L) {
  if(tam == 0) {
    printf("<ERRO: lista vazia>\n");
    return 1;
  } 
  else { 
    printf("A lista contem %d elementos\n", tam);
    return 0;
  }
}

void buscarLC(listaD *L, int chave) {
  listaD *temp = prim;
  while(temp->prox != prim) {
    if(temp->x == chave){
        printf("Valor encontrado no %dº item\n", temp->index);
    }
    temp =  temp->prox;
  }
  if(temp==prim) printf("<ERRO: valor não existe>\n");
}

void inserirLC(listaD *L, int valor) {
  listaD *novoitem;
  novoitem = (listaD *) malloc(sizeof(listaD));
  
  novoitem->x = valor;
  novoitem->prox = NULL;
  novoitem->ant = ult;
  tam++;
  novoitem->index = tam;

  if(prim==NULL) {
    prim = novoitem;
    prim->ant = ult;

    ult = novoitem;
    ult->prox = prim;
  }
  else {
    ult->prox = novoitem;
    ult = novoitem;
    ult->prox = prim;
  }
}

void remvalorLC(listaD *L, int chave) {
  if(vaziaLC(L)==1) {
    printf("<ERRO: lista vazia>\n");
    return;
  }
  listaD *temp = prim;
  int flag = 0;
  while(temp->prox != prim) {
    if(temp->index == chave){
      if(temp == prim && temp == ult){
          free(prim);
          free(ult);
          free(temp);
          prim = ult = NULL;
      }
      else if(temp == prim) {
        prim = prim->prox;
        prim->ant = ult;
        free(temp);
      }
      else if(temp == ult) {
        ult = ult->ant;
        ult->prox = prim;
        free(temp);
      }
      else { 
      temp->ant->prox = temp->prox;
      temp->prox->ant = temp->ant;
      free(temp); //null temp?
      }
      tam--;
      flag = 1;
    }
    temp = temp->prox;
  }
  if(flag == 0) printf("<ERRO: valor não existe>\n");
}

/* void remposLC(listaD *L, int chave) {
  if(vaziaLC(L)==1) {
    printf("<ERRO: lista vazia>\n");
    return;
  }
  listaD *temp = prim;
  while(temp->prox != prim) {
    if(temp->index == chave){
      if(temp == prim && temp == ult){
          free(prim);
          free(ult);
          free(temp);
          prim = ult = NULL;
      }
      else if(temp == prim) {
        prim = prim->prox;
        prim->ant = ult;
        free(temp);
      }
      else if(temp == ult) {
        ult = ult->ant;
        ult->prox = prim;
        free(temp);
      }
      else { 
      temp->ant->prox = temp->prox;
      temp->prox->ant = temp->ant;
      free(temp); //null temp?
      }
      tam--;
      return;
    }
    temp = temp->prox;
  }
  if(temp==prim) printf("<ERRO: posição não existe>\n");
} */

void imprimirLC(listaD *L) {
  listaD *temp = prim;
  while(temp->prox != prim) {
    printf("%d-> %d\n",temp->index, temp->x);
    temp =  temp->prox;
  }
}