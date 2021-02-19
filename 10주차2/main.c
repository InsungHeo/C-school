#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>

int chooseBD(void);
int compare(int computer, int player);


int main()
{
    char name[10], answer[4] = "yes";
    printf("Hello, What is your name?\n");
    scanf("%s", name);

    while(strcmp(answer, "yes") == 0 || strcmp(answer, "Y") == 0)
    {
        int guessbd = 0, bd;
        bd = chooseBD();
        printf("Okay, %s. Guess your number.\n", name);
        scanf("%d", &guessbd);

        while(compare(bd, guessbd) != 0)
        {
            if (compare(bd, guessbd) == 1)
                printf("Smaller...\n");
            if (compare(bd, guessbd) == -1)
                printf("Bigger...\n");

            scanf("%d", &guessbd);
        }
        printf("Correct! Great job!\n\n");


        printf("%s, would you like to play again?\n", name);
        scanf("%s", answer);
    }

    return 0;
}

int chooseBD(void)
{
    int bd = 0;
    srand(time(NULL));
    bd = (rand()%31) + 1;
    return bd;
}

int compare(int computer, int player)
{
    if (computer == player)
        return 0;
    else if (computer > player)
        return -1;
    else
        return 1;
}
