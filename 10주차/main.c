#include <stdio.h>
#include <stdlib.h>
#define kilometers 0.621371
int main()
{
    float d, dm, sp;
    int min, sec, minp, secp, totalt;
    printf("This program converts your time for a metric race\n");
    printf("to a time for running a mile and to your average\n");
    printf("speed in miles per hour.\n");
    printf("Please enter, in kilometers, the distance run.\n");
    scanf("%f", &d);
    printf("Next enter the time in minutes and seconds.\n");
    printf("Begin by entering the minutes.\n");
    scanf("%d", &min);
    printf("Now enter the seconds.\n");
    scanf("%d", &sec);

    dm = d*kilometers;
    sp = dm/((float) min/60 + (float) sec/3600);
    printf("You ran %.2f km <%.2f miles> in %d min, %d sec.\n", d, dm, min, sec);
    totalt = 60*min + sec;
    minp = (int) (totalt/dm)/60, secp = (int) (totalt/dm)%60;
    printf("That pace corresponds to running a mile in %d min, %d sec\n", minp, secp);
    printf("Your average speed was %.2f mph.", sp);

    return 0;
}
