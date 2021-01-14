#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 640000

int main(void)
{
    long op,ed;
    int A[N],temp;
    double oper_time[10],sum_time = 0.0;

    srand(time(NULL));
/*
    //for 1st Algorithm
    for(int k = 0; k < 10; k++)
    {
        op = clock();
        int qualified;

        for(int i = 0; i < N; i++)
        {
            qualified = 1;
            temp = rand() % N;
            for (int j = 0; j < i; j++)
                if(temp == A[j])
                {
                    qualified = 0;
                    break;
                }
            if(qualified)
                A[i] = temp;
            else
                i--;
        }

        ed = clock();
        oper_time[k] = (double)(ed-op)/CLOCKS_PER_SEC;
        sum_time += oper_time[k];
        printf("%2d) N=%d time:%f\n",k+1,N,oper_time[k]);
    }

    printf("  average time:%f\n",sum_time/10.0);

    //for 2nd Algorithm
    for(int k = 0; k < 10; k++)
    {
        op = clock();
        int Used[N];

        for(int i = 0; i < N; i++)
            Used[i] = 0;

        for(int i = 0; i < N; i++)
        {
            temp = rand() % N;

            if(Used[temp] == 0)
            {
                A[i] = temp;
                Used[temp] = 1;
            }
            else
                i--;
        }

        ed = clock();
        oper_time[k] = (double)(ed-op)/CLOCKS_PER_SEC;
        sum_time += oper_time[k];
        printf("%2d) N=%d time:%f\n",k+1,N,oper_time[k]);
    }

    printf("  average time:%f\n",sum_time/10.0);
*/
    //for 3rd Algorithm
    for(int k = 0; k < 10; k++)
    {
        op = clock();
        int temp_num;

        A[0] = 1;
        for(int i = 1; i < N; i++)
        {
            A[i] = i + 1;

            temp = rand() % i;
            temp_num = A[i];
            A[i] = A[temp];
            A[temp] = temp_num;
        }

        ed = clock();
        oper_time[k] = (double)(ed-op)/CLOCKS_PER_SEC;
        sum_time += oper_time[k];
        printf("%2d) N=%d time:%f\n",k+1,N,oper_time[k]);
    }

    printf("  average time:%f\n",sum_time/10.0);

    return 0;
}