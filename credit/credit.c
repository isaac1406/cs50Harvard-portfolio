#include <cs50.h>
#include <stdio.h>

void validation(long a);

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

void validation(long a)
{
    int rest = 0, c = 0, multiply =  0;
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
                int fdigit = multiply / 10;
                int ldigit = multiply % 10;
                multiply = ldigit + fdigit;
            a /= 10;
        }
        printf("%i %i %i %i\n", b, rest, c, multiply);
    }
}
