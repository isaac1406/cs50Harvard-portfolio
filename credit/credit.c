#include <cs50.h>
#include <stdio.h>
#include <math.h>

int validation(long a);
int firsts(int i, long j)

int main(void)
{
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while(number < 1);
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

int firsts(int i, long j)
{
    int counter = 0;
    if(i == 1)
    {
        while(j > )
        {
            counter++;
            j /= 10;
        }
    }
    else if(i == 2)
    {
        while(j > )
        {
            j /= 10
        }
    }
    printf("%li\n", j)
}

void type(long n)
{

}
