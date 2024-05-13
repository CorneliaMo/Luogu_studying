#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//https://www.luogu.com.cn/problem/P1093

typedef struct
{
    unsigned short chi;
    unsigned short math;
    unsigned short eng;
    unsigned short sum;
    unsigned short id; 
}student;

student * MergeSort(student *a, int n)  //归并排序 时间复杂度 O(NlogN)
{
    if (n>1)
    {
        student * result = (student *)malloc(n*sizeof(student)); //用于return数组的临时变量
        //分割数组
        student *i = a; //0 -> n/2-1 有n/2个
        student *j = a+n/2; //n/2 -> n-1 有n-n/2个

        i = MergeSort(i, n/2);
        j = MergeSort(j, n-n/2);
        
        //归并数组
        int index1=0; int index2=0;
        for (int loop=0;loop<n;loop++)  //循环归并
        {
            if (index1<(n/2)&&index2<(n-n/2))        //判断数列为空
            {
                if ((i+index1)->sum<=(j+index2)->sum)
                {
                    *(result+loop) = *(j+index2);
                    index2++;
                }else if((i+index1)->sum>(j+index2)->sum)
                {
                    *(result+loop) = *(i+index1);
                    index1++;
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
        memcpy(a, result, n*sizeof(student));
        free(result);
        return a;
    }else
    {
        //memcpy(result, a, n*sizeof(student));
        return a;
    }
}

void check(student * a, int n)
{
    short state = 1;
    for (int i=0;i<n/*&&state==1*/;i++)
    {
        for (int j=1;j<n;j++)
        {
            state = 0;
            if ( ((a+j)->sum)==((a+j-1)->sum) && ( ((a+j)->chi)>((a+j-1)->chi) || ( ((a+j)->chi)==((a+j-1)->chi)&&((a+j)->id)<((a+j-1)->id) ) ) )//同总分的：语文分高在先，若语文与总分同分，学号在前的先
            {
                //printf("switch %d %d %d and %d %d %d\n", (a+j)->id, (a+j)->chi, (a+j)->sum, (a+j-1)->id, (a+j-1)->chi, (a+j-1)->sum);
                student tmp = *(a+j);
                *(a+j) = *(a+j-1);
                *(a+j-1) = tmp;
                state = 1;
            }
        }
    }
}

int in_num(void)
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
    unsigned short n = 0;
    scanf("%d\n", &n);
    student * list = (student *)malloc(n*sizeof(student));
    for (unsigned short i=0;i<n;i++)
    {
        (list+i)->chi = in_num();
        (list+i)->math = in_num();
        (list+i)->eng = in_num();
        (list+i)->id = i+1;
        (list+i)->sum = (list+i)->chi + (list+i)->math + (list+i)->eng;
    }
    list = MergeSort(list, n);
    check(list, n);
    //putchar('\n');
    for (unsigned short i=0;i<5;i++)
    {
        printf("%d %d\n",(list+i)->id, (list+i)->sum);
    }
    return 0;
}