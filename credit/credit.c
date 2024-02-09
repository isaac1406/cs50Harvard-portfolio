#include <cs50.h>
#include <stdio.h>

void validation(long a);

int main(void)
{
    long number;
    do
    {
        int counter = 0;
        number = get_long("Number: ");
        while(number > 0)
        {
            counter++;
            number /= 10;
        }
        int result = number / ()
    }
    while(number < 1);
    validation(number);
}

void validation(long a)
{
    int rest = 0, c = 0, multiply =  0, doubled = 0, total;
    while(a > 0)
    {
        int b = a % 10;
        rest += b;
        a /= 10;
        if(a > 0)
        {
            c = a % 10;
            multiply = c * 2;
            if(multiply > 10)
            {
                int fdigit = multiply / 10;
                int ldigit = multiply % 10;
                multiply = fdigit + ldigit;
            }
            doubled += multiply;
            a /= 10;
        }
        // pesquisar sobre retorno de valor para a validação do cartão
        total = doubled + rest;
        printf("%i %i\n", rest, doubled);
    }
    printf("%i\n", total);
}
