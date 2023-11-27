#include <stdio.h>

//https://www.luogu.com.cn/problem/P1065
//思考：这道题应该用链表？


int main(void)
{
    int m, n = 0;  //其中m(<20)表示机器数   n(<20)表示工件数
    scanf("%d %d", &m, &n);
    int len = m*n;
    int loc = 0;
    int sec[len];
    for (int i=0;i<len;i++){ sec[i]=0; }

    while (loc<len)
    {
        int tmp = getchar();
        if (tmp>=48&&tmp<=57)
        {
            sec[i] = sec[i]*10 + tmp-48;
        }else{
            loc = loc+1;
        }
    }

    int work_sec[len][2];  //每个工序所使用的机器号
    for (int i=0;i<n;i++)
    {
        scanf("%d %d", &work_sec[i][0], &work_sec[i][1]);
    }
    int work_t[len][2];   //每个工序的加工时间
    for (int i=0;i<n;i++)
    {
        scanf("%d %d", &work_t[i][0], &work_t[i][1]);
    }
    
    int workflow[m][400]; //机器工作序列
    for (int i=0;i<len;i++)
    {
        //安排机器号sec[i] 
    }


    

}