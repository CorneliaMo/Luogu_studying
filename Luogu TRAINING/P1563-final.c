#include <stdio.h>
 
 //https://www.luogu.com.cn/problem/P1563

int main(void)
{
    typedef struct    //定义结构体
    {
        int orient;             //人物0朝内 1朝外
        char name[20];
    }people;

    int n, m, index = 0;     //人物序号逆时针递增
    scanf("%d %d", &n, &m);
    people List[n-1];           //初始化人物对象数组

    for (int i=0;i<n;i++) //读取人物信息
    {
        scanf("%d %s", &List[i].orient, List[i].name);          //易错点！！！！int变量需提供变量指针/地址（使用&运算符） 而char字符串不需要，其本身就是指针
    }
    for (int i=0;i<m;i++)
    {
        int temp_1, temp_2 = 0; //方向0左1右 个数
        scanf("%d %d", &temp_1, &temp_2);
        //00减 01加 10加 11减
        if (temp_1==List[index].orient)                //判断索引越界
        {
            //减
            index = index - temp_2;
        }else if (temp_1!=List[index].orient){
            //加
            index = index + temp_2;
        }
        if (index<0)
        {
            index = index-(index/n)*n+n;
        }else if (index>=n){
            index = index-(index/n)*n;
        }
    }
    printf("%s", List[index].name);
    return 0;
}