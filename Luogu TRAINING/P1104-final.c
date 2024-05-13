#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//https://www.luogu.com.cn/problem/P1104

typedef struct
{
    char name[20];
    int y;
    int m;
    int d;
    int id;
}people;

int days(people *a) //Count days from 1960
{
    int sum = 0;
    for (int i=1960;i<a->y;i++)
    {
        sum += (i%4==0)*366+(i%4!=0)*365;
    }
    for (int i=1;i<a->m;i++)
    {
        sum += (i<=7&&i%2==1)*31+(i<=7&&i%2==0&&i!=2)*30+(i>=8&&i%2==0)*31+(i>=8&&i%2==1)*30+(i==2&&(a->y)%4==0)*29+(i==2&&(a->y)%4!=0)*28;
    }
    sum += a->d;
    return sum;
}

void BubbleSort(people *a, int n)
{
    short state = 1;
    for (int loop=0;loop<=n&&state==1;loop++)
    {
        state = 0;
        for (int i=1;i<n;i++)
        {
            if ((days(a+i)<days(a+i-1))||(days(a+i)==days(a+i-1)&&(a+i)->id>(a+i-1)->id))
            {
                people tmp = *(a+i);
                *(a+i) = *(a+i-1);
                *(a+i-1) = tmp;
                state = 1;
            }
        }
    }
}

int main(void)
{
    int n = 0;
    scanf("%d\n", &n);
    people * list = (people *)malloc(n*sizeof(people));
    for (int i=0;i<n;i++)
    {
        scanf("%s %d %d %d", &((list+i)->name), &((list+i)->y), &((list+i)->m), &((list+i)->d));
        (list+i)->id = i;
    }
    BubbleSort(list, n);
    for (int i=0;i<n;i++)
    {
        printf("%s\n", (list+i)->name);
    }
    return 0;
}