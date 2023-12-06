#include <stdio.h>
#include <stdlib.h>

//https://www.luogu.com.cn/problem/P9836?contestId=141594

int factor(int a, int n);

int main(void)
{
    /*
    //Initialtive & Input
    int n, w;
    scanf("%d %d", &n, &w);
    int *p = (int *)calloc(n, sizeof(int));
    for (int i=0;i<n;i++)
    {
        scanf("%d", p+i);
    }

    //calculating
    */
   printf("%d", factor(1, 10));

}

int factor(int a, int n)//从a开始搜索n的因数， 有则return 1
{
    if (a >= n)
    {
        return (a==n)*1;
    }
    for (int i=a;i<=n;i++)
    {
        if (n%i==0)
        {
            return 1+factor(i+1, n);
        }
    }
    return 0;
}