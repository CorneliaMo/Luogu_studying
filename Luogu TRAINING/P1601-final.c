#include <stdio.h>
#include <math.h>
#include "Marquest.h"

//https://www.luogu.com.cn/problem/P1601
//洛谷的无符号长整型为8字节 win下为4字节 4,294,967,295 使用九位数

int main(void)
{
    unsigned long a[56];
    int len_a[56];
    unsigned long b[56];
    unsigned long result[56];
    int len_b[56];
    char s_a[500];
    char s_b[500];
    for (int i=0;i<56;i++){result[i]=0;a[i]=0;b[i]=0;len_a[i]=9;len_b[i]=9;}

    scanf("%s", &s_a);
    scanf("%s", &s_b);
    //数的长度strlen(s_a) 占用位数strlen(s_a)/9+(strlen(s_a)%9!=0)
    //末位个数(strlen(s_a)%9!=0)*strlen(s_a)%9+(strlen(s_a)%9==0)*9
    int la =  strlen(s_a);
    int lb = strlen(s_b);
    int index_a = la/9+(la%9!=0); 
    int index_b = lb/9+(lb%9!=0);
    len_a[index_a-1] = (la%9!=0)*la%9+(la%9==0)*9;
    len_b[index_b-1] = (lb%9!=0)*lb%9+(lb%9==0)*9;

    for (int i=0;i<index_a;i++)
    {
        //要从后往前读取的位数 len_a[i] 已经读取的位数 i*9 
        //对应字符串索引la-i*9-j-1
        for (int j=0;j<len_a[i];j++) //读取位乘对应倍数 (int)pow(10, j)
        {
            a[i] = a[i]+((int)(s_a[la-i*9-j-1])-48)*(int)pow(10, j);
            //printf("%d a[%d]=%d\n", len_a[i], i, a[i]);
        }
    }

    for (int i=0;i<index_b;i++)
    {
        //要从后往前读取的位数 len_a[i] 已经读取的位数 i*9 
        //对应字符串索引lb-i*9-j-1
        for (int j=0;j<len_b[i];j++) //读取位乘对应倍数 (int)pow(10, j)
        {
            b[i] = b[i]+((int)(s_b[lb-i*9-j-1])-48)*(int)pow(10, j);
            //printf("%d b[%d]=%d\n", len_b[i], i, b[i]);
        }
    }

    int len_result = max(index_a, index_b); //取最长的一位计算
    unsigned long stepin = 0; //进位
    for (int i=0;i<len_result;i++)
    {
        result[i] = a[i]+b[i]+stepin-(stepin+a[i]+b[i])/1000000000*1000000000;
        stepin = (stepin+a[i]+b[i])/1000000000;
    }
    if (stepin!=0)
    {
        len_result++;
        result[len_result] = stepin;
    }
    printf("%d", result[len_result-1]);  //第一节无需补位 输出忽略0
    for (int i=len_result-2;i>=0;i--){printf("%09d", result[i]);} //注意强制输出位数 不要忽略0

    //for (int i=index_a-1;i>=0;i--){printf("%d ", a[i]);}

    return 0;
}