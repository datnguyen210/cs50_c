#include "cs50.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int count_score(string s);
char to_upper(char s);
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(void)
{
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");
    int score1 = count_score(player1);
    int score2 = count_score(player2);
    if (score1 > score2)
    {
        printf("Player 1 wins!");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!");
    }
}

int count_score(string s)
{
    int score = 0;
    for (int i = 0, length = strlen(s); i < length; i++)
    {
        char upper_char = to_upper(s[i]);
        score += POINTS[upper_char - 'A'];
    }
    return score;
}

char to_upper(char s)
{
    s = toupper(s);
}