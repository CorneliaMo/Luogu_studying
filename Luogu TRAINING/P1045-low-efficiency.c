#include <stdio.h>
#include <math.h>

//https://www.luogu.com.cn/problem/P1045

int main(void)
{
    int P = 0;                 //次幂
    int len = 0;               //位数
    short int result[501];     //倒序储存每一位数
    short int putin[501];      //倒序储存进位数
    float tmp = log(10)/log(2); 
    
    scanf("%d", &P);
    float tmp2 = P/tmp;        //指数运算
    
    if ((int)tmp2<tmp2)
    {
        len = (int)tmp2+1;
    }else{
        len = (int)tmp2;       //四舍五入
    }

    printf("%d\n", len);       //输出结果

    for (int i=0;i<500;i++){result[i]=0;putin[i]=0;} //初始化数组
    result[0] = 2;   //最后一位设成2 不然怎么幂运算？

    
    for (int i=0;i<P-1;i++)             //多少次幂就循环多少次，乘多少次2（待优化）
    {   
        for (int k=0;k<500;k++)         //从低向高乘2，并判断进位
        {
            result[k]=result[k]*2;
            result[k]=result[k]+putin[k]; //加上进位
            putin[k]=0;                   //归零进位
            if (result[k]>=10)            //判断是否需要进位
            {
                putin[k+1]=1;             //将下一位设成进1
                result[k] = (int)fmod(result[k], 10.0); //将这一位设置为进位后的数
            }
        }
    }
    result[0] = result[0] - 1;              //2P -1 的 减一

    for (int line=10;line>0;line--)
    {
        for (int col=50;col>0;col--)
        {
            printf("%d", result[(line-1)*50+col-1]);        //按题目要求输出结果
        }
        putchar('\n');  //换行
    }
    
    //for (int i=499;i>=0;i--){printf("%d",*r[i]);}
    return 0;
}