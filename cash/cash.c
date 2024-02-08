#include <cs50.h>
#include <stdio.h>

void cashier(int a);

int main(void)
{
    int change;
    do
    {
        change = get_int("Change owed: ");
    }
    while(change < 0);
    cashier(change);
}

void cashier(int a)
{
    int i = 0;
    while(a > 0)
    {
        if (a >= 25)
            a -= 25;
        else if (a >= 10)
            a -= 10;
        else if (a >= 5)
            a -= 5;
        else
            a -= 1;
        i++;
    }
    printf("%i\n", i);
}
