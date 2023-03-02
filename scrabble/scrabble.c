#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("Player 2 wins!\n");
    }

}

int compute_score(string word)
{
    // TODO: Compute and return score for string

    int points = 0;
    //loop over string
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        //check whether the passed character is alphabetic,
        if (isalpha(word[i]))
        {
            // get score from points array
            points += POINTS[i];
        }
        else
        {
            // 0 if character is a symbol
            points += 0;
        }


    }
    return points;//return total points
}
