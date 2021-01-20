//find the minimum positive sebsequence sum.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 10

void quickSort(int arr[],int index[],int lo,int hi);//rank[lo,hi)
int partition(int arr[],int index[],int lo,int hi);
void swap(int arr[],int index[],int a,int b);

int main(void)
{
    int A[N] = {4,-8,-10,23,9,-90,73,-90,8,176};

    int Sumi[N];//sum of first index i
    Sumi[0] = A[0];
    for(int i = 1; i < N; i++)
        Sumi[i] = Sumi[i-1] + A[i];

    int index[N];//record the position of Sumi
    for(int i = 0; i < N; i++)
        index[i] = i;

    //sort the Sumi together with index
    quickSort(Sumi,index,0,N);
/*
    //test
    for(int i = 0; i < N; i++)
        printf("%d ",Sumi[i]);
    putchar('\n');
*/
    //check the positive minimum result
    int minSum = Sumi[0];
    int thisSum;

    if(minSum < 0)
        minSum = INT_MAX;

    for(int i = 1; i < N; i++)
    {
        thisSum = Sumi[i] - Sumi[i-1];
        if((index[i]-index[i-1]) > 0 && thisSum > 0 && thisSum < minSum)
            minSum = thisSum;
        if(Sumi[i] > 0 && Sumi[i] < minSum)
            minSum = Sumi[i];
    }

    if(minSum != INT_MAX)
        printf("minimum positive subsequence sum is %d\n",minSum);
    else
        printf("No minimum positive subsequence sum.\n");
    
    return 0;
}

void quickSort(int arr[],int index[],int lo,int hi)
{
    if(hi - lo < 2) 
        return;
    int mi = partition(arr,index,lo,hi);

    quickSort(arr,index,lo,mi);
    quickSort(arr,index,mi+1,hi);
}

int partition(int arr[],int index[],int lo,int hi)//LUG
{
    swap(arr,index,lo,lo+rand()%(hi-lo));
    hi--;
    int pivot = arr[lo];
    int pivot_index = index[lo];

    while(lo < hi)
    {
        while(lo < hi && pivot <= arr[hi])
            hi--;
        arr[lo] = arr[hi];
        index[lo] = index[hi];
        while(lo < hi && pivot >= arr[lo])
            lo++;
        arr[hi] = arr[lo];
        index[hi] = index[lo];
    }
    arr[lo] = pivot;
    index[lo] = pivot_index;

    return lo;
}

void swap(int arr[],int index[],int a,int b)
{
    int arr_temp,index_temp;

    arr_temp = arr[a];
    arr[a] = arr[b];
    arr[b] = arr_temp;

    index_temp = index[a];
    index[a] = index[b];
    index[b] = index_temp;
}