#include <stdio.h>
#include <stdlib.h>

void altera(int *salario, int percentual);

int main()
{
    int *salario = malloc(sizeof(int));
    int percentual;
    scanf("%d %d", salario, &percentual);
    altera(salario, percentual);
    printf("%d", *salario);
    return 0;
}


void altera(int *salario, int percentual)
{
    *salario *= percentual;
    return;
}
