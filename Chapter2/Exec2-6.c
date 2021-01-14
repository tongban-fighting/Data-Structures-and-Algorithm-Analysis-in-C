#include <stdio.h>
#include <time.h>

#define N 1000

int main(void)
{
    long op,ed;
    int sum = 0;

    //for num 1
    op = clock();
    sum = 0;
    for(int i = 0; i < N; i++)
        sum++;
    ed = clock();
    printf("1) %fs (N=%d)\n",(double)(ed-op)/CLOCKS_PER_SEC,N);

    //for num 2
    op = clock();
    sum = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
           sum++;
    ed = clock();
    printf("2) %fs (N=%d)\n",(double)(ed-op)/CLOCKS_PER_SEC,N);

    //for num 3
    op = clock();
    sum = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N * N; j++)
            sum++;
    ed = clock();
    printf("3) %fs (N=%d)\n",(double)(ed-op)/CLOCKS_PER_SEC,N);

    //for num 4
    op = clock();
    sum = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < i; j++)
            sum++;
    ed = clock();
    printf("4) %fs (N=%d)\n",(double)(ed-op)/CLOCKS_PER_SEC,N);

    //for num 5
    op = clock();
    sum = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < i * i; j++)
            for(int k = 0; k < j; k++)
                sum++;
    ed = clock();
    printf("5) %fs (N=%d)\n",(double)(ed-op)/CLOCKS_PER_SEC,N);

    //for num 1
    op = clock();
    sum = 0;
    for(int i = 1; i < N; i++)
        for(int j = 1; j < i * i; j++)
            if(j % i == 0)
                for(int k = 0; k < j; k++)
                    sum++;
    ed = clock();
    printf("6) %fs (N=%d)\n",(double)(ed-op)/CLOCKS_PER_SEC,N);

    return 0;
}