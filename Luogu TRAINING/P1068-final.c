#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//https://www.luogu.com.cn/problem/P1068

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

typedef struct
{
    unsigned short score;
    unsigned short id;
}people;

people * MergeSort(people *a, int n)  //归并排序 时间复杂度 O(NlogN)
{
    if (n>1)
    {
        people * result = (people *)malloc(n*sizeof(people)); //用于return数组的临时变量
        //分割数组
        people *i = a; //0 -> n/2-1 有n/2个
        people *j = a+n/2; //n/2 -> n-1 有n-n/2个

        i = MergeSort(i, n/2);
        j = MergeSort(j, n-n/2);
        
        //归并数组
        int index1=0; int index2=0;
        for (int loop=0;loop<n;loop++)  //循环归并
        {
            if (index1<(n/2)&&index2<(n-n/2))        //判断数列为空
            {
                if ((i+index1)->score<(j+index2)->score)
                {
                    *(result+loop) = *(j+index2);
                    index2++;
                }else if((i+index1)->score>(j+index2)->score)
                {
                    *(result+loop) = *(i+index1);
                    index1++;
                }else if ((i+index1)->score==(j+index2)->score)
                {
                    if ((i+index1)->id>(j+index2)->id)
                    {
                        *(result+loop) = *(j+index2);
                        index2++;
                    }else{
                        *(result+loop) = *(i+index1);
                        index1++;
                    }
                }
            }else if(index1==n/2)             //r1数列为空
            {
                for (int loop2=loop;loop2<n;loop2++)
                {
                    *(result+loop2) = *(j+index2);
                    index2++;
                }
                loop = n;//退出循环
            }else if(index2==(n-n/2))             //r2数列为空
            {
                for (int loop2=loop;loop2<n;loop2++)
                {
                    *(result+loop2) = *(i+index1);
                    index1++;
                }
                loop = n;//退出循环
            }
        }
        //返回并释放
        memcpy(a, result, n*sizeof(people));
        free(result);
        return a;
    }else
    {
        //memcpy(result, a, n*sizeof(people));
        return a;
    }
}

int main(void)
{
    int n=0, m=0;
    scanf("%d %d", &n, &m);
    people * list = (people *)malloc(n*sizeof(people));
    for (int i=0;i<n;i++)
    {
        (list+i)->id = scan();
        (list+i)->score = scan();
    }
    list = MergeSort(list, n);
    int line = (list+((int)(m*1.5)) -1*((int)(m*1.5)>(m*1.5))-1)->score;
    int sum=0;
    while ((list+sum)->score>=line)
    {
        sum++;
    }
    printf("%d %d\n", line, sum);
    sum = 0;
    while ((list+sum)->score>=line)
    {
        printf("%d %d\n", (list+sum)->id, (list+sum)->score);
        sum++;
    }
    return 0;
}