//융합전자공학부 2020010728 허인성 (캡쳐본 아님?)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int *array, int n); // 배열 무작위로 섞기
int Binsearch(int *array, int key, int m, int M); //중간값의 인덱스 반환

double n100(double *ar1);    // n = 100    일 때  500번 측정 후 평균을 리턴
double n1000(double *ar2);   // n = 1000   일 때  500번 측정 후 평균을 리턴
double n10000(double *ar3);  // n = 10000  일 때  500번 측정 후 평균을 리턴
double n100000(double *ar4); // n = 100000 일 때  500번  측정 후 평균을 리턴

double Isort1(int *array, int n); // 삽입정렬
double Isort2(int *array, int n); // 이진탐색을 처음부터 적용
double Isort3(int *array, int n); // 이진탐색을 1/3부터 적용
double Isort4(int *array, int n); // 이진탐색을 2/3부터 적용





int main()
{
    double result[4];
    double ar1[4], ar2[4], ar3[4], ar4[4];

    n100(ar1);    n1000(ar2);    n10000(ar3);    n100000(ar4);

    printf("공창컴(12174)_과제2_2020010728_허인성\n\n");
    printf("\t단위: ms        |   n = 100       |   n = 1,000     |   n = 10,000    |   n = 100,000   |\n");
    printf("------------------------------------------------------------------------------------------------\n");
    printf("삽입정렬         \t|    %8.3f     |    %8.3f     |    %8.3f     |    %8.3f     |\n", *(ar1  ), *(ar2  ), *(ar3  ), *(ar4  ));
    printf("이진탐색 처음부터\t|    %8.3f     |    %8.3f     |    %8.3f     |    %8.3f     |\n", *(ar1+1), *(ar2+1), *(ar3+1), *(ar4+1));
    printf("이진탐색 1/3부터 \t|    %8.3f     |    %8.3f     |    %8.3f     |    %8.3f     |\n", *(ar1+2), *(ar2+2), *(ar3+2), *(ar4+2));
    printf("이진탐색 2/3부터 \t|    %8.3f     |    %8.3f     |    %8.3f     |    %8.3f     |\n", *(ar1+3), *(ar2+3), *(ar3+3), *(ar4+3));

    return 0;
}

double n100(double *ar1)
{
    int array[100];
    double r1 = 0, r2 = 0, r3 = 0, r4 = 0;
    srand(time(NULL));

    for(int i; i<100; i++)
        array[i] = i+1;

    for(int i = 0; i < 500; i++)
    {
        shuffle(array, 100);
        r1 += Isort1(array, 100);
    }
    for(int i = 0; i < 500; i++)
    {
        shuffle(array, 100);
        r2 += Isort2(array, 100);
    }
    for(int i = 0; i < 500; i++)
    {
        shuffle(array, 100);
        r3 += Isort3(array, 100);
    }
    for(int i = 0; i < 500; i++)
    {
        shuffle(array, 100);
        r4 += Isort4(array, 100);
    }
    *(ar1) = r1/500; *(ar1+1) = r2/500; *(ar1+2) = r3/500; *(ar1+3) = r4/500;
}

double n1000(double *ar2)
{
    int array[1000];
    double r1 = 0, r2 = 0, r3 = 0, r4 = 0, a;
    srand(time(NULL));

    for(int i; i<1000; i++)
        array[i] = i+1;

    for(int i = 0; i < 500; i++)
    {
        shuffle(array, 1000);
        r1 += Isort1(array, 1000);
    }
    for(int i = 0; i < 500; i++)
    {
        shuffle(array, 1000);
        r2 += Isort2(array, 1000);
    }
    for(int i = 0; i < 500; i++)
    {
        shuffle(array, 1000);
        r3 += Isort3(array, 1000);
    }
    for(int i = 0; i < 500; i++)
    {
        shuffle(array, 1000);
        r4 += Isort4(array, 1000);
    }
    *(ar2) = r1/500; *(ar2+1) = r2/500; *(ar2+2) = r3/500; *(ar2+3) = r4/500;
}

double n10000(double *ar3)
{
    int array[10000];
    double r1 = 0, r2 = 0, r3 = 0, r4 = 0;
    srand(time(NULL));

    for(int i; i<10000; i++)
        array[i] = i+1;

    for(int i = 0; i < 500; i++)
    {
        shuffle(array, 10000);
        r1 += Isort1(array, 10000);
    }
    for(int i = 0; i < 500; i++)
    {
        shuffle(array, 10000);
        r2 += Isort2(array, 10000);
    }
    for(int i = 0; i < 500; i++)
    {
        shuffle(array, 10000);
        r3 += Isort3(array, 10000);
    }
    for(int i = 0; i < 500; i++)
    {
        shuffle(array, 10000);
        r4 += Isort4(array, 10000);
    }
    *(ar3) = r1/500; *(ar3+1) = r2/500; *(ar3+2) = r3/500; *(ar3+3) = r4/500;
}

