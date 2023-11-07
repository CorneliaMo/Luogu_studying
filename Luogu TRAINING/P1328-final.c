#include <stdio.h>

//https://www.luogu.com.cn/problem/P1328

int min(int a, int b)
{
    if (a>b){return b;}else{return a;}
}

int main(void)
{
    
    int N, a, b = 0 ;
    scanf("%d %d %d", &N, &a, &b);
    //printf("%d %d %d", N, a, b);
    int A_cycle[200];
    int B_cycle[200];
    int A_score[201];
    int B_score[201];

    int form[5][5];    //查表确定胜负 form[甲][乙] 结果为甲对乙
    for (int i=0;i<5;i++){for (int j=0;j<5;j++){form[i][j]=0;}}
    form[0][2]=1;form[0][3]=1;form[1][3]=1;form[2][4]=1;form[3][4]=1;form[1][0]=1;form[2][1]=1;form[3][2]=1;form[4][0]=1;form[4][1]=1;
    getchar();                            //逐行输入A，B的周期
    for (int i=0;i<a-1;i++)
    {
        A_cycle[i] = ((int)getchar())-48;
        getchar();
        //printf("%d ", A_cycle[i]);
    }
    A_cycle[a-1] = ((int)getchar())-48;
    //printf("%d ", A_cycle[a-1]);
    getchar();
    for (int i=0;i<b-1;i++)
    {
        B_cycle[i] = ((int)getchar())-48;
        getchar();
        //printf("%d ", B_cycle[i]);
    }
    B_cycle[b-1] = ((int)getchar())-48;
    //printf("%d ", B_cycle[b-1]);
    //for (int i=0;i<a;i++){printf("%d ", A_cycle[i]);}
   
    int len = min(a*b, N);
    //printf("%d", len);
    A_score[0]=0;
    B_score[0]=0;
    for (int i=1;i<=len;i++)    //计算最小公倍数orN次内的结果
    {                           //score数组左移一位
        A_score[i] = form[A_cycle[(i-1)%a]][B_cycle[(i-1)%b]]+A_score[i-1];
        //printf("%d ", form[A_cycle[(i-1)%a]][B_cycle[(i-1)%b]]);
        B_score[i] = form[B_cycle[(i-1)%b]][A_cycle[(i-1)%a]]+B_score[i-1];
        //printf("%d %d\n", A_score[i], B_score[i]);
        //printf("%d %d ,", (i-1)%a, (i-1)%b);
    }

    if (len<N)
    {
        printf("%d %d", A_score[len]*(N/len)+A_score[N%len], B_score[len]*(N/len)+B_score[N%len]);
    }else{
        printf("%d %d", A_score[N], B_score[N]);
    }

    return 0;
}