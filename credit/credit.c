#include <cs50.h>
#include <stdio.h>
#include <math.h>

int validation(long a);

int main(void)
{
    long number;
    do
    {
        int counter = 0;
        number = get_long("Number: ");
        long clone = number;
        while(clone > 0)
        {
            counter++;
            clone /= 10;
        }
        long result = number / (pow(10, counter));
    }
    while(result == 0 || number < 1);
    int decider = validation(number);
    if(decider % 10 == 0)
    {

    }
    else
    {
        printf("Invalid\n")
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

