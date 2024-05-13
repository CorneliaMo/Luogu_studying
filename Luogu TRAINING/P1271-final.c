#include <stdio.h>
#include <stdlib.h>

//https://www.luogu.com.cn/problem/P1271

unsigned short * MergeSort(unsigned short *a, int n)  //归并排序 时间复杂度 O(NlogN)
{
    unsigned short * result = (unsigned short *)malloc(n*sizeof(unsigned short)); //用于return数组的临时变量
    if (n>1)
    {
        //分割数组
        unsigned short *i = a; //0 -> n/2-1 有n/2个
        unsigned short *j = a+n/2; //n/2 -> n-1 有n-n/2个

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

int main(void)
{
    int n, m; //n名候选人 m张选票
    scanf("%d %d", &n, &m);
    unsigned short * list = (int *)malloc(m*sizeof(unsigned short));
    for (int i=0;i<m;i++)
    {
        scanf("%d", list+i);
    }
    list = MergeSort(list, m);
    for (int i=0;i<m;i++)
    {
        printf("%d ", *(list+i));
    }
    return 0;
}