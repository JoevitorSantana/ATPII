/* ..:: IMPLEMENTAR ::..
	..:: Mostrar o menu e implementar as seguintes operacoes ::..
		[A] Inserir nomes em uma lista (maximo 10)
			-> deve-se parar quando se pressionar <ENTER> ou quando encher a Lista;
			-> Nao deve ser possivel cadastrar nomes iguais;
		[B] Exibir a Lista
		[C] Ordernar a Lista
		[D] Excluir nomes da lista ate se pressionar <ENTER> ou a string estiver vazia;
*/		

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define TF;

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

int main(void)
{
	char opcao, listaNomes[TF][TF], nome[TF];
	int counter = 0;
	
	do {
		ExibirMenu();
		
		/** getch() Obtêm o caractere inputado **/
		opcao = getch();
		
		switch (toupper(opcao))
		{
			case 'A':
				do {
					printf("Insira um nome: \n");
					gets(listaNome[counter]);
				} while (counter <= 10 && nome != 27);
				break;
			case 'B':
				break;
			case 'C':
				break;
			case 'D':
				break;
		}
		
	} while (opcao != 27);
	
	printf("Fim do programa!\n");
	
	return 0;
}
