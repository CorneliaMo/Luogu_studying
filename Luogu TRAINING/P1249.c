#include <stdio.h>

//https://www.luogu.com.cn/problem/P1249
//感觉用递归好不少

#include <string.h>
//约定数组零位储存数组末位索引
int * combine(int *a, int *b)//返回合并a b数组的指针
{
//
    //总字节数 (*(a)+*(b)+2)*sizeof(int)
    //A段字节数 (*(a)+1)*sizeof(int)
    //B段字节数 (*(b)+1)*sizeof(int)
    int tmp[*a+*b+1];
    memcpy(tmp+1, a+1, (*a)*sizeof(int));
    memcpy(tmp+(*a)+1, b+1, (*b)*sizeof(int));
    tmp[0] = *a+*b;
    //free(*a);
    //free(*b);
    return tmp;
}

int *divide(int n) //待拆分的值n 可拆返回数组 不可拆返回数组
//所谓拆分是拆成两个数 并且两个数的乘积大于原数 输出一个最大的结果
{
//
}

int main(void)
{
    /*
    int n = 0;
    scanf("%d", &n);

    for (int i=n-1;)
    int multiple = 0;
    */
    int n[5] = {4, 2, 3, 4, 5};
    int m[7] = {6, 7, 6, 5, 4, 3, 2};
    int *p = combine(n, m);
    for (int i=0;i<=*p;i++)
    {
        printf("%d\n", *(p+i));
    }
    return 0;
}