//find the minimum sebsequence sum. O(n)

#include <stdio.h>

#define N 10

int main(void)
{
    int A[N] = {-4,8,-10,23,-89,-90,73,-90,-78,176};
    int ThisSum = 0,MinSum = A[0];

    for(int i = 0; i < N; i++)
    {
        ThisSum += A[i];

        if(ThisSum < MinSum)
            MinSum = ThisSum;
        else if(ThisSum > 0)
            ThisSum = 0;
    }

    printf("The minimum sebsequence sum is %d\n",MinSum);

    return 0;
}