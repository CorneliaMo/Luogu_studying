#include <stdio.h>
#include <stdlib.h>

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
       *(sum+i) = a;
       a = getchar();
       i++;
    }
    *(sum+i) = '\0';
    return sum;
}

int cmp(char *a, char *b) //大的排前面
{
    for (int i=0;i<11;i++)
    {
        if (*(b+i)=='\0')
        {
            if (*(a+i)<*a)
            {
                return 1;
            }else
            {
                return 0;
            }
        }else if (*(a+i)=='\0')
        {
            if (*b<*(b+i))
            {
                return 1;
            }else
            {
                return 0;
            }
        }else if (*(a+i)<*(b+i))
        {
            return 1;
        }else if (*(a+i)>*(b+i))
        {
            return 0;
        }
    }
    return 0;
}

void BubbleSort(char** a, int n)
{
    short state = 1;
    for (int loop=0;loop<n&&state==1;loop++)
    {
        state = 0;
        for (int i=1;i<n;i++)
        {
            if (cmp(*(a+i-1), *(a+i)))
            {
                char * tmp = *(a+i-1);
                *(a+i-1) = *(a+i);
                *(a+i) = tmp;
                state = 1;
            }
        }
    }
}

int main(void)
{
    int n = 0;
    scanf("%d\n", &n);
    char** list = (char **)malloc(n*sizeof(char**));
    for (int i=0;i<n;i++)
    {
        *(list+i) = scan();
    }
    BubbleSort(list, n);
    for (int i=0;i<n;i++)
    {
        int index = 0;
        while (*(*(list+i)+index)!='\0')
        {
            putchar(*(*(list+i)+index));
            index++;
        }
    }
}