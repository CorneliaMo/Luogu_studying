#include <stdio.h>

//https://www.luogu.com.cn/problem/P1067

int main(void)
{
    int len;
    short num_c[100][4];
    short num[100];
    scanf("%d\n", &len);

    char tmp;
    for (int i=0;i<100;i++){num_c[i][0]=-1;num_c[i][1]=0;num_c[i][2]=0;num_c[i][3]=0;}

    for (int i=0;i<=len;i++)
    {
        for (int j=0;j<5;j++)
        {
            tmp = getchar();
            //printf("%c", tmp);
            if (tmp=='-')
            {
                num_c[i][0] = 1;
            }else if ((tmp>=48)&&(tmp<=57)){
                num_c[i][1] = num_c[i][2];
                num_c[i][2] = num_c[i][3];
                num_c[i][3] = (int)tmp-48;
            }else if ((tmp==' ') || (tmp=='\n')){
                j = 4;
            }
        }
    }

    for (int i=0;i<=len;i++)
    {
        num[i] = (num_c[i][0]*(-1))*(num_c[i][1]*100+num_c[i][2]*10+num_c[i][3]);
        //printf("%d", num[i]);
        if (len==0){
            printf("%d", num[0]);
        }else if ((i!=len)&(i!=len-1)&(num[i]>1)&(i!=0)){
            printf("+%dx^%d", num[i], len-i);
        }else if ((i!=len)&(i!=len-1)&(num[i]<-1)&(i!=0)){
            printf("%dx^%d", num[i], len-i);
        }else if ((i!=len)&(i!=len-1)&(num[i]==1)&(i!=0)){
            printf("+x^%d", len-i);
        }else if ((num[i]==1)&(i!=len-1)&(i==0)&(i!=len)){
            printf("x^%d", len-i);
        }else if ((i!=len)&(i!=len-1)&(num[i]==-1)){
            printf("-x^%d", len-i);
        }else if (i==0){
            printf("%dx^%d", num[i], len-i);
        }else if ((i==len)&(i!=len-1)&(num[i]>0)){
            printf("+%d", num[i]);
        }else if ((i==len)&(i!=len-1)&(num[i]<0)){
            printf("%d", num[i]);
        }else if ((i==len-1)&(num[i]<-1)){
            printf("%dx", num[i]);
        }else if ((i==len-1)&(num[i]>1)){
            printf("+%dx", num[i]);
        }else if ((i==len-1)&(num[i]==1)){
            printf("+x");
        }else if ((i==len-1)&(num[i]==-1)){
            printf("-x");
        }
    }
    return 0;
}