int max(int a, int b)
{
    return (a>=b)*a+(a<b)*b;
}

int min(int a, int b)
{
    return (a>=b)*b+(a<b)*a;
}


#include <stdlib.h>
#include <string.h>
int * bubblesort_high2low(int *p, int a, int b)//提供数组指针p 起始索引a 终止索引b
{
    for (int i=0;i<(b-a);i++) //循环n-1遍
    {
        for (int j=a+1;j<=b;j++)
        {
            if (*(p+j)>*(p+j-1))
            {
                int tmp;
                tmp = *(p+j);
                *(p+j) = *(p+j-1);
                *(p+j-1) = tmp;
            }
        }
    }
}

int * append(int *a, int b, int n)//数组指针a大小为n 向数组后添加b 返回新的数组指针
{
    int * result = (int *)malloc((n+1)*sizeof(int));
    memcpy(result , a, n*sizeof(int));
    free(a);
    *(result+n) = b;
    return result;
}

int * delpos(int *a, int b, int n)//数组指针a大小为n 删除对应索引b 返回新的数组指针
{
    int * result = (int *)malloc((n-1)*sizeof(int));
    memcpy(result, a, b*sizeof(int));
    memcpy(result+b, a+b+1, (n-b-1)*sizeof(int));
    //free(a);
    return result;
}

int * delend(int *a, int n)//数组指针a大小为n 删除末位 返回新的数组指针
{
    int * result = (int *)malloc((n-1)*sizeof(int));
    memcpy(result, a, (n-1)*sizeof(int));
    //free(a);
    return result;
}