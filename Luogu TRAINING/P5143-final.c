#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//https://www.luogu.com.cn/problem/P5143

typedef struct
{
    int x;
    int y;
    int z;
}point;

int scan(void)//快速输入
{
    char a = getchar();
    while (a>'9'||a<'0')
    {
        a = getchar();
    }
    int sum = 0;
    while (a<='9'&&a>='0')
    {
       sum = sum*10+a-'0';
       a = getchar(); 
    }
    return sum;
}

point * MergeSort(point *a, int n)  //归并排序 时间复杂度 O(NlogN)
{
    if (n>1)
    {
        point * result = (point *)malloc(n*sizeof(point)); //用于return数组的临时变量
        //分割数组
        point *i = a; //0 -> n/2-1 有n/2个
        point *j = a+n/2; //n/2 -> n-1 有n-n/2个

        i = MergeSort(i, n/2);
        j = MergeSort(j, n-n/2);
        
        //归并数组
        int index1=0; int index2=0;
        for (int loop=0;loop<n;loop++)  //循环归并
        {
            if (index1<(n/2)&&index2<(n-n/2))        //判断数列为空
            {
                if ((i+index1)->z>=(j+index2)->z)
                {
                    *(result+loop) = *(j+index2);
                    index2++;
                }else if((i+index1)->z<(j+index2)->z)
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
        memcpy(a, result, n*sizeof(point));
        free(result);
        return a;
    }else
    {
        //memcpy(result, a, n*sizeof(point));
        return a;
    }
}

int main(void)
{
    int N = 0;
    scanf("%d\n", &N);
    point * list = (point *)malloc(N*sizeof(point));
    for (int i=0;i<N;i++)
    {
        (list+i)->x = scan();
        (list+i)->y = scan();
        (list+i)->z = scan();
    }
    list = MergeSort(list, N);
    double sum = 0.0;
    for (int i=1;i<N;i++)
    {
        sum += sqrt( ((list+i)->x-(list+i-1)->x)*((list+i)->x-(list+i-1)->x) + ((list+i)->y-(list+i-1)->y)*((list+i)->y-(list+i-1)->y) + ((list+i)->z-(list+i-1)->z)*((list+i)->z-(list+i-1)->z));
    }
    /*
    for (int i=0;i<N;i++)
    {
        printf("%d %d %d\n", (list+i)->x, (list+i)->y, (list+i)->z);
    }
    */
    printf("%.3f", sum);
    return 0;
}