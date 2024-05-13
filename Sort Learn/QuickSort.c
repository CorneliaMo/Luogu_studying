#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Marquest.h"
#include <time.h>

int * QuickSort(int *a, int n) //快速排序 平均时间复杂度：O(N*logN)
//从大小为n的数组指针a中取key，分块，递归排序4
//全部数列使用malloc新建占用堆内存 应对大数据量
{
    if (n>1)
    {
        //取key值  采用中间值
        int key = *(a+n/2);
        int * left = (int *)malloc(sizeof(int));
        int * right = (int *)malloc(sizeof(int));
        int * process = (int *)malloc((n-1)*sizeof(int));
        
        //从待处理数列中删去key
        memcpy(process, a, n/2*sizeof(int));
        memcpy(process+n/2, a+n/2+1, (n-n/2-1)*sizeof(int));
        int len_l = 0; int len_r = 0;

        //左右分块
        for (int i=0;i<n-1;i++)
        {
            //待分类数据 *(process+i)
            if (*(process+i)>key)
            {
                right = append(right, *(process+i), len_r);//向右堆添加值
                //append后原堆空间会被free
                len_r++;
            }else{
                left = append(left, *(process+i), len_l);//向左堆添加值
                //append后原堆空间会被free
                len_l++;
            }
        }
        //递归排序
        if(len_l>1)
        {
            left = QuickSort(left, len_l);
        }
        if(len_r>1)
        {
            right = QuickSort(right, len_r);
        }
        //合并两堆
        int * result = (int *)malloc(n*sizeof(int));
        memcpy(result, left, len_l*sizeof(int));
        *(result+len_l) = key;
        memcpy(result+len_l+1, right, len_r*sizeof(int));
        //释放堆内存
        free(left);
        free(right);
        free(process);
        //返回数组指针
        return result;
    }else{
        return a;
    }
}



int main(void)
{
    FILE * fp;
    fp = fopen("E:\\C learning\\numbers.txt", "r");
    int n = 0;
    fscanf(fp, "%d", &n);
    printf("Number of data : %d\n\n", n);
    int * list = (int *)malloc(n*sizeof(int));

    for (int i=0;i<n;i++)
    {
        fscanf(fp, "%d", list+i);
    }

    clock_t start, finish;
    double Total_time;
    start = clock();

    int *a;
    a = QuickSort(list, n);

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
