//find the maximum subsequence product

#include <stdio.h>

#define N 10

int maxproduct(int arr[],int lo,int hi);//rank [lo,hi)
int maxi(int arr[],int n);//arr has index from 0 to n

int main(void)
{
    int A[N] = {3,5,-3,-6,0,4,9,-3,-6,-8};

    int mi[N],num_0 = 0;
    for(int i = 0; i < N; i++)
        if(A[i] == 0)
            mi[num_0++] = i;

    if(num_0 == 0)
        printf("Maximum subsequence product is %d\n",maxproduct(A,0,N));
    else
    {
        int maxprod[N+1];
        maxprod[0] = maxproduct(A,0,mi[0]);
        for(int i = 1; i < num_0; i++)
            maxprod[i] = maxproduct(A,mi[i-1]+1,mi[i]);
        maxprod[num_0] = maxproduct(A,mi[num_0-1]+1,N);

        printf("Maximum subsequence product is %d\n",maxi(maxprod,num_0));
    }
    return 0;
}

int maxproduct(int arr[],int lo,int hi)
{
    int neg_num = 0, neg_start, neg_end;
    int result = 1;

    for(int i = lo; i < hi; i++)
        if(arr[i] < 0)
            if(neg_num == 0)
            {
                neg_num++;
                neg_start = neg_end = i;
            }
            else
            {
                neg_num++;
                neg_end = i;
            }
    if(neg_num % 2 == 0)
    {
        for(int i = lo; i < hi; i++)
            result *= arr[i];
        return result;
    }
    else
    {
        int result1 = 1;
        int result2 = 1;

        for(int i = lo; i < neg_end; i++)
            result1 *= arr[i];
        for(int i = neg_start+1; i < hi; i++)
            result2 *= arr[i];
        return result1 > result2 ? result1 : result2;
    }
}

int maxi(int arr[],int n)
{
    int max = arr[0];

    for(int i = 1; i <= n; i++)
        if(arr[i] > max)
            max = arr[i];

    return max;
}