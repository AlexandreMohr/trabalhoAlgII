char tipo_plantas[4] = {'A','B','C','D'};
int cresc_plantas[4] = {5, 10, 15, 20};
int satis_plantas[4] = {10, 20, 30, 50};

//struct semente e operadores
typedef struct semente{

  char tipo; //tipos da semente A, B, C, D.
  char estado; //[S]EMENTE, [P]LANTA, [F]RUTO
  int tempo_crescimento; //quão rápido ela vira uma [F]ruta;
  int turno_plantada; // turno em que foi plantada, quando platada vira estado [P]
  int turno_colhida; // turno em que foi plantada, quando platada vira estado [P]
  int satisfacao; //quantos pontos de fome ela tira
  int tempo_morte; //plantada ou comida
  int posicao_inicial[2]; // posições onde ela foi iniciada
  int posicao_plantada[2]; //posições onde foi plantada

}Semente;

void cria_semente(Semente *s){
  int aux;
  aux = (rand()%4);
  s->tipo = tipo_plantas[aux]; //randomizar essa parte
  s->estado = 'S';
  s->tempo_crescimento = cresc_plantas[aux]; //turnos para virar fruto
  s->turno_plantada = -1; //-1 não plantada
  s->turno_colhida = -1; //-1 não colhida
  s->satisfacao = satis_plantas[aux];
  s->tempo_morte = (cresc_plantas[aux]+10);
  s->posicao_inicial[0] = -1; //se -1, não foi colocada
  s->posicao_inicial[1] = -1; //se -1, não foi colocada
  s->posicao_plantada[0] = -1; //se -1, não foi plantada
  s->posicao_plantada[1] = -1; //se -1, não foi plantada
}

int comer_semente(Semente *s){
  //caso retorne -1 é pq é uma planta e não pode ser consumida ainda
  printf("\nConsumindo item...");
  char aux;
  aux = s->estado;
  if(aux == 'S'){
    printf("\nSemente consumida %c com satisfacao %i\n", s->tipo, s->satisfacao);
    return s->satisfacao;
  }

  if('F' == aux && s->turno_colhida != 0 && (s->turno_colhida - s->turno_plantada)<= s->tempo_morte ){
    printf("\nFruta consumida %c com satisfacao %i \n", s->tipo, 2*s->satisfacao);
    return (2*(s->satisfacao));
  }

  else{
    printf("\nEste item está podre...\n");
    return -1;
  }
}

//COME SEMENTE/FRUTA (VERIFICA SE NAO ESTA PODRE TEMPO_MORTE<TURNO COLHIDA - TURNO PLANTADA)
//PLANTA SEMENTE

//Struct da mochila (PILHA) e alguns operadores
typedef struct mochila{

  Semente slot[8];
  int topo;

}Mochila;

void mochila_inicia(Mochila *m){

  Semente S;
  cria_semente(&S);
  m->slot[0] = S;
  m->topo = 0; //mochila vazia

}

int mochila_status(Mochila *m){

  int aux;
  aux = m->topo;
  printf("\nEspaços mochila: %i\n",(7-aux));
  return (7-aux);

}

void mochila_lista(Mochila *m){
  if((m->topo)>=0){
    int i;
    printf("\nItens na mochila:\n\n");
    for(i=0;i<=(m->topo);i++){
      if(m->slot[i].estado == 'S'){
        printf("\t -> Item slot [%i]: Semente %c \n", i, m->slot[i].tipo);
      }
      else{
        printf("\t -> Item slot [%i]: Fruta %c \n", i, m->slot[i].tipo);
      }
      
    }
  }

  else{
    printf("\nMochila vazia.\n\n");
  }

}

//funções mochia/sementes

void pega_semente(Semente *s, Mochila *m){
  printf("\nPegando semente...\n");

  if((m->topo)<7){
    m->topo = ((m->topo)+1);
    m->slot[m->topo] = *s;
    printf("Semente %c apanhada...\n", m->slot[m->topo].tipo);
  }

  else{
    printf("Erro ao pegar semente, mochila cheia.\n");
  }
}

Semente * retira_semente(Mochila *m){
  printf("\nRetirando item...\n");

  if((m->topo)>=0){
    Semente *s_aux;
    s_aux = malloc(sizeof(Semente));
    s_aux  = &m->slot[m->topo];
    m->topo = ((m->topo)-1);
    printf("Semente %c retirada...\n", s_aux->tipo);

    return s_aux;
  }

  else{
    printf("Erro ao retirar semente, mochila vazia.\n");
    return NULL;
  }
} 
