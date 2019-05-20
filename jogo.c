#include<memory.h>
#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"
#define correcao_caractere 48 //correção da tabela ascII


char ** leitura_mapa(FILE *arq, int *linhas, int *colunas){

	char tamanho_mapa[5];


	rewind(arq); //setando a posicao inicial de leitura do arquivo para 0

	fread(tamanho_mapa,sizeof(char),5,arq);

	*linhas = ((int)tamanho_mapa[0] - correcao_caractere)*10 + ((int)tamanho_mapa[1] - correcao_caractere);
	*colunas = ((int)tamanho_mapa[3] - correcao_caractere)*10 + ((int)tamanho_mapa[4] - correcao_caractere);

	char **mapa = (char **)malloc(*linhas*sizeof(char *)); //alocando o tamanho do mapa em uma matriz

	for (int linha=0; linha<*linhas;linha++){

		mapa[linha] = (char *) malloc(*colunas*sizeof(char));
	}

	if(!mapa){

		printf("\n Problemas em alocar memória");
		return 0;
	}
	fseek(arq,sizeof(char),SEEK_CUR);

	for (int linha=0;linha<*linhas;linha++){ //loop de leitura das *linhas
		for (int coluna=0;coluna<*colunas;coluna++){


			fread(&mapa[linha][coluna],sizeof(char),1,arq); //lendo um caractere do arquivo
		//fread(&mapa[linha],sizeof(char),50,arq); //lendo um caractere do arquivo
		}

	}

	printf("\n\n\tmapa: ");

	return mapa;
}


void printa_mapa(char **mapa,int *linhas,int *colunas, Personagem *p1){

	printf("\n\n");

	printf("\t\t%s",p1->nome);
	printf("\t\tsaude: %i",p1->saude);
	printf("\tfome: %i\n",p1->fome);

	for (int i=0;i<*linhas;i++){

		printf("\t\t");

		for(int j=0;j<*colunas;j++){

			if ((p1->posicao[1]==i) && (p1->posicao[0]==j)){
				printf("\x1b[31m");
				printf("P");
				printf("\x1b[0m");
			}
			else printf("%c",mapa[i][j]);

		}

	}
}
