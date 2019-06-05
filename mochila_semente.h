#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

//Struct da semente e alguns operadores

typedef struct semente{

  char tipo; //tipos da semente A, B, C, D.
  int tempo_crescimento; //quão rápido ela vira uma planta;
  int turno_plantada; // turno em que foi plantada
  int satisfacao; //quantos pontos de fome ela tira
  char estado; //plantada ou comida
  int posicao_inicial[2]; // posições onde ela foi iniciada
  int posicao_plantada[2]; //posições onde foi plantada

}Semente;

void cria_semente(Semente *s){

  s->tipo = 'A'; //randomizar essa parte
  s->tempo_crescimento = 100; //turnos para virar fruto
  s->turno_plantada = -1; //-1 não plantada
  s->satisfacao = 10;
  s->estado = 'Z'; //redundante? pq se há coord está plantada
  s->posicao_inicial[0] = -1; //se -1, não foi colocada
  s->posicao_inicial[1] = -1; //se -1, não foi colocada
  s->posicao_plantada[0] = -1; //se -1, não foi plantada
  s->posicao_plantada[1] = -1; //se -1, não foi plantada

  printf("\nSemente criada\n\n");

}

//Struct da mochila (PILHA) e alguns operadores

typedef struct mochila{

  Semente semente[8];
  int topo;

}Mochila;

void mochila_inicia(Mochila *m){

  m->topo = -1; //mochila vazia

}

int mochila_status(Mochila *m){

  int aux;
  aux = m->topo;
  printf("\nEspaços mochila: %i\n\n",(7-aux));
  return (7-aux);

}

int main(void) {
  //inicia semente e mochila
  Semente S1;
  cria_semente(&S1);
  Mochila M1;
  mochila_inicia(&M1);

  //funcs para verificar a mochila
  mochila_status(&M1);
 
  printf("FIM\n");
  return 0;
}
