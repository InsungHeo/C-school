#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define maxv 1000000000
#define minv 1000000
int regcd(int a, int b);
int legcd(int a, int b);


int main()
{
    int a, b, x, y;
    srand(time(NULL));
    for (int i=0 ; i<3 ; i++)
    {
        a = (rand()*rand()) % (maxv-minv-1) + minv + 1;
        b = (rand()*rand()) % (maxv-minv-1) + minv + 1;
        x = regcd(a, b);
        y = legcd(a, b);


        printf("%d보다 크고 %d보다는 작은 임의의 두 정수는 각각\n%9d, %9d이다.\n", minv, maxv, a, b);
        printf("재귀함수를 통해 구한 최대공약수 : %d\n", x);
        printf("반복문을 통해 구한 최대공약수   : %d\n\n", y);
    }



    return 0;
}
