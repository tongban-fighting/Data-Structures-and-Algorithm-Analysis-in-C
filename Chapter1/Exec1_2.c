//solve word puzzle problem, use lower words

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define N 80
#define M 10 //number of words in the list

int main(void)
{
    long op,ed;

    //generate the input and print-- two-dimensional array(N*N)
    char pool[N][N];

    printf("   ");
    for(int i = 1; i <= N; i++)
        printf("%2d ",i);
    putchar('\n');
    srand(time(NULL));
    for(int i = 0; i < N; i++)
    {
        printf("%2d  ",i+1);
        for(int j = 0; j < N; j++)
        {
            pool[i][j] = 'a' + rand() % 26;
            printf("%c  ",pool[i][j]);
        }
        putchar('\n');
    }

    //define a list of words
    char list_words[M][N+1]={"review","this","my","basic","formulas","memorize","derive","proof","computer","science"};

    //start solve the word puzzle
    op = clock();

    //row compare left to right
    int start;//word start position
    int match;

    for(int i = 0; i < N; i++)
        for(int k = 2; k <= N; k++) //k is number of characters
            for(int j = 0; j + k - 1 < N; j++)
                for(int m = 0; m < M; m++)
                {
                    match = 1;
                    for(start = 0; start < k; start++)
                        if(pool[i][j+start] != list_words[m][start])
                        {
                            match = 0;
                            break;
                        }
                    if((match == 1)&&(list_words[m][start] == '\0'))
                        printf("Find \"%s\", start from (%d,%d) to (%d,%d).\n",list_words[m],i+1,j+1,i+1,j+k);
                }

    //row compare right to left
    for(int i = 0; i < N; i++)
        for(int k = 2; k <= N; k++)
            for(int j = N - 1; j - k + 1 >= 0; j--)
                for(int m = 0; m < M; m++)
                {
                    match = 1;
                    for(start = 0; start < k; start++)
                        if(pool[i][j-start] != list_words[m][start])
                        {
                            match = 0;
                            break;
                        }
                    if((match == 1)&&(list_words[m][start] == '\0'))
                        printf("Find \"%s\", start from (%d,%d) to (%d,%d).\n",list_words[m],i+1,j+1,i+1,j-k+2);
                }   

    //column compare up to bottom
    for(int j = 0; j < N; j++)
        for(int k = 2; k <= N; k++)
            for(int i = 0; i + k - 1 < N; i++)
                for(int m = 0; m < M; m++)
                {
                    match = 1;
                    for(start = 0; start < k; start++)
                        if(pool[i+start][j] != list_words[m][start])
                        {
                            match = 0;
                            break;
                        }
                    if((match == 1)&&(list_words[m][start] == '\0'))
                        printf("Find \"%s\", start from (%d,%d) to (%d,%d).\n",list_words[m],i+1,j+1,i+k,j+1);
                }             

    //column compare bottom to up
    for(int j = 0; j < N; j++)
        for(int k = 2; k <= N; k++)
            for(int i = N - 1; i - k + 1 >= 0; i--)
                for(int m = 0; m < M; m++)
                {
                    match = 1;
                    for(start = 0; start < k; start++)
                        if(pool[i-start][j] != list_words[m][start])
                        {
                            match = 0;
                            break;
                        }
                    if((match == 1)&&(list_words[m][start] == '\0'))
                        printf("Find \"%s\", start from (%d,%d) to (%d,%d).\n",list_words[m],i+1,j+1,i-k+2,j+1);
                }    

    //orientation up to bottom,left to right
    for(int j = 0; j < N - 1; j++)
        for(int k = 2; k <= N - j; k++)
            for(int i = 0; i <= N-j-k; i++)
                for(int m = 0; m < M; m++)
                {
                    match = 1;
                    for(start = 0; start < k; start++)
                        if(pool[i+start][j+start] != list_words[m][start])
                        {
                            match = 0;
                            break;
                        }
                    if((match == 1)&&(list_words[m][start] == '\0'))
                        printf("Find \"%s\", start from (%d,%d) to (%d,%d).\n",list_words[m],i+1,j+1,i+k,j+k);
                }       

    //reverse of (orientation up to bottom,left to right)
    for(int j = N - 1; j > 0 ; j--)
        for(int k = 2; k <= j + 1; k++)
            for(int i = N - 1; i >= k - 1; i--)
                for(int m = 0; m < M; m++)
                {
                    match = 1;
                    for(start = 0; start < k; start++)
                        if(pool[i-start][j-start] != list_words[m][start])
                        {
                            match = 0;
                            break;
                        }
                    if((match == 1)&&(list_words[m][start] == '\0'))
                        printf("Find \"%s\", start from (%d,%d) to (%d,%d).\n",list_words[m],i+1,j+1,i-k+2,j-k+2);
                }      

    //orientation up to bottom,right to left
    for(int j = N - 1; j > 0 ; j--)
        for(int k = 2; k <= j + 1; k++)
            for(int i = 0; i <= N-k; i++)
                for(int m = 0; m < M; m++)
                {
                    match = 1;
                    for(start = 0; start < k; start++)
                        if(pool[i+start][j-start] != list_words[m][start])
                        {
                            match = 0;
                            break;
                        }
                    if((match == 1)&&(list_words[m][start] == '\0'))
                        printf("Find \"%s\", start from (%d,%d) to (%d,%d).\n",list_words[m],i+1,j+1,i+k,j-k+2);
                }      

    //reverse of (orientation up to bottom,right to left)
    for(int i = N - 1; i > 0; i--)
        for(int k = 2; k <= i + 1; k++)
            for(int j = 0; j <= N-k; j++)
                for(int m = 0; m < M; m++)
                {
                    match = 1;
                    for(start = 0; start < k; start++)
                        if(pool[i-start][j+start] != list_words[m][start])
                        {
                            match = 0;
                            break;
                        }
                    if((match == 1)&&(list_words[m][start] == '\0'))
                        printf("Find \"%s\", start from (%d,%d) to (%d,%d).\n",list_words[m],i+1,j+1,i-k+2,j+k);
                }      

    return 0;
}

