/*      Seven-Card_stud.c

   draw 7 cards, see what the rarest outcome is and note it down
   run the script a million times and print the results in a table

*/

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define MAX_HAND_SIZE 7
#define RESET srand(time(NULL) + (z+z))
#define RUNS 10000000


typedef struct my_hand
{
    int card_type;
    int card_number;
};

typedef struct outcome
{
    int Royal_flush;
    int Straight_flush;
    int Four_of_a_kind;
    int Full_house;
    int Flush;
    int Straight;
    int Three_of_a_kind;
    int Two_pair;
    int Pair;
    int High_card;
};

struct my_hand hand[MAX_HAND_SIZE];
struct outcome out;

void draw_card (int card_position)
{

    hand[card_position].card_number = (rand() % 13) + 1;
    hand[card_position].card_type = rand() % 4;
}

int check_draw (struct my_hand hand[MAX_HAND_SIZE])
{
    for (int i = 0; i < (MAX_HAND_SIZE - 1); i++)
    {
        for (int k = i + 1; k < MAX_HAND_SIZE; k++)
        {
            if (hand[i].card_number == hand[k].card_number && hand[i].card_type == hand[k].card_type)
            {
                return 1;
            }
        }
    }
    return 0;
}

void sort_deck (struct my_hand hand[MAX_HAND_SIZE])
{
    int x, y;
    int z = 0;
    while (z < MAX_HAND_SIZE)
    {
        for (int i = 0; i < MAX_HAND_SIZE - 1; i++)
        {
            if (hand[i].card_number > hand[i + 1].card_number)
            {
                x = hand[i + 1].card_number;
                y = hand[i + 1].card_type;
                hand[i + 1].card_number = hand[i].card_number;
                hand[i + 1].card_type = hand[i].card_type;
                hand[i].card_number = x;
                hand[i].card_type = y;
            }
        }
        z++;
    }
}

int check_royal_flush (struct my_hand hand[MAX_HAND_SIZE])
{
    int z = 0;
    for (int i = 0; i < (MAX_HAND_SIZE - 1); i++)
    {
        if (hand[i].card_number + 1 == hand[i + 1].card_number && hand[i].card_type == hand[i + 1].card_type)
        {
            z++;
        }
        else if (i == 5 && hand[6].card_number == 13 && hand[0].card_number == 1 && hand[6].card_type == hand[0].card_type)
        {
            z++;
        }
        else if (hand[i].card_number != hand[i + 1].card_number || hand[i].card_type != hand[i + 1].card_type)
        {
            z = 0;
        }
        if (z > 4 && hand[0].card_number == 1 && hand[6].card_number == 13)
        {
            return 1;
        }
    }
    return 0;
}

int check_straight_flush (struct my_hand hand[MAX_HAND_SIZE])
{
    int z = 0;
    for (int i = 0; i < (MAX_HAND_SIZE - 1); i++)
    {
        if (hand[i].card_number + 1 == hand[i + 1].card_number && hand[i].card_type == hand[i + 1].card_type)
        {
            z++;
        }
        else if (i == 5 && hand[6].card_number == 13 && hand[0].card_number == 1 && hand[6].card_type == hand[0].card_type)
        {
            z++;
        }
        else if (hand[i].card_number != hand[i + 1].card_number || hand[i].card_type != hand[i + 1].card_type)
        {
            z = 0;
        }
        if (z > 4)
        {
            return 1;
        }
    }
    return 0;
}

