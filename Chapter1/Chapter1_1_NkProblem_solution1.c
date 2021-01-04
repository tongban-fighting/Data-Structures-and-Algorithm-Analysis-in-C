//Determine kth largest in N numbers

#include <stdio.h>
#include <time.h>
#define N 100000
#define k 40000

int main(void)
{
    double arr[N],temp;
    int i = 0;
    long op,ed;

    //Start time
    op = clock();

    //read N numbers from file "Chapter1_1_NkProblem_input"
    FILE * fp;
    fp = fopen("Chapter1_1_NkProblem_input","r");
    while((fscanf(fp,"%lf",&temp) == 1) && i < N)
        arr[i++] = temp;
    
    //bubble sort
    for(int i = 0; i < N - 1; i++)
        for(int j = 0; j < N - 1 - i; j++)
            if(arr[j] < arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
    
    //End time
    ed = clock();

    //show the result
    printf("The %dth largest number is %f\n",k,arr[k-1]);
    printf("Processing time is %fs\n",(double)(ed-op)/CLOCKS_PER_SEC);

    fclose(fp);
    return 0;
}