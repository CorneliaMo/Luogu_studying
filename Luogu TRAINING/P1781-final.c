#include <stdio.h>
#include <stdlib.h>

//https://www.luogu.com.cn/problem/P1781

typedef struct
{
    char ticket[100];
    short id;
}people;

int len(char a[])
{
    int sum = 0;
    while (a[sum]!='\0')
    {
        sum++;
    }
    return sum;
}

int compare(char a[], char b[])
{
    int n = len(a);
    for (int i=0;i<n;i++)
    {
        if (a[i]<b[i])
        {
            //printf("%s < %s\n", a, b);
            return 1;
        }else if(a[i]>b[i])
        {
            //printf("%s > %s\n", a, b);
            return 0;
        }
    }
    return 0;
}

int cmp(char a[], char b[])
{
    if (len(a)<len(b))
    {
        //printf("%s < %s\n", a, b);
        return 1;
    }else if(len(a)>len(b))
    {
        //printf("%s > %s\n", a, b);
        return 0;
    }else{
        return compare(a, b);
    }
}

int main(void)//由大到小
{
    short n = 0;
    scanf("%d\n", &n);
    people * list = (people *)malloc(n*sizeof(people));
    for (int i=0;i<n;i++)
    {
        scanf("%s", (list+i)->ticket);
        (list+i)->id = i+1;
    }

    for (int loop=0;loop<=n;loop++)
    {
        for (int i=1;i<n;i++)
        {
            if (cmp((list+i-1)->ticket, (list+i)->ticket))
            {
                people tmp = *(list+i);
                *(list+i) = *(list+i-1);
                *(list+i-1) = tmp;
            }
        }
    }
    printf("%d\n%s", list->id, list->ticket);
    return 0;
}