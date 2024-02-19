#include <cs50.h>
#include <stdio.h>
#include <math.h>

int validation(long a);
int digits(long card);

int main(void)
{
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while(number < 1);//need to reject the first digit being 0
    int decider = validation(number);
    int numDigits = digits(number);
    if(decider % 10 != 0)
    {
        printf("Invalid\n");
    }
}

int validation(long a)
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
        total = doubled + rest;
        return total;
    }
}

int digits(long card)
{
    int counter = 0;
    while(card > 0)
    {
        card /= 10;
        counter++;
    }
    return count;
}

bool IsAmex(long card, int numDigits)
{
    
}
