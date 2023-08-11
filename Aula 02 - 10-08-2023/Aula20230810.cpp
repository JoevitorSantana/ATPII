#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define TF 10

char * acaoInput = "Inserir";

void ExibirMenu(){
	printf("##################################### Menu ######################################## \n");
	printf("\n");
	printf("[A] Inserir nomes em uma lista (maximo 10)\n");
	printf("[B] Exibir a Lista\n");
	printf("[C] Ordernar a Lista\n");
	printf("[D] Excluir nomes da lista ate se pressionar <ENTER> ou a string estiver vazia\n");
	printf("[ESC] Sair");
	printf("\n");
	printf("################################################################################### \n");
	printf("\n");
	printf("Escolha uma opcao\n");
}

void ExibirInputNome(int TL) {
	printf("############ %s Nomes ################\n", acaoInput);
	printf("In Name[%d]: ", TL + 1);
}

void OrdenarListaNome(int TL, char listaNome[TF][30]) {
	int x = 0, y = 0;
	char aux[30];
	for(x=0;x<TL;x++){
      for(y=x+1;y<TL;y++){
         if(strcmp(listaNome[x],listaNome[y])>0){
            strcpy(aux,listaNome[x]);
            strcpy(listaNome[x],listaNome[y]);
            strcpy(listaNome[y],aux);
         }
      }
   }
}

int VerificarClienteExiste(char listaNome[TF][30], char auxNome[30]){
	int itBuscaNome = 0, qtdeClienteEncontrado = 0;
	while (itBuscaNome < TF) {
		if (strcmp(auxNome, listaNome[itBuscaNome]) == 0) {
			qtdeClienteEncontrado++;
		}
		itBuscaNome++;
	}
	return qtdeClienteEncontrado;
}

void ExcluirNome(char listaNome[TF][30], int indiceNomeExcluido, int TL) {
	int i = 0, x = 0;
	for (i = indiceNomeExcluido; i < TL - 1; i++) {
		listaNome[i] = listaNome[i+1];
	}
}

int main(void)
{
	char opcao, listaNome[TF][30], auxNome[30];
	int TL = 0, i = 0;
	int indiceNomeExcluido;
	
	do {
		system("cls");
		ExibirMenu();
		opcao = getch();
		switch (toupper(opcao))
		{
			case 'A':
				do {
					if (TL < TF) {
						ExibirInputNome(TL);
						fflush(stdin);
						gets(auxNome);
						if (strcmp(auxNome, "\0") != 0 || strlen(auxNome) > 0) {
							/*VERIFICAR SE JÁ EXISTE COM MESMO NOME */
							
							if (VerificarClienteExiste(listaNome, auxNome) == 0) {
								strcpy(listaNome[TL], auxNome);
								TL++;	
							} else {
								printf("Ja existe alguem com este nome na lista!\n");
								getch();
							}
						}
					} else {
					 	printf("\nLista Cheia\n");
					 	getch();
					}
				} while (TL < TF && strcmp(auxNome, "\0") != 0 || strlen(auxNome) > 0);
				getch();
				break;
			case 'B':
				printf("############ Conteudo da Lista ################\n");
				if (TL == 0) {
					printf("\nLista esta a inserir\n");
				} else {
					for (i = 0; i < TL; i++) {
						printf("\n In Lista[%d] %s \n", i+1, listaNome[i]);
					}
				}
				getch();
				break;
			case 'C':
				printf("############ Ordernar Conteudo da Lista ################\n");
				if (TL == 0) {
					printf("\nLista esta a inserir\n");
				} else {
					OrdenarListaNome(TL, listaNome);
					for (i = 0; i < TL; i++) {
						printf("\n In Lista[%d] %s \n", i+1, listaNome[i]);
					}
				}
				getch();
				break;
			case 'D':
				printf("############ Excluir nomes da Lista ################\n");
				if (TL == 0) {
					printf("\nLista esta a inserir\n");
				} else {
					printf("############ Excluir Nome ################\n");
					printf("Insira o nome: \n");
					fflush(stdin);
					gets(auxNome);
					
					indiceNomeExcluido = VerificarClienteExiste(listaNome, auxNome);
					
					if (indiceNomeExcluido != 0) {
						ExcluirNome(listaNome, indiceNomeExcluido, TL);
						printf("Nome excluido com sucesso!\n");
						TL--;
					} else {
						printf("Nao foi encontrado ninguem com este nome na lista!\n");
					}
				}
				getch();
				break;
		}
		
	} while (opcao != 27);
	
	printf("Fim do programa!\n");
	
	return 0;
}
