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
    tPontos time_lido;
    int encontrado = 0;

    fseek(parq, 0, SEEK_SET);

    while(fread(&time_lido, sizeof(tPontos), 1, parq) == 1)
    {
        if(strcmp(time_lido.nome, time_grava.nome) == 0)
        {
            encontrado = 1;
            fseek(parq, -sizeof(tPontos), SEEK_CUR);
            fwrite(&time_grava, sizeof(tPontos), 1, parq);
            break;
        }
    }

    if(!encontrado)
    {
        fseek(parq, 0, SEEK_END);
        fwrite(&time_grava, sizeof(tPontos), 1, parq);
    }

    return 0;
}
int contabiliza_pontuacao(tPlacarJogo *placar, tPontos *time_grava)
{
    time_grava->jogos++;
    if(strcmp(placar->time1.nome, time_grava->nome) == 0)
    {
        time_grava->saldo += placar->time1.gols - placar->time2.gols;
        if(placar->time1.gols > placar->time2.gols)
        {
            time_grava->pontos += 3;
        }
        else if(placar->time1.gols == placar->time2.gols)
        {
            time_grava->pontos += 1;
        }
    }
    else if(strcmp(placar->time2.nome, time_grava->nome) == 0)
    {
        time_grava->saldo += placar->time2.gols - placar->time1.gols;
        if(placar->time2.gols > placar->time1.gols)
        {
            time_grava->pontos += 3;
        }
        else if(placar->time2.gols == placar->time1.gols)
        {
            time_grava->pontos += 1;
        }
    }
    return 0;
}
int ler_gravar_resultados(FILE *parq, FILE *parq2, char *time_desejado)
{
    tPlacarJogo placar;
    tPontos time_grava;

    time_grava.jogos = 0;
    time_grava.pontos = 0;
    time_grava.saldo = 0;

    strcpy(time_grava.nome, time_desejado);

    fseek(parq, 0, SEEK_SET);

    while(fscanf(parq, "%s %d x %d %s",
    placar.time1.nome, &placar.time1.gols, &placar.time2.gols, placar.time2.nome))
    {
        if(strcmp(placar.time1.nome, time_grava.nome) == 0 || strcmp(placar.time2.nome, time_grava.nome) == 0)
        {
            contabiliza_pontuacao(&placar, &time_grava);
        }
    }

    grava_pontos_time(parq2, time_grava);
    return 0;
}
void mostra_pontuacao_time(FILE *parq)
{
    tPontos time_lido;
    fseek(parq, 0, SEEK_SET);

    while (fread(&time_lido, sizeof(tPontos), 1, parq) == 1) {
        printf("time: %s - jogos: %d, saldo de gols: %d, pontos: %d\n",
        time_lido.nome, time_lido.jogos, time_lido.saldo, time_lido.pontos);
    }
}

