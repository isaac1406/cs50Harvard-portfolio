#include <stdio.h>
#include <stdlib.h>

void altera(float *salario, float percentual);

int main()
{
    float *salario = malloc(sizeof(int));
    float percentual;
    scanf("%f %f", salario, &percentual);
    altera(salario, percentual/100);
    printf("%.2f\n", *salario);
    return 0;
}


void altera(float *salario, float percentual)
{
    *salario += *salario * percentual;
    return;
}