double n100000(double *ar4)
{
    int array[100000];
    double r1, r2, r3, r4;
    srand(time(NULL));

    for(int i; i<100000; i++)
        array[i] = i+1;

    for(int i = 0; i < 500; i++)
    {
        shuffle(array, 100000);
        r1 += Isort1(array, 100000);
    }
    for(int i = 0; i < 500; i++)
    {
        shuffle(array, 100000);
        r2 += Isort2(array, 100000);
    }
    for(int i = 0; i < 500; i++)
    {
        shuffle(array, 100000);
        r3 += Isort3(array, 100000);
    }
    for(int i = 0; i < 500; i++)
    {
        shuffle(array, 100000);
        r4 += Isort4(array, 100000);
    }
    *(ar4) = r1/500; *(ar4+1) = r2/500; *(ar4+2) = r3/500; *(ar4+3) = r4/500;
}

void shuffle(int *array, int n) // 배열 무작위로 섞기
{
    int temp, rn;
    for(int i = 0; i < n-1; i++)
    {
        rn = rand()%(n-i) + i;
        temp = *(array+i);
        *(array+i) = *(array+rn);
        *(array+rn) = temp;
    }
}

int Binsearch(int *array, int key, int m, int M) //중간값의 인덱스 반환
{
    if(m > M)
        return -1;
    int mid = (m + M)/2;
    if(*(array+mid) < key && *(array+mid+1) >= key)
        return mid+1;
    else if(*(array+mid) > key)
    {
        if(mid == 0)
            return 0;
        else
            return Binsearch(array, key, m, mid-1);
    }
    else
        return Binsearch(array, key, mid+1, M);
}

double Isort1(int *array, int n)
{
    clock_t start, end;
    double result;
    start = clock();

    int key, i;
    for(int j = 1; j < n; j++)
    {
        key = *(array+j);
        i = j - 1;
        while(i >= 0 && *(array+i) > key)
        {
            *(array+i+1) = *(array+i);
            i--;
        }
        *(array+i+1) = key;
    }

    end = clock();
    result = (double)(end-start);
    return result;
}

double Isort2(int *array, int n)
{
    double result;
    clock_t start, end;
    start = clock();

    int key, mid;
    for(int j = 1; j < n+1; j++)
    {
        key = *(array+j);
        mid = Binsearch(array, key, 0, j-1);
        for(int i = j-1; i > mid-1; i--)
            *(array+i+1) = *(array+i);
        *(array+mid) = key;
    }

    end = clock();
    result = (double)(end-start);
    return result;
}

double Isort3(int *array, int n)

{
    double result;
    clock_t start, end;
    start = clock();

    int key, i;
    for(int j = 1; j < (int) n/3; j++)
    {
        key = *(array+j);
        i = j - 1;
        while(i >= 0 && *(array+i) > key)
        {
            *(array+i+1) = *(array+i);
            i--;
        }
        *(array+i+1) = key;
    }

    for(int j = (int) n/3; j < (int) 2*n/3; j++)
    {
        int key, mid;
        key = *(array+j);
        mid = Binsearch(array, key, 0, j-1);
        for(int i = j-1; i > mid-1; i--)
            *(array+i+1) = *(array+i);
        *(array+mid) = key;
    }

    end = clock();
    result = (double)(end-start);
    return result;
}

double Isort4(int *array, int n)
{
    double result;
    clock_t start, end;
    start = clock();

    int key, i;
    for(int j = 1; j < (int) 2*n/3; j++)
    {
        key = *(array+j);
        i = j - 1;
        while(i >= 0 && *(array+i) > key)
        {
            *(array+i+1) = *(array+i);
            i--;
        }
        *(array+i+1) = key;
    }

    for(int j = (int) 2*n/3; j < n; j++)
    {
        int key, mid;
        key = *(array+j);
        mid = Binsearch(array, key, 0, j-1);
        for(int i = j-1; i > mid-1; i--)
            *(array+i+1) = *(array+i);
        *(array+mid) = key;
    }

    end = clock();
    result = (double)(end-start);
    return result;
}

void printlist(int *anylist) // 정렬이 제대로 되는지 확인하기 위한 배열 출력
{
    for(int k = 0; k < 100; k++)
        printf("%3d ", *(anylist+k));
    printf("\n");
}
