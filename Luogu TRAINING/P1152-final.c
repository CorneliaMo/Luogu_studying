#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//https://www.luogu.com.cn/problem/P1152

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
    int n = 0;
    scanf("%d", &n);
    int * list = (int *)malloc((n-1)*sizeof(int));
    int prev=0, now=0;
    scanf("%d", &now);
    for (int i=0;i<n-1;i++)
    {
        prev = now;
        scanf("%d", &now);
        *(list+i) = fabs(now-prev);
    }
    list = MergeSort(list, n-1);
    for (int i=1;i<n;i++)
    {
        if (*(list+i-1)!=i)
        {
            printf("Not jolly");
            return 0;
        }
    }
    printf("Jolly");
    return 0;
}