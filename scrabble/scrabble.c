#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void points(string player1);

int main(void)
{
    //make the players as arrays
    string player1 = get_string("player 1: ");
    for(int x = 0, lenght = strlen(player1); x < lenght; x++)
    {
        //if lowercase
        if(player1[x] >= 'a' && player1[x] <= 'z')
        {
            player1[x] -= 32;
        }
    }

    points(player1);
}

void points(string player1)
{
    //pontuation for each letter
    char one[10] = {'A', 'E', 'I', 'L', 'N', 'O', 'R', 'S', 'T', 'U'};
    char two[2] = {'D', 'G'};
    char three[4] = {'B', 'C', 'M', 'P'};
    char four[5] = {'F', 'H', 'V', 'W', 'Y'};
    char five = 'K';
    char eight[2] = {'J', 'X'};
    char ten[2] = {'Q', 'Z'};

    int sum = 0;

    //player 1 and 2
    for(int i = 0; i < 2; i++)
    {
        //each letter of the word imputed
        for(int j = 0, lenght = strlen(player1); j < lenght; j++)
        {
            //check for 1 point
            for(int h = 0; h < 10; h++)
            {
                if(player1[j] == one[h])
                {
                    sum += 1;
                }
            }
            //check for 2 points
            for(int h = 0; h < 2; h++)
            {
                if(player1[j] == two[h])
                {
                    sum += 1;
                }
            }
            //check for 3 points
            for(int h = 0; h < 5; h++)
            {
                if(player1[j] == three[h])
                {
                    sum += 1;
                }
            }
            //check for 4 points
            for(int h = 0; h < 5; h++)
            {
                if(player1[j] == four[h])
                {
                    sum += 1;
                }
            }
            //check for 5 points
            for(int h = 0; h < 11; h++)
            {
                if(player1[j] == one[h])
                {
                    sum += 1;
                }
            }
            //check for 8 points
            for(int h = 0; h < 2; h++)
            {
                if(player1[j] == eight[h])
                {
                    sum += 1;
                }
            }
            //check for 10 points
            for(int h = 0; h < 2; h++)
            {
                if(player1[j] == ten[h])
                {
                    sum += 1;
                }
            }
        }
    }
}
