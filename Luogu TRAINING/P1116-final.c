#include <stdio.h>
#include <stdlib.h>

//https://www.luogu.com.cn/problem/P1116

int scan(void)
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

int main(void)
{
    int N = 0;
    scanf("%d\n", &N);
    int * list = (int *)malloc(N*sizeof(int));
    for (int i=0;i<N;i++)
    {
        *(list+i) = scan();
    }

    //Using bubble sort ????
    int sum=0, state=1;
    for (int loop=0;loop<N&&state==1;loop++)
    {
        state = 0;
        for (int i=1;i<N;i++)
        {
            if (*(list+i)<*(list+i-1))
            {
                state = 1;
                sum++;
                int tmp = *(list+i);
                *(list+i) = *(list+i-1);
                *(list+i-1) = tmp;
            }
        }
    }
    printf("%d", sum);
    return 0;
}