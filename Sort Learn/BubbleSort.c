#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * BubbleSort(int *p, int n)//提供数组指针p 起始索引a 终止索引b
{
    for (int i=0;i<n-1;i++) //循环n-1遍
    {
        int state = 0;
        for (int j=0;j<=n;j++)
        {
            if (*(p+j)>*(p+j-1))
            {
                int tmp;
                tmp = *(p+j);
                *(p+j) = *(p+j-1);
                *(p+j-1) = tmp;
                state = 1;
            }
        }
        if (state == 0)
        {
            i = n;
        }
    }
}

int main(void)
{
    FILE * fp;
    fp = fopen("C:\\numbers.txt", "r");
    int n = 0;
    fscanf(fp, "%d", &n);
    printf("Number of data : %d\n\n", n);
    int * list = malloc(n*sizeof(int));

    for (int i=0;i<n;i++)
    {
        fscanf(fp, "%d", list+i);
    }

    clock_t start, finish;
    double Total_time;
    start = clock();

    int *a;
    a = BubbleSort(list, n);

    finish = clock();
    Total_time = (double)((finish - start) / (double)CLOCKS_PER_SEC * 1000);
    printf("Sort %d data using %.0f ms\n", n, Total_time);
    printf("Sort %d data using %.2f MB memory\n", n, n*sizeof(int)/1024.0/1024.0);
    printf("Checking data...\n");
    int i;
    for (i=1;i<n;i++)
    {
        //printf("%d\n", *(a+i));
        if (*(a+i)<*(a+i-1))
        {
            printf("Sort failed\n");
            i = n+1;
        }
    }
    if (i!=n+1)
    {
        printf("Check pass");
    }
    return 0;
}