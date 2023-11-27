#include <stdio.h>
#include <math.h>
#include <malloc.h>

//https://www.luogu.com.cn/problem/P1042

void checkResult();
static int *W_21;
static int *L_21;
static int *W_11;
static int *L_11;
static int Num_11;
static int Num_21;

int main(void)
{
    char result = 'E';
    Num_21 = 0;
    Num_11 = 0;
    W_21 = (int *)malloc(sizeof(int) * 8000); 
    L_21 = (int *)malloc(sizeof(int) * 8000); 
    W_11 = (int *)malloc(sizeof(int) * 8000); 
    L_11 = (int *)malloc(sizeof(int) * 8000); 

    while (1)
    {
        result = getchar();
        if (result=='W')
        {
            W_11[Num_11]++;
            W_21[Num_21]++;
            checkResult();
        }else if (result=='L'){
            L_11[Num_11]++;
            L_21[Num_21]++;
            checkResult();
        }else if (result=='E'){
            break;
        }
    }
    for (int i=0;i<=Num_11;i++)
    {
        printf("%d:%d\n",W_11[i], L_11[i]);
    }
    putchar('\n');
    for (int i=0;i<=Num_21;i++)
    {
        printf("%d:%d\n",W_21[i], L_21[i]);
    }
    return 0;
}

void checkResult()
{
    if (((W_11[Num_11]>=11)||(L_11[Num_11]>=11))&abs(W_11[Num_11]-L_11[Num_11])>=2)
    {
        Num_11++;
    }
    if (((W_21[Num_21]>=21)||(L_21[Num_21]>=21))&abs(W_21[Num_21]-L_21[Num_21])>=2)
    {
        Num_21++;
    }
}