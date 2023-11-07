#include <stdio.h>

//https://www.luogu.com.cn/problem/P1601

int main(void)
{
    char a[18] = {'0'};
    char b[18] = {'0'};
    char final[36];
    int len_a, len_b;
    len_a = 0;
    len_b = 0;
    char tmp = ' ';

    while (1)
    {
        tmp = getchar();
        //putchar(tmp);
        if (tmp=='\n')
        {
            break;
        }else{
            a[len_a] = tmp;
            len_a++;
            //printf("%dplus\n", len_a);
        }
    }

    tmp = ' ';

    while (1)
    {
        tmp = getchar();
        if (tmp=='\n')
        {
            break;
        }else{
            b[len_b] = tmp;
            len_b++;
        }
    }
    //printf("%d", len_a);

    char final_a[len_a-1];
    char final_b[len_b-1];

    //将数字逆序
    for (int i=0;i<len_a;i++)
    {
        final_a[i] = a[len_a-i-1];
    }
    for (int i=0;i<len_b;i++)
    {
        final_b[i] = b[len_b-i-1];
    }
 
    //printf("%s", final_a);
    //printf("%s", final_b);
 
    short int sum, plus = 0; 
    int i = 0;
    while (1)
    {
        printf("%d %c %d %c\n", ((int)final_a[i])-48, final_a[i], ((int)final_b[i])-48, final_b[i]);
        
        if ( (final_a[i]!='0'||final_b[i]!='0') & (48<=(int)(final_a[i])<=57) & (48<=(int)(final_b[i])<=57) )
        {
            sum = ((int)final_a[i])-48 + ((int)final_b[i])-48 + plus;
            if (sum>=10)
            {
                plus = 1;
                sum = sum-10;
            }
            final[i] = (char)(sum+48);
            i++;
        }else{printf("fuck");break;}
    }
    for (;i>=0;i--)
    {
        putchar(final[i]);
    }

    return 0;
}