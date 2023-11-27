#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

//https://www.luogu.com.cn/problem/P9869?contestId=145259

int deep_search(int a, int n, int * x); //深度搜索直至闭环

int main(void)
{
    int c, t; //分别表示测试点编号和测试数据组数
    scanf("%d %d", &c, &t);
    for (int loop=0;loop<t;loop++) //多组数据
    {
        int n, m; //分别表示变量个数和语句条数
        scanf("%d %d", &n, &m); getchar();//  SKIP\n
        int x[n+1];
        memset(x, 0, sizeof(x)); //将变量值赋值为0 后面再赋值为序号
        //for (int i=1;i<=n;i++){ x[i] = 0; } //将变量值赋值为序号
        char command = ' ';
        int a, b;
        for (int i=0;i<m;i++)
        {
            //command可能为T(84) F(70) U(85) +(43) -(45)
            command = getchar(); getchar();
            switch (command)
            {
            case 84: //T 整数a 表示 x[a] <- T
                scanf("%d", &a);getchar();
                x[a] = 84+n;  //避免混淆变量序号和赋值
                break;
            case 70: //F 整数a 表示 x[a] <- F
                scanf("%d", &a);getchar();
                x[a] = 70+n;  //避免混淆变量序号和赋值
                break;
            case 85: //U 整数a 表示 x[a] <- U
                scanf("%d", &a);getchar();
                x[a] = 85+n;  //避免混淆变量序号和赋值
                break;
            case 43: //+ 整数a 整数b 表示 x[a] <- x[b]
                scanf("%d %d", &a, &b);getchar();
                if (x[b]==0){ x[b] = b; }
                x[a] = x[b];
                break;
            case 45: //- 整数a 整数b 表示 x[a] <- ¬x[b]
                scanf("%d %d", &a, &b);getchar();
                if (x[b]==0){ x[b] = b; }
                x[a] = -x[b];
                break;
            }
        }
        int sum = 0;
        for (int i=1;i<=n;i++)
        {
            //详见P9869.png
            if (abs(x[i])<=n&&abs(x[i])>0)
            {
            sum += deep_search(x[i], n, &x[0]);
            }else if(abs(x[i])==85+n)
            {
                sum++;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}

int deep_search(int a, int n, int * x) //深度搜索直至闭环 冲突返回1 否则0
{
    int state[n+1];
    memset(state, 0, sizeof(state)); //状态归零
    int index = a;
    int now = 0;
    while (1)
    {
        now = abs(index); //现在要查询的索引
        state[now] = index;       //标记要查询的索引
        int next = abs(*(x+now));
        if (next<=n&&next>0) //要查询的索引指向下一个值
        {
            //当前为正值则指引下一个值 当前为负值则指引下一个值取反
            index = *(x+now)*(index/now);
            if (state[next]!=0) //下一个要查询的索引已经查询过
            {
                break;
            } //下一个要查询的索引没有查询过则继续标记
        }else //终止于字符abs(*(x+now))
        {
            if (next==85+n)//判断字符
            {
                return 1;
            }else
            {
                return 0;
            }
        }
    }
    //执行到这里则是闭环
    if (-index==state[now]) //冲突
    {
        return 1;
    }else//不冲突
    {
        return 0;
    }
}