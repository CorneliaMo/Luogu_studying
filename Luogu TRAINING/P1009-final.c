#include <stdio.h>

//https://www.luogu.com.cn/problem/P1009

void plus_in(unsigned long *p, int n, int a) //高精度数组指针p 要进位的索引n 进位数a
{
    unsigned long tmp = (*(p+n)+a)/1000000000; //临时储存进位数
    *(p+n) = *(p+n)+a - tmp*1000000000;
    
    if ((tmp*1000000000)>0) //判断是否连续进位
    {
        plus_in(p, n+1, tmp);  //递归进位
    }
}

void factorial(unsigned long *p, int n) //高精度数组指针p 阶乘数n
{
    for (int i=1;i<=n;i++)
    {
        unsigned long tmp[30]; //临时储存进位数
        for (int j=0;j<30;j++)
        {
            tmp[j] = *(p+j)*i/1000000000; 
            *(p+j) = *(p+j)*i - tmp[j]*1000000000;
        }
        for (int j=0;j<30;j++)
        {
            if (tmp[j]>0)
            {
                plus_in(p, j+1, tmp[j]);
            }
        }
    }
}

void pluser(unsigned long *p, unsigned long *a)//高精度数组指针p 高精度数组指针a 将a加到p上 清空a
{
    for (int i=0;i<30;i++)
    {
        int tmp = (*(p+i)+*(a+i))/1000000000; //临时储存进位数
        *(p+i) = *(p+i)+*(a+i) - tmp*1000000000;
        if ((tmp*1000000000)>0) //判断是否进位
        {
            plus_in(p, i+1, tmp);  //进位
        }
        *(a+i) = 0; //清空a
    }
}

int main(void)
{
    unsigned long fac[30];
    unsigned long result[30];
    for (int i=0;i<30;i++){ fac[i]=0; result[i]=0; }

    int n=0;
    scanf("%d", &n);
    for (int i=1;i<=n;i++)
    {
        fac[0] = 1; //零怎么乘.......
        factorial(fac, i); //算出i!
        pluser(result, fac); //将i!加入结果
    }

    int index=29;
    int state = 1;
    while (state)
    {
        for (int i=index;i>=0;i--)
        {
            if (result[i]!=0)
            {
                index = i;
                state = 0;
                break;
            }
        }
    }
    printf("%d", result[index]);
    for (int i=index-1;i>=0;i--){ printf("%09d", result[i]); }
    
    return 0;
}