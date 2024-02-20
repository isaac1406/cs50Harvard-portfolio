#include <cs50.h>
#include <stdio.h>
#include <math.h>

int ldigit(long card);
int digits(long card);
bool IsAmex(long card, int numDigits);
bool IsMastercard(long card, int numDigits);
bool IsVisa(long card, int numDigits);

int main(void)
{
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while(number < 1);//need to reject the first digit being 0
    int decider = ldigit(number);
    printf("%i\n", decider);
    int numDigits = digits(number);
    bool amex = IsAmex(number, numDigits);
    bool mastercard = IsMastercard(number, numDigits);
    bool visa = IsVisa(number, numDigits);
    if(decider % 10 != 0)
    {
        printf("Invalid\n");
    }
    else if(amex == true)
    {
        printf("AMEX\n");
    }
    else if(mastercard == true)
    {
        printf("MASTERCARD\n");
    }
    else if(visa == true)
    {
        printf("VISA\n");
    }
    else
    {
        printf("Invalid\n");
    }
}

int ldigit(long card)
{
    int total= 0;
    bool alternate = false;
    while(card > 0)
    {
       if(alternate == true)
       {
            int last = card % 10;
            int product = multiplier(last);
            total += product;
       }
       else
       {
            int last = card % 10;
            total += last;
       }
       alternate = !alternate;
       card /= 10;
    }
    return total;
}

int multiplier(int last)
{
    int multiply = last * 2;
    int sum = 0;
    while(multiply > 0)
    {
        int rest = multiply % 10;
        sum += last;
        multiply /= 10;
    }
    return sum;
}

int digits(long card)
{
    int counter = 0;
    while(card > 0)
    {
        card /= 10;
        counter++;
    }
    return counter;
}

bool IsAmex(long card, int numDigits)
{
    int firsts = card / pow(10, 13);
    if((numDigits == 15) && (firsts == 34 || firsts == 37))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsMastercard(long card, int numDigits)
{
    int firsts = card / pow(10, 14);
    if((numDigits == 16) && (firsts > 50 && firsts < 56))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsVisa(long card, int numDigits)
{
    if(numDigits == 13)
    {
        int first = card / pow(10, 12);
        if(first == 4)
        {
            return true;
        }
    }
    else if(numDigits == 16)
    {
        int first = card / pow(10, 15);
        if(first == 4)
        {
            return true;
        }
    }
    return false;
}
