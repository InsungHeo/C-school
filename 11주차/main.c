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


        printf("%d���� ũ�� %d���ٴ� ���� ������ �� ������ ����\n%9d, %9d�̴�.\n", minv, maxv, a, b);
        printf("����Լ��� ���� ���� �ִ����� : %d\n", x);
        printf("�ݺ����� ���� ���� �ִ�����   : %d\n\n", y);
    }



    return 0;
}
