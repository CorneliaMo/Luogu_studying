#include <stdio.h>
#include <stdlib.h>

//https://www.luogu.com.cn/problem/P1177

unsigned int * MergeSort(unsigned int *a, int n)  //归并排序 时间复杂度 O(NlogN)
{
    unsigned int * result = (unsigned int *)malloc(n*sizeof(unsigned int)); //用于return数组的临时变量
    if (n>1)
    {
        //分割数组
        unsigned int *i = a; //0 -> n/2-1 有n/2个
        unsigned int *j = a+n/2; //n/2 -> n-1 有n-n/2个

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
        return result;
    }else
    {
        //memcpy(result, a, n*sizeof(int));
        return a;
    }
}

//快排超时 不会选key
//最后还是用归并排序
int main(void)
{
    int N = 0;
    scanf("%d", &N);
    unsigned int * list = (unsigned int *)malloc(N*sizeof(unsigned int));
    for (int i=0;i<N;i++)
    {
        scanf("%d", list+i);
    }
    list = MergeSort(list, N);
    for (int i=0;i<N;i++)
    {
        printf("%d ", *(list+i));
    }
}