#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//https://www.luogu.com.cn/problem/P4995

long long scan(void)
{
    char a = getchar();
    while (a>'9'||a<'0')
    {
        a = getchar();
    }
    long long sum = 0;
    while (a<='9'&&a>='0')
    {
        sum = sum*10+a-'0';
        a = getchar();
    }
    return sum;
}

long long * MergeSort(long long *a, long long n)  //归并排序 时间复杂度 O(NlogN)
{
    if (n>1)
    {
        long long * result = (long long *)malloc(n*sizeof(long long)); //用于return数组的临时变量
        //分割数组
        long long *i = a; //0 -> n/2-1 有n/2个
        long long *j = a+n/2; //n/2 -> n-1 有n-n/2个

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
        memcpy(a, result, n*sizeof(long long));
        free(result);
        return a;
    }else
    {
        //memcpy(result, a, n*sizeof(ushort));
        return a;
    }
}
int main(void)
{
    int n = 0;
    scanf("%d\n", &n);
    long long * list = (long long *)malloc((n+1)*sizeof(long long));
    n++;
    *list = 0;
    for (int i=1;i<n;i++)
    {
        *(list+i) = scan();
    }
    list = MergeSort(list, n);
    long long min=0, max=n-1;
    long long sum = 0;
    while (min<max)
    {
        sum += (*(list+max)-*(list+min))*(*(list+max)-*(list+min));
        min++;
        if (min==max)
        {
            break;
        }
        sum += (*(list+max)-*(list+min))*(*(list+max)-*(list+min));
        max--;
        if (min==max)
        {
            break;
        }
    }
    printf("%lld", sum);
    return 0;
}