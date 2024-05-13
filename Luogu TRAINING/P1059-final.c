#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//https://www.luogu.com.cn/problem/P1059

unsigned short * MergeSort(unsigned short *a, int n)  //归并排序 时间复杂度 O(NlogN)
{
    if (n>1)
    {
        unsigned short * result = (unsigned short *)malloc(n*sizeof(unsigned short)); //用于return数组的临时变量
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
                break;//退出循环
            }else if(index2==(n-n/2))             //r2数列为空
            {
                for (int loop2=loop;loop2<n;loop2++)
                {
                    *(result+loop2) = *(i+index1);
                    index1++;
                }
                break;//退出循环
            }
        }
        //返回并释放
        memcpy(a, result, n*sizeof(unsigned short));
        free(result);
        return a;
    }else
    {
        return a;
    }
}

unsigned short read(void)//快速输入
{
    char ch = getchar();
    unsigned short res=0;
    while (ch>'9' || ch<'0') { ch = getchar(); }
    while (ch<='9' && ch>='0')
    {
        res = res*10 + ch-'0';
        ch = getchar();
    }
    return res;
}

int main(void)
{
    int n;
    scanf("%d\n", &n);
    unsigned short * list = (unsigned short *)malloc(n*sizeof(unsigned short));
    for (int i=0;i<n;i++)
    {
        *(list+i) = read();
    }
    list = MergeSort(list, n);
    int sum = 1;
    int prev=*list;
    for (int i=1;i<n;i++)
    {
        if (*(list+i)!=prev)
        {
            prev = *(list+i);
            sum++;
        }
    }
    printf("%d\n", sum);
    prev=*list; printf("%d ",prev);
    for (int i=1;i<n;i++)
    {
        if (*(list+i)!=prev)
        {
            prev=*(list+i);
            printf("%d ",prev);
        }
    }
}