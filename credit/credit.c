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
    while(a > 0)
    {
        int b = a % 10;
        a /= 10;
        int c = a % 10;

    }
    printf("\n")
}

printf("%i ", b);
