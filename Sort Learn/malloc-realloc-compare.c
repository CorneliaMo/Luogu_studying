#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int * m_test(int * a, int n)
{
    int * result = (int *)malloc((n+1)*sizeof(int));
    memcpy(result, a, n*sizeof(int));
    *(result+n) = 0;
    free(a);
    return result;
}

int * a_test(int * a, int n)
{
    int * result = (int *)realloc(a, (n+1)*sizeof(int));
    *(result+n) = 0;
    return result;
}

int main(void)
{
    int * a =(int *)malloc(sizeof(int)); 
    int * b =(int *)malloc(sizeof(int)); 
    clock_t start, finish;
    double Total_time;

    start = clock();
    for (int i=1;i<200000;i++)
    {
        a = m_test(a, i);
    }
    finish = clock();
    Total_time = (double)((finish - start) / (double)CLOCKS_PER_SEC * 1000);
    printf("\nmalloc: %.2fms\n", Total_time);
    free(a);

    start = clock();
    for (int i=1;i<200000;i++)
    {
        b = a_test(b, i);
    }
    finish = clock();
    Total_time = (double)((finish - start) / (double)CLOCKS_PER_SEC * 1000);
    printf("\nrealloc: %.2fms\n", Total_time);
    free(b);
}