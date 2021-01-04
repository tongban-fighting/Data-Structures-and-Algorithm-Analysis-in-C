//Determine kth largest in N numbers, 2nd solution

#include <stdio.h>
#include <time.h>
#define N 100000
#define k 40000

void insert(double * arr, int n, double temp);

int main(void)
{
    double arr[k],temp;
    int i = 0;
    long op,ed;

    //Start time
    op = clock();

    //read k numbers from file "Chapter1_1_NkProblem_input"
    FILE * fp;
    fp = fopen("Chapter1_1_NkProblem_input","r");
    while(i < k && (fscanf(fp,"%lf",&temp) == 1))
        arr[i++] = temp;
    
    //bubble sort for the first k numbers
    for(int i = 0; i < k - 1; i++)
        for(int j = 0; j < k - 1 - i; j++)
            if(arr[j] < arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
    
    //processing every numbers after first k numbers(k-N)
    while(fscanf(fp,"%lf",&temp) == 1)
        if(temp > arr[k-1])
            insert(arr,k,temp);

    //End time
    ed = clock();

    //show the result
    printf("The %dth largest number is %f\n",k,arr[k-1]);
    printf("Processing time is %fs\n",(double)(ed-op)/CLOCKS_PER_SEC);

    fclose(fp);
    return 0;
}

//first search the position to insert, then insert the temp number
void insert(double * arr, int n, double temp)
{
    int lo = 0, hi = n, target, mid;

    //binary search
    mid = (lo + hi) / 2;
    while(lo < hi)
    {
        if(arr[mid] > temp)
            lo = mid + 1;
        else
            hi = mid;
        mid = (lo + hi) / 2;
    }
    
    //insert temp into hi position
    for(int i = n - 1; i > hi; i--)
        arr[i] = arr[i - 1];
    arr[hi] = temp;
}