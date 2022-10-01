#include <stdio.h>
#include <stdlib.h>

void inserirElemento(int *vetor, int elemento, int *tamanho) {
    printf("tamanho antes: %d\n", *tamanho);
    
    if (*tamanho != 0)
    {
        vetor = realloc(vetor, *tamanho+1);
    }
    else{
        printf("tamanho é igual a 0\n");
    }
    
    vetor[ *tamanho] = elemento; 
   *tamanho = *tamanho + 1;
    
    printf("tamanho depois: %d\n", *tamanho);

    return;
}

void exibirLista(int *vetor, int *tamanho) {

  printf("%d", *tamanho);
  for (int i = 0; i < *tamanho; i++) {
    printf("%d\n", vetor[i]);
  }
}

void liberarMemoria(int *vetor) { free(vetor); }

int menu() {
  int opcao;
  printf("1. Inserir elemento; \n2. Exibir lista; \n3. Liberar memória. \n4. "
         "Sair.\n");
  scanf("%d", &opcao);
  return opcao;
}

int main() {
  int tamanho = 0;
  int *vet, opcao, elemento;
  vet = (int*)malloc(1*sizeof(int));

  while (1) {
    opcao = menu();

    if (opcao == 1) 
    {
      printf("Digite o elemento que deseja inserir: ");
      scanf("%d", &elemento);
      inserirElemento(vet, elemento, &tamanho);
       for(int i = 0; i< tamanho ; i++)
        {
            printf("%d\n",vet[i] );
        }
    } 
    else if (opcao == 2) 
    {
      printf("chamou\n");
      exibirLista(vet, tamanho);
    } 
    else if (opcao == 3) 
    {
      liberarMemoria(vet);
    } 
    else if (opcao == 4) 
    {
      break;
    } 
    else 
    {
      printf("Opção inválida. ");
      menu();
    }
  }

  for (int i = 0; i < tamanho; i++) {
    scanf("%d", &vet[i]);
  }

  return 0;
}
