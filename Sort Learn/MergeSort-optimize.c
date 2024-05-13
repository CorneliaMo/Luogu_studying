#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int * MergeSort(int *a, int n)  //归并排序 时间复杂度 O(NlogN)
{
    if (n>1)
    {
        int * result = (int *)malloc(n*sizeof(int)); //用于return数组的临时变量
        //分割数组
        int *i = a; //0 -> n/2-1 有n/2个
        int *j = a+n/2; //n/2 -> n-1 有n-n/2个

        i = MergeSort(i, n/2);
        j = MergeSort(j, n-n/2);
        
        //归并数组
        int index1=0; int index2=0;
        for (int loop=0;loop<n;loop++)  //循环归并
        {
            if (index1<(n/2)&&index2<(n-n/2))        //判断数列为空
            {
                if (*(i+index1)>=*(j+index2))
                {
                    *(result+loop) = *(j+index2);
                    index2++;
                }else if(*(i+index1)<*(j+index2))
                {
                    *(result+loop) = *(i+index1);
                    index1++;
                }
            }else if(index1==n/2)             //r1数列为空
            {
                for (int loop2=loop;loop2<n;loop2++)
                {
                    *(result+loop2) = *(j+index2);
                    index2++;
                }
                loop = n;//退出循环
            }else if(index2==(n-n/2))             //r2数列为空
            {
                for (int loop2=loop;loop2<n;loop2++)
                {
                    *(result+loop2) = *(i+index1);
                    index1++;
                }
                loop = n;//退出循环
            }
        }
        //返回并释放
        memcpy(a, result, n*sizeof(unsigned int));
        free(result);
        return a;
    }else
    {
        //memcpy(result, a, n*sizeof(int));
        return a;
    }
}

int main(void)
{
    putchar('\n');
    clock_t start, finish;
    double Total_time;
    FILE * fp;
    fp = fopen("C:\\numbers.txt", "r");
    int n = 0;
    fscanf(fp, "%d", &n);
    printf("Number of data : %d\n\nReading...\n", n);
    int * list = (int *)malloc(n*sizeof(int));

    start = clock();
    for (int i=0;i<n;i++)
    {
        fscanf(fp, "%d", list+i);
    }
    finish = clock();
    Total_time = (double)((finish - start) / (double)CLOCKS_PER_SEC * 1000);
    printf("Read %d data using %.0f ms\n\n", n, Total_time);

    printf("Sorting...\n");
    start = clock();
    int *a;
    a = MergeSort(list, n);
    finish = clock();
    Total_time = (double)((finish - start) / (double)CLOCKS_PER_SEC * 1000);
    printf("Sort %d data using %.0f ms\n", n, Total_time);
    printf("Sort %d data using %.2f MB memory\n\n", n, n*sizeof(int)/1024.0/1024.0);
    
    printf("Checking data...\n");
    int i;
    start = clock();
    for (i=1;i<n;i++)
    {
        //printf("%d\n", *(a+i));
        if (*(a+i)<*(a+i-1))
        {
            printf("Sort failed\n");
            i = n+1;
        }
    }
    finish = clock();
    Total_time = (double)((finish - start) / (double)CLOCKS_PER_SEC * 1000);
    if (i!=n+1)
    {
        printf("Check pass\n");
    }
    printf("Check %d data using %.0f ms\n", n, Total_time);
    return 0;
}

/*
int main(void)
{
    int list[10] = {4, 87, 546, 45, 12, 5, 89, 57, 135, 68759};
    int *a;
    a = list;
    a = MergeSort(a, 10);
    for (int i=0;i<10;i++)
    {
        printf("%d\n", *(a+i));
    }
}
*/
