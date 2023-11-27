#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int * MergeSort(int *a, int n)  //归并排序 时间复杂度 O(NlogN)
{
    int * result; //用于return数组的临时变量
    if (n>1)
    {
        //分割数组
        int *i = malloc(n/2*sizeof(int)); 
        int *j = malloc((n-n/2)*sizeof(int));
        memcpy(i, a, (n/2)*sizeof(int));
        memcpy(j, a+n/2, (n-n/2)*sizeof(int));

        int *tmp1 = MergeSort(i, n/2);
        int *tmp2 = MergeSort(j, n-n/2);
        memcpy(i, tmp1, n/2*sizeof(int));
        memcpy(j, tmp2, (n-n/2)*sizeof(int));
        free(tmp1);
        free(tmp2);
        
        //归并数组
        int *r = malloc(n*sizeof(int));
        int index1=0; int index2=0;
        for (int loop=0;loop<n;loop++)  //循环归并
        {
            if (index1<(n/2)&&index2<(n-n/2))        //判断数列为空
            {
                if (*(i+index1)>=*(j+index2))
                {
                    *(r+loop) = *(j+index2);
                    index2++;
                }else if(*(i+index1)<*(j+index2))
                {
                    *(r+loop) = *(i+index1);
                    index1++;
                }
            }else if(index1==n/2)             //r1数列为空
            {
                for (int loop2=loop;loop2<n;loop2++)
                {
                    *(r+loop2) = *(j+index2);
                    index2++;
                }
                loop = n;//退出循环
            }else if(index2==(n-n/2))             //r2数列为空
            {
                for (int loop2=loop;loop2<n;loop2++)
                {
                    *(r+loop2) = *(i+index1);
                    index1++;
                }
                loop = n;//退出循环
            }
        }
        //返回并释放
        result = (int *)malloc(n*sizeof(int));
        memcpy(result, r, n*sizeof(int));
        free(r);
        free(i);
        free(j);
        return result;
    }else
    {
        result = (int *)malloc(n*sizeof(int));
        memcpy(result, a, n*sizeof(int));
        return result;
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
    int * list = malloc(n*sizeof(int));

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
