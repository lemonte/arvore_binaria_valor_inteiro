// GEANDERSON LEMONTE --- V02


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"


int mostrarOpcoes()
{ // Mostrar opcoes do MENU
  int opcao;
  system("CLS");
  printf("\n\n\n\t=====| MENU |=====\n\n");
  printf("0 - SAIR (Encerrar Programa).\n\n");
  printf("1 - Inserir Valor.\n");
  printf("2 - Buscar valor.\n");
  printf("3 - Remover valor.\n");
  printf("4 - Imprimir todos os valores.\n");
  printf("5 - Imprimir todos os percorrer em Ordem.\n");
  printf("6 - Imprimir todos os percorrer em Pos Ordem.\n");
  printf("7 - Imprimir todos os percorrer em pre Ordem.\n");
  printf("\tInforme OPCAO desejada: ");

  scanf(" %d", &opcao);

  if ((opcao > 5) || (opcao < 0))
  {
    printf("\n\n\n");
    printf("\t+-------------------------------------------------+");
    printf("\t|   ERRO:                                         |");
    printf("\t|                                                 |");
    printf("\t|   OPCAO INVALIDA!!!                             |");
    printf("\t|                                                 |");
    printf("\t|   Tente outra vez.                              |");
    printf("\t+-------------------------------------------------+\n\n");
    system("PAUSE");
  }
  return opcao;
}

int entradaNumero()
{ // SOLICITAR ENTRADA DE DADOS PARA O USUARIO
  int entrada = 0;
  printf("Informe o valor: ");
  scanf("%d", &entrada);
  return entrada;
}

void menu(TNo *raiz)
{ // MENU COM OPCOES PARA SELECIONAR
  int opcao = 0;
  do
  {
    opcao = mostrarOpcoes();
    switch (opcao)
    {
    case 1:
      printf("\n ===== Inserir valor ===== \n");
      int entrada = entradaNumero();
      raiz = inserirValor(raiz, entrada, NULL);
      break;
    case 2:
      printf("\n ===== Buscar valor ===== \n");
      entrada = entradaNumero();
      if (buscarValor(raiz, entrada) == 0)
      {
        printf("\n ===== Valor nao encontrado ===== \n");
      }
      break;
    case 3:
      printf("\n ===== Remover valor ===== \n");
      entrada = entradaNumero();
      raiz = removeArvore(raiz, entrada);
      break;
    case 4:
      printf("\n ===== Imprimindo valores ===== \n");
      if (raiz == NULL)
      {
        printf("\n ===== Arvore vazia ===== \n");
      }
      else
      {
        mostrarValores(raiz);
      }
      break;
    case 5:
      printf("\n ===== ORDEM ===== \n");
      entrada = entradaNumero();
      percorreEmOrdem(raiz);
      break;
    case 6:
      printf("\n ===== POS ORDEM ===== \n");
      entrada = entradaNumero();
      posOrdem(raiz);
      break;
    case 7:
      printf("\n ===== PRE ORDEM ===== \n");
      entrada = entradaNumero();
      preOrdem(raiz);
      break;
    default:
      break;
    }
  } while (opcao != 0);
  printf("\n ===== Saindo do programa ===== \n");
}


// ####### CODIGO PRINCIPAL COM CHAMADA DO MENU ############


int main()
{ // CODIGO PRINCIPAL
  TNo *raiz = NULL;
  menu(raiz);
  return 0;
}
