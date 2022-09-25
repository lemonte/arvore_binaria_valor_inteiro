#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipoNo
{
  int valor;
  struct tipoNo *esq, *dir, *pai;
} TNo; // ESTRUTURA UTILIZADA NA ARVORE

TNo *inicializaTNo(TNo *no)
{ // INCIALIZANDO CADA ESTRUTURA DA ARVORE
  no = (TNo *)malloc(sizeof(TNo));
  no->dir = NULL;
  no->esq = NULL;
  no->pai = NULL;
  return no;
}

TNo *inserirValor(TNo *no, int entrada, TNo *noAnterior)
{ // INSERINDO VALOR NA ARVORE
  if (no == NULL)
  {
    no = inicializaTNo(no); // INCIALIZA A ESTRUTURA A SER ADICIONADA
    no->valor = entrada;
  }
  else if (no->valor == entrada)
  { // VERIFICA SE JA EXISTE O VALOR NA ARVORE
    printf("Valor ja inserido na arvore");
  }
  else if (no->valor < entrada)
  { // PERCORRE A ARVORE PELA DIREITA
    no->dir = inserirValor(no->dir, entrada, no);
  }
  else
  { // PERCORRE A ARVORE PELA ESQUERDA
    no->esq = inserirValor(no->esq, entrada, no);
  }
  return no; // RETORNA A ARVORE
}

TNo *removeArvore(TNo *nodo, int entrada)
{ // REMOVENDO ELEMENTO DA ARVORE
  if (nodo == NULL)
  { // CASO PERCORRA A LISTA E NAO ENCONTRE MOSTRE QUE O VALOR NAO FOI ENCONTRADO
    printf("Valor nao encontrado");
    return nodo;
  }
  else if (entrada > nodo->valor)
  { // CASO O VALOR SEJE MAIOR QUE O TOPO DA ARVORE, CONTINUE PERCORRENDO PELA DIREITA
    nodo->dir = removeArvore(nodo->dir, entrada);
  }
  else if (entrada < nodo->valor)
  { // CASO O VALOR SEJE MENOR QUE O TOPO DA ARVORE CONTINUE PERCORRENDO PELA ESQUERDA
    nodo->esq = removeArvore(nodo->esq, entrada);
  }
  else if (nodo->esq == NULL && nodo->dir == NULL)
  { // SE É O VALOR PROCURADO E O LADO DIREITO E ESQUERDO ESTAO VAZIOS, REMOVA O ELEMENTO DA MEMORIA
    free(nodo);
    printf("ELEMENTO REMOVIDO \n");
    nodo = NULL;
  }
  else
  {                            // CASO SEJA O ELEMENTO PROCURADO E POSSUA ELEMENTO PELA ESQUERDA OU PELA DIREITA
    TNo *atual = nodo;         // ATUAL RECEBE O PONTEIRO DO VALOR A SER INSERIDO
    TNo *esquerda = nodo->esq; // ESQUERDA RECEBE O PROXIMO ELEMENTO A ESQUERDA
    nodo = nodo->dir;          // TOPO DA ARVORE RECEBE O VALOR DA DIREITA
    while (esquerda != NULL)
    {                                            // ENQUANTO HOUVER ELEMENTO PELA ESQUERDA, CONTINUE REINSERINDO NOVAMENTE O VALOR NA LISTA
      inserirValor(nodo, esquerda->valor, NULL); // INSERE O VALOR NOVAMENTE NA LISTA
      esquerda = esquerda->esq;                  // VAI PARA O PROXIMO ELEMENTO A ESQUERDA
    }
    printf("ELEMENTO REMOVIDO \n"); // MOSTRAR QUE O ELEMENTO FOI REMOVIDO
    free(atual); // REMOVENDO DA MEMORIA
    atual = NULL; // DEFININDO ATUAL COMO NULL
  }
  return nodo; // RETORNANDO ARVORE
}

void percorreEmOrdem(TNo *no)
{ // PERCORRENDO A ARVORE EM ORDEM
  if (no != NULL)
  {
    percorreEmOrdem(no->esq);
    printf("%d \n", no->valor);
    percorreEmOrdem(no->dir);
  }
  else
  {
    printf("Arvore esta vazia");
  }
}

void preOrdem(TNo *no)
{ // PERCORRENDO ARVORE EM PRE ORDEM
  if (no != NULL)
  {
    printf("%d \n", no->valor);
    preOrdem(no->esq);
    preOrdem(no->dir);
  }
  else
  {
    printf("Arvore esta vazia");
  }
}

void posOrdem(TNo *no)
{ // PERCORRENDO ARVORE EM POS ORDEM
  if (no != NULL)
  {
    posOrdem(no->esq);
    posOrdem(no->dir);
    printf("%d \n", no->valor);
  }
  else
  {
    printf("Arvore esta vazia");
  }
}

void mostrarValores(TNo *no)
{ // MOSTRANDO TODOS OS VALORES
  if (no != NULL)
  {
    printf("valor -> %d \n", no->valor);
    TNo *dirAtual = no->dir;
    if (dirAtual != NULL)
    {
      mostrarValores(dirAtual);
    }
    TNo *esqAtual = no->esq;
    if (esqAtual != NULL)
    {
      mostrarValores(esqAtual);
    }
  }
}

int buscarValor(TNo *no, int valor_procurado)
{ // BUSCANDO VALOR NA LISTA
  if (no != NULL)
  {
    if (no->valor == valor_procurado)
    {
      printf("valor encontrado-> %d \n", no->valor);
      return 1;
    }
    TNo *dirAtual = no->dir;
    if (dirAtual != NULL)
    {
      if (buscarValor(dirAtual, valor_procurado) == 1)
      {
        return 1;
      };
    }
    TNo *esqAtual = no->esq;
    if (esqAtual != NULL)
    {
      if (buscarValor(esqAtual, valor_procurado) == 1)
      {
        return 1;
      };
    }
  }
  return 0;
}