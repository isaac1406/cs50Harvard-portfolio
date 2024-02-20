#include <cs50.h>
#include <stdio.h>
#include <math.h>

int validation(long a);
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
    int decider = validation(number);
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

int every_(long a)
{

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
