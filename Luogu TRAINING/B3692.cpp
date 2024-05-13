#include <iostream>
#include <string>
using namespace std;

//https://www.luogu.com.cn/problem/B3692

typedef struct
{
    string name;
    int score; //通过题数
    int 
}team;

bool cmp(const team& a, const team& b)  //对结构体中score排序
{
    return a->score > b->score;
}

int find_index
int main(void)
{
    int n, m, k; //n,m,K，依次为该场 ICPC 试题数、该场 ICPC 队伍数、该场 ICPC 提交记录数
    cin >> n >> m >> k;
    //输入并储存结果，分为封榜前/后
    //队伍索引为队伍哈希值

    //排序封榜前
    //倒序遍历排行榜



}