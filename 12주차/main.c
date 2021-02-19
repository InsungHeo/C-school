#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20
void printlist(int *anylist);
int shuffle(int *anylist);
int Selectionsort(int *array_primenumber);
int Insertionsort(int *array_primenumber);

int main()
{
    int array_primenumber[SIZE] = {};
    printf("소수 %d개를 입력해주세요.\n", SIZE);
    for(int a = 0; a < SIZE; a++)
    {
        scanf("%d", array_primenumber+a);
    }
    printf("\n정렬전\t\t");
    shuffle(array_primenumber);
    printlist(array_primenumber);
    printf("\n");
    //Selectionsort(array_primenumber);
    Insertionsort(array_primenumber);

    return 0;
}

void printlist(int *anylist) // 배열 출력
{
    for(int k = 0; k < SIZE; k++)
        printf("%3d ", *(anylist+k));
    printf("\n");
}

int shuffle(int *anylist) // 배열 무작위로 섞기
{
    srand(time(NULL));
    int temp, rn;
    for(int i = 0; i < SIZE-1; i++)
    {
        rn = rand()%(SIZE-i) + i;
        temp = *(anylist+i);
        *(anylist+i) = *(anylist+rn);
        *(anylist+rn) = temp;
    }
}


int Selectionsort(int *array_primenumber) // 선택정렬
{
    printf("선택정렬\n");
    int min_idx, temp;
    for(int i = 0; i < SIZE; i++)
    {
        min_idx = i;
        for(int j = i+1; j < SIZE; j++)
            if(array_primenumber[min_idx] > array_primenumber[j])
                min_idx = j;

        temp = *(array_primenumber+i);
        *(array_primenumber+i) = *(array_primenumber+min_idx);
        *(array_primenumber+min_idx) = temp;

        printf("%3d 단계\t", i+1);
        printlist(array_primenumber);

    }
}

int Insertionsort(int *array) // 삽입정렬
{
    printf("삽입정렬\n");
    int key, i;
    for(int j = 1; j < SIZE; j++)
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
}
