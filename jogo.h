typedef struct semente{

  int tempo_crescimento; //quão rápido ela vira uma planta;
  int satisfacao; //quantos pontos de fome ela tira
  char estado; //plantada ou comida
}Semente;

typedef struct mochila{
  Semente semente[8];
}Mochila;

typedef struct personagem{
  char nome[30];
  int saude;
  int fome;
  Mochila m;
  int posicao[2];
}Personagem;




void inicia_personagem(Personagem *p);

void movimenta(Personagem *p, char comando,int *linhas, int *colunas);

char ** leitura_mapa(FILE *arq, int *linha, int *colunas);

void printa_mapa(char **mapa,int *linhas,int *colunas,Personagem *p1);
