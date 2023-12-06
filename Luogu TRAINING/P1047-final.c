#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//https://www.luogu.com.cn/problem/P1047

clock_t start, finish;
double Total_time;

int main(void)
{
    //Init
    int l, m;
    scanf("%d %d", &l, &m);
    char * tree = (char *)malloc(l+1);
    memset(tree, '1', l+1);
    int u, v;
    u = 0;v = 1;
    /*Input clocking*/                                  start = clock();
    for(int i=0;i<m;i++)//27002ms
    {
        scanf("%d %d", &u, &v); //45906ms
        //memset(tree+u, '0', v-u+1); //0ms
    }
                                                        finish = clock();Total_time = (double)((finish - start) / (double)CLOCKS_PER_SEC * 1000);printf("\nInput and process used %.2f ms\n", Total_time);

            
    /*Sum clocking*/                                    start = clock();
    int sum = 0;
    for (int i=0;i<=l;i++)
    {
        sum += (*(tree+i)=='1');
    }
                                                        finish = clock();Total_time = (double)((finish - start) / (double)CLOCKS_PER_SEC * 1000);printf("\nSum up used %.2f ms\n", Total_time);
    //OUTPUT
    printf("\n%d", sum);
    return 0;
}