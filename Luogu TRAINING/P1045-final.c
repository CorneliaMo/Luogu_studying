#include <stdio.h>
#include <math.h>

//https://www.luogu.com.cn/problem/P1045

int main(void)
{
    int P = 0;                 //次幂
    int len = 0;               //位数
    unsigned long result[56];  //五位数共用一个无符号长整型
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

    for (int i=0;i<56;i++){result[i]=0;}  //初始化

    result[0] = 2; //最后一位设成2 不然怎么幂运算？

    for (int i=0;i<P-1;i++)
    {
        for (int k=0;k<56;k++){
            result[k]=result[k]*2;
            } 
        for (int k=0;k<55;k++)
        {
            result[k+1]=result[k+1]+(result[k]>=1000000000);
            result[k]=result[k]%1000000000;
        }
        result[55]=result[55]%100000;
    }

result[0]--;

/*
for (int row=10;row>0;row--)
{
    for (int col=5;col>0;col--)
    {
        printf("%010d", result[(row-1)*10+col-1]);
    }
    putchar('\n');
}
*/
    printf("%05d%09d%09d%09d%09d%09d\n", result[55], result[54], result[53], result[52], result[51], result[50]);
    printf("%09d%09d%09d%09d%09d%05d\n", result[49], result[48], result[47], result[46], result[45], result[44]/10000);
    printf("%04d%09d%09d%09d%09d%09d%01d\n", result[44]%10000, result[43], result[42], result[41], result[40], result[39], result[38]/100000000);
    printf("%08d%09d%09d%09d%09d%06d\n", result[38]%100000000, result[37], result[36], result[35], result[34], result[33]/1000);
    printf("%03d%09d%09d%09d%09d%09d%02d\n", result[33]%1000, result[32], result[31], result[30], result[29], result[28], result[27]/10000000);
    printf("%07d%09d%09d%09d%09d%07d\n", result[27]%10000000, result[26], result[25], result[24], result[23], result[22]/100);
    printf("%02d%09d%09d%09d%09d%09d%03d\n", result[22]%100, result[21], result[20], result[19], result[18], result[17], result[16]/1000000);
    printf("%06d%09d%09d%09d%09d%08d\n", result[16]%1000000, result[15], result[14], result[13], result[12], result[11]/10);
    printf("%01d%09d%09d%09d%09d%09d%04d\n", result[11]%10, result[10], result[9], result[8], result[7], result[6], result[5]/100000);
    printf("%05d%09d%09d%09d%09d%09d\n", result[5]%100000, result[4], result[3], result[2], result[1], result[0]);
    return 0;
}