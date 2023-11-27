#include <stdio.h>

//https://www.luogu.com.cn/problem/P9868?contestId=145259

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    getchar();
    short words[n][2];  //words[*][0]为最小值 words[*][1]为最大值
    short tmp = 0;
    short max = 0;
    short min = 999;
    for (int i=0;i<n;i++) //一共有n个单词
    {
        words[i][0] = 999;
        words[i][1] = 0; 
        for (int j=0;j<m;j++)//每个单词有m个字母
        {
            tmp = getchar();
            if (tmp<words[i][0])   //比较获取最小值
            {
                words[i][0] = tmp;
            }
            if (tmp>words[i][1])   //比较获取最大值
            {
                words[i][1] = tmp;
            }
        }
        getchar();
    }
    //只要某个单词的最小值都小于其他单词的最大值  则成立  输出1
    //反之  不成立  输出0
    short state = 1;
    for (int i=0;i<n;i++) //一共有n个单词
    {
        state = 1; //重置状态
        for (int j=0;j<i&&state==1;j++)//第i个单词的前面部分
        {
            if (/*第j个的最大值 小于等于 第i个的最小值 则不成立*/words[j][1] <= words[i][0])
            {
                state = 0;
            }
        }
        for (int j=i+1;j<n&&state==1;j++)//第i个单词的后面部分
        {
            if (/*第j个的最大值 小于等于 第i个的最小值 则不成立*/words[j][1] <= words[i][0])
            {
                state = 0;
            }
        }
        printf("%d", state);
    }    
    return 0;
}

/*
4 7
abandon
bananaa
baannaa
notnotn

4 7
aabdnno
aaaabnn
aaaabnn
nnnoott



*/