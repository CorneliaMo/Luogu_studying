//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

//https://www.luogu.com.cn/problem/P9871?contestId=145259

typedef struct
{
    int start; //起始天数
    int end; //终止天数
    int duration; //持续天数
    int delta;  //净增加能量值
    float ratio; //净增加能量值/持续天数
}challenge;

typedef struct node
{
    int start;
    int end;
    int duration;
};

bool compare(const challenge &a, const challenge &b) //const必须加，不然会错，目前不懂为啥。
{
    return a.ratio>b.ratio;
}

int main(void)
{
    int c, t;//分别表示测试点编号和测试数据组数
    cin >> c >> t;
    for (int loop=0;loop<t;loop++)
    {
        long energy = 0;
        int n, m, k, d;
        //分别表示试运行的天数、挑战的个数、大 Y 单次跑步打卡的连续天数限制以及大 Y 跑步打卡减少的能量值
        cin >> n >> m >> k >> d;
        challenge list[m];
        for (int loop2=0;loop2<m;loop2++)
        {
            int x, y, v;
            //如果在第x天时，用户已经连续跑步打卡至少y天,那么用户的能量值提高v
            cin >> x >> y >> v;
            list[loop2].start = x-y+1;
            list[loop2].end = x;
            list[loop2].duration = y;
            list[loop2].delta = v-y*d;
            list[loop2].ratio = (float)list[loop2].delta / (float)y;
        }
        sort(list, list+m, compare);  //ratio从大到小排序
        

        energy += list[0].delta;
        LINK head = {list[0].start, list[0].end, list[0].duration, NULL}; //链表的初始节点
        for (int i=1;i<m;i++)
        {
            if (list[i].ratio<=0)
            {
                break;
            }
            LINK * p_now = head;
            while (p_now) //搜索到和list[i]有重叠的链节
            {

            }
        }
    }
    return 0;
}