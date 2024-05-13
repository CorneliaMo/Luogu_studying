#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//https://www.luogu.com.cn/problem/T379829?contestId=149175

//2 : 1
//3 : 7
//4 : 4
//5 : 2, 3, 5
//6 : 0, 6, 9
//7 : 8
//9->0 2->3
//进位1->2 7->8
char * scan(void)
{
    char a = getchar();
    while (a>'9'||a<'0')
    {
        a = getchar();
    }
    char * sum = (char *)malloc(11*sizeof(char));
    int i=0;
    while (a<='9'&&a>='0')
    {
        if (i>=10)
        {
            realloc(sum, (i+2)*sizeof(char));
        }
        *(sum+i) = a;
        a = getchar();
        i++;
    }
    *(sum+i) = '\0';
    return sum;
}

long long scani(void)
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

int len(char * a)
{
    int r = 0;
    while (*(a+r)!='\0')
    {
        r++;
    }
    return r;
}
int main(void)
{
    /*
    char * a = scan();
    char * b = scan();
    int l_a = len(a);
    int l_b = len(b);
    */
    long long a, b;
    a = scani();
    b = scani();
    if (b-a>=10)
    {
        putchar('2');
    }else if(b==a)
    {
        putchar('1');
    }else{
        if (((a%10)<=2&&(a%10+b-a)>=3)||((a%10)<=9&&(a%10+b-a)>=10))
        {
            putchar('2');
        }else{
            putchar('1');
        }
    }
    return 0;
}