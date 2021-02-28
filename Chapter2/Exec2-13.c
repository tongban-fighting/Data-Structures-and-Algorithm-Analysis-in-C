//Determine if a positive interger is prime

#include <stdio.h>
#include <math.h>
#include <time.h>

int main(void)
{
    long n;
    long sqrtn;
    long op,ed;

    printf("Please input a positive interger: ");
    while(scanf("%lx",&n))
    {
        op = clock();
        long i;
        sqrtn = sqrt(n);

        for(i = 2; i <= sqrtn; i++)
            if(n % i == 0)
            {
                printf("%ld is not prime.\n",n);
                break;
            }
        if(i > sqrtn)
            printf("%ld is prime.\n",n);
        ed = clock();
        printf("running time:%f\n",(double)(ed-op)/CLOCKS_PER_SEC);
        printf("Please input a positive interger(input q to quit): ");
    }

    return 0;
}