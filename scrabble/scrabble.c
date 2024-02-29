#include <cs50.h>
#include <stdio.h>
#include <string.h>

void points(string player1);

int main(void)
{
    string player1 = get_string("player 1: ");

    points(player1);
}

void points(string player1)
{
    char one[10] = {'A', 'E', 'I', 'L', 'N', 'O', 'R', 'S', 'T', 'U'};

    int sum = 0;

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0, lenght = strlen(player1); j < lenght; j++)
        {
            for(int h = 0; h < 11; h++)
            {
                if(player1[j] == one[h])
                {
                    sum += 1;
                }
            }
        }
    }
}