int check_four_of_a_kind (struct my_hand hand[MAX_HAND_SIZE])
{
    for (int i = 0; i < (MAX_HAND_SIZE - 1); i++)
    {
        for (int j = i + 1; j < MAX_HAND_SIZE; j++)
        {
            for (int k = j + 1; k < (MAX_HAND_SIZE); k++)
            {
                for (int l = k + 1; l < MAX_HAND_SIZE; l++)
                {
                    if (hand[i].card_number == hand[j].card_number && hand[j].card_number == hand[k].card_number && hand[k].card_number == hand[l].card_number)
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int check_full_house (struct my_hand hand[MAX_HAND_SIZE])
{
    for (int i = 0; i < (MAX_HAND_SIZE - 1); i++)
    {
        for (int j = i + 1; j < MAX_HAND_SIZE; j++)
        {
            for (int k = j + 1; k < (MAX_HAND_SIZE); k++)
            {
                if (hand[i].card_number == hand[j].card_number && hand[j].card_number == hand[k].card_number)
                {
                    for (int l = 0; l < MAX_HAND_SIZE; l++)
                    {
                        for (int m = l + 1; m < (MAX_HAND_SIZE); m++)
                        {
                            if (hand[l].card_number == hand[m].card_number && hand[l].card_number != hand[i].card_number)
                            {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int check_flush (struct my_hand hand[MAX_HAND_SIZE])
{
    for (int i = 0; i < (MAX_HAND_SIZE - 1); i++)
    {
        for (int j = i + 1; j < MAX_HAND_SIZE; j++)
        {
            for (int k = j + 1; k < (MAX_HAND_SIZE); k++)
            {
                for (int l = k + 1; l < MAX_HAND_SIZE; l++)
                {
                    for (int m = l + 1; m < MAX_HAND_SIZE; m++)
                    {
                        if (hand[i].card_type == hand[j].card_type && hand[j].card_type == hand[k].card_type && hand[k].card_type == hand[l].card_type && hand[l].card_type == hand[m].card_type)
                        {
                        return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int check_straight (struct my_hand hand[MAX_HAND_SIZE])
{
    int z = 0;
    for (int i = 0; i < (MAX_HAND_SIZE - 1); i++)
    {
        if (hand[i].card_number + 1 == hand[i + 1].card_number)
        {
            z++;
        }
        else if (i == 5 && hand[6].card_number == 13 && hand[0].card_number == 1)
        {
            z++;
        }
        else if (hand[i].card_number != hand[i + 1].card_number)
        {
            z = 0;
        }
        if (z > 4)
        {
            return 1;
        }
    }
    return 0;
}

int check_three_of_a_kind (struct my_hand hand[MAX_HAND_SIZE])
{
    for (int i = 0; i < (MAX_HAND_SIZE - 1); i++)
    {
        for (int j = i + 1; j < MAX_HAND_SIZE; j++)
        {
            for (int k = j + 1; k < (MAX_HAND_SIZE); k++)
            {
                if (hand[i].card_number == hand[j].card_number && hand[j].card_number == hand[k].card_number)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int check_two_pair (struct my_hand hand[MAX_HAND_SIZE])
{
    for (int i = 0; i < (MAX_HAND_SIZE - 1); i++)
    {
        for (int j = i + 1; j < MAX_HAND_SIZE; j++)
        {
            if (hand[i].card_number == hand[j].card_number)
            {
                for (int k = i + 1; k < (MAX_HAND_SIZE - 1); k++)
                {
                    for (int l = k + 1; l < MAX_HAND_SIZE; l++)
                    {
                        if (hand[k].card_number == hand[l].card_number)
                        {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int check_one_pair (struct my_hand hand[MAX_HAND_SIZE])
{
    for (int i = 0; i < (MAX_HAND_SIZE - 1); i++)
    {
        for (int j = i + 1; j < MAX_HAND_SIZE; j++)
        {
            if (hand[i].card_number == hand[j].card_number)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main(void)
{
    int z = 0;
    for (int r = 0; r < RUNS; r++)
    {
        do
        {
            z++;
            RESET;
            int check;
            for (int i = 0; i < MAX_HAND_SIZE; i++)
            {

                draw_card(i);

            }

        } while (check_draw(hand) == 1);

        sort_deck(hand);

        /*
        for (int i = 0; i < MAX_HAND_SIZE; i++)
        {
             printf("card %d, card number: %d and card type: %d\n", i, hand[i].card_number, hand[i].card_type);
        }
        */

        if (check_royal_flush(hand) == 1)
            out.Royal_flush = 1;
        else if (check_straight_flush(hand) == 1)
            out.Straight_flush++;
        else if (check_four_of_a_kind(hand) == 1)
            out.Four_of_a_kind++;
        else if (check_full_house(hand) == 1)
            out.Full_house++;
        else if (check_flush(hand) == 1)
            out.Flush++;
        else if (check_straight(hand) == 1)
        {
            out.Straight++;
            /*
            printf("straight\n");
            */
        }
        else if (check_three_of_a_kind(hand) == 1)
            out.Three_of_a_kind++;
        else if (check_two_pair(hand) == 1)
            out.Two_pair++;
        else if (check_one_pair(hand) == 1)
            out.Pair++;
        else
            out.High_card++;
        /*
        printf("\n");
        */
    }

    printf("Hand                |Combinations        |Probabilities       \n");
    printf("--------------------------------------------------------------\n");
    printf("Royal flush           %d                    %lf\n", out.Royal_flush, (float)out.Royal_flush / RUNS);
    printf("Straight flush        %d                    %lf\n", out.Straight_flush, (float)out.Straight_flush / RUNS);
    printf("Four of a kind        %d                    %lf\n", out.Four_of_a_kind, (float)out.Four_of_a_kind / RUNS);
    printf("Full house            %d                    %lf\n", out.Full_house, (float)out.Full_house / RUNS);
    printf("Flush                 %d                    %lf\n", out.Flush, (float)out.Flush / RUNS);
    printf("Straight              %d                    %lf\n", out.Straight, (float)out.Straight / RUNS);
    printf("Three of a kind       %d                    %lf\n", out.Three_of_a_kind, (float)out.Three_of_a_kind / RUNS);
    printf("Two pair              %d                    %lf\n", out.Two_pair, (float)out.Two_pair / RUNS);
    printf("Pair                  %d                    %lf\n", out.Pair, (float)out.Pair / RUNS);
    printf("High card             %d                    %lf\n", out.High_card, (float)out.High_card / RUNS);
    return 0;
}
