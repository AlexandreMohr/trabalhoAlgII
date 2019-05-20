#include<stdio.h>
#include <stdlib.h>
#include "jogo.h"
#include <memory.h>

void main(int argc, char *argv[]){
  int linhas,colunas;
  FILE *arq; //ponteiro para abertura do arquivo

  printf("\n\tColheita miserável\n");
  printf("\n\tPara controlar o personagem utilize as teclas \'w\' \'a\' \'s\' \'d\'\n");
  printf("\tAo inserir o caractere \'.\', durante a execução, o jogo é finalizado");

  Personagem p;
  inicia_personagem(&p);


  arq = fopen("mapa.txt", "r");


	if (!arq){ //erro na abertura do arquivo
		printf("\n\t erro na abertura do arquivo");
		return;
	}


  char **mapa = leitura_mapa(arq,&linhas,&colunas);



  char var;



  do{
    printa_mapa(mapa,&linhas,&colunas,&p);

    system("stty raw");
    var = getchar();
    //scanf("%c",&var);

    system("stty cooked");

    movimenta(&p,var,&linhas,&colunas);


    for(long int i=0;i<50000000;i++);

    fflush(stdin);


  }while(var!='.');



  fclose(arq);

	free(mapa);


}



void inicia_personagem(Personagem *p){

  printf("\n\n\tInsira o nome do personagem\n\t");
  fgets(p->nome,30,stdin);

  p->posicao[0] = 0;
  p->posicao[1] = 0;
  p->saude = 100;
  p->fome = 0;




  printf("\n\n\n");

}

void movimenta(Personagem *p, char comando,int *linhas, int *colunas){

  if(comando=='w')
    p->posicao[1]--;
  else if(comando=='s')
    p->posicao[1]++;
  else if(comando=='a')
    p->posicao[0]--;
  else if(comando=='d')
    p->posicao[0]++;

  if (p->posicao[1]==(*linhas))
    p->posicao[1]=0;
  else if (p->posicao[1]<0)
    p->posicao[1]=(*linhas)-1;


    if (p->posicao[0]==(*colunas)-1)
      p->posicao[0]=0;
    else if (p->posicao[0]<0)
      p->posicao[0]=(*colunas)-2;

}
