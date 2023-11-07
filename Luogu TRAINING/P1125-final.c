#include <stdio.h>

//https://www.luogu.com.cn/problem/P1125

int main(void)
{
    char word[100];
    int times[26];
    scanf("%s", &word);
    for (int i=0;i<26;i++){times[i]=0;}

    for (int i=0;i<strlen(word);i++)
    {
        times[(int)word[i]-97]++;
    }

    int max_index, min_index = 0;
    for (int i=1;i<26;i++){
        if (times[max_index]<times[i]) { max_index = i; }
        if ((times[min_index]>times[i])&(times[i]!=0)) { min_index = i; }
        if ((times[min_index]==0)&(times[i]!=0)) { min_index = i; }
    }
    //printf("%d %d", times[max_index], times[min_index]);

    int n = times[max_index] - times[min_index];
    if(n>1){
        int state=1;
        while (state)
        {
            for (int i=2;i<n;i++)
            {
                if (n%i==0)
                {
                    printf("No Answer\n0");
                    state=0;
                    break;
                }
            }
            if (state==1){printf("Lucky Word\n%d", n);state=0;}
        }
    }else{
        printf("No Answer\n0");
    }
    return 0;
}