#include <cs50.h>
#include <stdio.h>

void validation(int a);

int main(void)
{
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while(number < 1);
    validation(number);
}

void validation(int a)
{
    int rest = 0;
    while(a > 0)
    {
        int b = a % 10;
        rest += b;
        a /= 10;
        int c = a % 10;
        printf("%i %i\n", b, c);
    }
    printf("\n");
}

printf("%i ", b);
