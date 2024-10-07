#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct {
   char nome[MAX];
   int gols;} tTimeGols;

typedef struct {
   tTimeGols time1;
   tTimeGols time2;
} tPlacarJogo;

typedef struct {
   char nome[MAX];
   int jogos;
   int saldo;
   int pontos;
} tPontos;

int grava_pontos_time(FILE *parq, tPontos time_grava);
int contabiliza_pontuacao(tPlacarJogo *placar, tPontos *time_grava);
int ler_gravar_resultados(FILE *parq, FILE *parq2, char *time_desejado);
void mostra_pontuacao_time(FILE *parq);

/* Implementação das funções solicitadas */
int main()
{
   FILE *parq, *parq2;
   char time_buscado[MAX];
   parq=fopen("jogos.txt","r");
   if(parq==NULL)
    return -1;
   parq2=fopen("pontos.dat","w+");
   if(parq2==NULL) {
      fclose(parq);
      return -1; }
   printf("Digite o time desejado: ");
   fgets(time_buscado,MAX,stdin);
   while (time_buscado[0]!='\n') {
      time_buscado[strlen(time_buscado)-1]='\0';
      ler_gravar_resultados(parq, parq2, time_buscado);
      mostra_pontuacao_time(parq2);
      printf("Digite o time desejado: ");
      fgets(time_buscado,MAX,stdin); }
   fclose(parq);
   fclose(parq2);
   return 0;
}

int grava_pontos_time(FILE *parq, tPontos time_grava)
{
    char string[MAX];
    int exite = 0;
    while(!feof(parq))
    {
        fgets(string, MAX, parq);
        if (strstr(string, time_grava.nome) == NULL)
            continue;
        else
        {
            
        }
    }
}
int contabiliza_pontuacao(tPlacarJogo *placar, tPontos *time_grava)
{

}
int ler_gravar_resultados(FILE *parq, FILE *parq2, char *time_desejado)
{

}
void mostra_pontuacao_time(FILE *parq)
{

}
