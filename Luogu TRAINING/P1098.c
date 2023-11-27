#include <stdio.h>
#include <string.h>

//https://www.luogu.com.cn/problem/P1098

int main(void)
{
    int P1, P2, P3 = 0;
    char data[100];
    scanf("%d %d %d\n", &P1, &P2, &P3);
    gets(&data);
    int len = strlen(data);
    int loc = 0;

    int check_type()
    while (loc <= len-1)
    {
        if (((data[loc+1]!='-')&(data[loc]!='-')|(data[loc+1]=='-')))
        {
            printf("%c", data[loc]);
            loc++;
        }else if (data[loc+1]=='-'){
            int start = (int)data[loc];
            int stop = (int)data[loc+2];
            if (P3==1)
            {
                printf("%c", data[loc]);
                for (int i=start+1;i<stop;i++)
                {
                    for (int j=0;j<P2;j++)
                    {
                        if (P1 == 1) //保持原样输出
                        {
                            printf("%c", (char)i);
                        }else if ((P1 == 2)&start>=97){ //小写转大写
                            printf("%c", (char)(i-32));
                        }else if ((P1 == 2)&start<97){  //维持数字原样输出
                            printf("%c", (char)i);
                        }
                    }
                }
                printf("%c", data[loc+2]);
            }else if (P3==2){
                printf("%c", data[loc]);
                for (int i=stop-1;i>start;i--)
                {
                    for (int j=0;j<P2;j++)
                    {
                        if (P1 == 1) //保持原样输出
                        {
                            printf("%c", (char)i);
                        }else if ((P1 == 2)&start>=97){ //小写转大写
                            printf("%c", (char)(i-32));
                        }else if ((P1 == 2)&start<97){  //维持数字原样输出
                            printf("%c", (char)i);
                        }
                    }
                }
                printf("%c", data[loc+2]);
            }
            loc = loc + 3;
        }else if (data[loc]=='-'){
            //printf("???");
            int start = (int)data[loc-1];
            int stop = (int)data[loc+1];
            if (P3==1)
            {
                //printf("%c", data[loc]);
                for (int i=start+1;i<stop;i++)
                {
                    for (int j=0;j<P2;j++)
                    {
                        if (P1 == 1) //保持原样输出
                        {
                            printf("%c", (char)i);
                        }else if ((P1 == 2)&start>=97){ //小写转大写
                            printf("%c", (char)(i-32));
                        }else if ((P1 == 2)&start<97){  //维持数字原样输出
                            printf("%c", (char)i);
                        }
                    }
                }
                printf("%c", data[loc+1]);
            }else if (P3==2){
                //printf("%c", data[loc]);
                for (int i=stop-1;i>start;i--)
                {
                    for (int j=0;j<P2;j++)
                    {
                        if (P1 == 1) //保持原样输出
                        {
                            printf("%c", (char)i);
                        }else if ((P1 == 2)&start>=97){ //小写转大写
                            printf("%c", (char)(i-32));
                        }else if ((P1 == 2)&start<97){  //维持数字原样输出
                            printf("%c", (char)i);
                        }
                    }
                }
                printf("%c", data[loc+1]);
            }
            loc = loc + 2;
        }
    }
    return 0;
}