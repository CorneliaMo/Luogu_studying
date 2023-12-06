#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//https://www.luogu.com.cn/problem/P1249

//数学基础：n/2最近的整数才能取得最大乘积
//只有n>=5时，拆分的乘积大于原数
//只有大于等于10的偶数才能拆成不重复的几位
//拆分a (n%2==0&&n<10)*(n/2-1)+(n%2==0&&n>=10)*n/2+(n%2!=0)*(n-1)/2
//拆分b (n%2==0&&n<10)*(n/2+1)+(n%2==0&&n>=10)*n/2+(n%2!=0)*(n+1)/2
int * devide(int n)
{
    int * result;
    if (n<5)
    {
        result = (int *)calloc(2, sizeof(int));
        *(result) = 1;
        *(result+1) = n;
    }
    else
    {
        int * tmp1 = devide((n%2==0&&n<10)*(n/2-1)+(n%2==0&&n>=10)*n/2+(n%2!=0)*(n-1)/2);
        int * tmp2 = devide((n%2==0&&n<10)*(n/2+1)+(n%2==0&&n>=10)*n/2+(n%2!=0)*(n+1)/2);
        result = (int *)calloc(*tmp1+*tmp2+1, sizeof(int));
        *(result) = *tmp1+*tmp2;
        memcpy(result+1, tmp1+1, *tmp1*sizeof(int));
        memcpy(result+*tmp1+1, tmp2+1, *tmp2*sizeof(int));
        free(tmp1);
        free(tmp2);
    }
    return result;
}

int * MergeSort(int *a, int n)  //归并排序 时间复杂度 O(NlogN)
{
    int * result = (int *)malloc(n*sizeof(int)); //用于return数组的临时变量
    if (n>1)
    {
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
        return result;
    }else
    {
        //memcpy(result, a, n*sizeof(int));
        return a;
    }
}

int main(void)
{
    //Input, calculate and sort
    int n = 0;
    scanf("%d", &n);
    int *p = devide(n);
    memcpy(p+1, MergeSort(p+1, *p), *p*sizeof(int));

    //combine

    int mult = 1;
    for (int i=1;i<=*p;i++)
    {
        printf("%d ",*(p+i));
        mult *= *(p+i);
    }
    printf("\n%d", mult);
    return 0;
}