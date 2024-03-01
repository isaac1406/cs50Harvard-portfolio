#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string upper(string player);
int points(string player1, string player2);

int main(void)
{
    const int N = 2;
    string player[N];
    //input the words chosen by both players
    for(int i = 0; i < N; i++)
    {
        player[i] = get_string("player %i: ", i + 1);
    }

    // put all to uppercase to avoid mistakes in the pontuation
    upper(player[0]);
    upper(player[1]);

    //apply functon to calculate the points of each player
    int score = points(player[0], player[1]);
    //check the result
    if(score > 0)
    {
        printf("Player 1 WINS!");
    }
    else if(score < 0)
    {
        printf("Player 2 WINS!");
    }
    else
    {
        printf("TIE!!");
    }

}

string upper(string player)
{
    for(int x = 0, lenght = strlen(player); x < lenght; x++)
    {
        //if lowercase
        if(player[x] >= 'a' && player[x] <= 'z')
        {
            player[x] -= 32;
        }
    }
    return player;
}

int points(string player1, string player2)
{
    //pontuation for each letter
    char one[10] = {'A', 'E', 'I', 'L', 'N', 'O', 'R', 'S', 'T', 'U'};
    char two[2] = {'D', 'G'};
    char three[4] = {'B', 'C', 'M', 'P'};
    char four[5] = {'F', 'H', 'V', 'W', 'Y'};
    char five = 'K';
    char eight[2] = {'J', 'X'};
    char ten[2] = {'Q', 'Z'};
    //sum of the points scored by each player
    int sum[2] = {0, 0};

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
                    sum[i] += 1;
                }
            }
            //check for 2 points
            for(int h = 0; h < 2; h++)
            {
                if(player1[j] == two[h])
                {
                    sum[i] += 1;
                }
            }
            //check for 3 points
            for(int h = 0; h < 5; h++)
            {
                if(player1[j] == three[h])
                {
                    sum[i] += 1;
                }
            }
            //check for 4 points
            for(int h = 0; h < 5; h++)
            {
                if(player1[j] == four[h])
                {
                    sum[i] += 1;
                }
            }
            //check for 5 points
            if(player1[j] == five)
            {
                sum[i] += 1;
            }
            //check for 8 points
            for(int h = 0; h < 2; h++)
            {
                if(player1[j] == eight[h])
                {
                    sum[i] += 1;
                }
            }
            //check for 10 points
            for(int h = 0; h < 2; h++)
            {
                if(player1[j] == ten[h])
                {
                    sum[i] += 1;
                }
            }
        }
    }
    //the result will define in main who won
    int score = sum[0] - sum[1];
    return score;
}
